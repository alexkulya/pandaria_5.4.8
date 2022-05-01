/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "WorldSession.h"

enum Spells
{
    SPELL_TRESPASSER_A                      = 54028,
    SPELL_TRESPASSER_H                      = 54029,

    SPELL_SUNREAVER_DISGUISE_FEMALE         = 70973,
    SPELL_SUNREAVER_DISGUISE_MALE           = 70974,
    SPELL_SILVER_COVENANT_DISGUISE_FEMALE   = 70971,
    SPELL_SILVER_COVENANT_DISGUISE_MALE     = 70972,

    SPELL_MANABONKED                        = 61839,
    SPELL_TELEPORT_VISUAL                   = 51347,
    SPELL_IMPROVED_BLINK                    = 61995,

    EVENT_SELECT_TARGET                     = 1,
    EVENT_LAUGH_1                           = 2,
    EVENT_WANDER                            = 3,
    EVENT_PAUSE                             = 4,
    EVENT_CAST                              = 5,
    EVENT_LAUGH_2                           = 6,
    EVENT_BLINK                             = 7,
    EVENT_DESPAWN                           = 8,

    MAIL_MINIGOB_ENTRY                      = 264,
    MAIL_DELIVER_DELAY_MIN                  = 5 * MINUTE,
    MAIL_DELIVER_DELAY_MAX                  = 15 * MINUTE,

    NPC_APPLEBOUGH_A                        = 29547,
    NPC_SWEETBERRY_H                        = 29715,

    ZONE_DALARAN                            = 4395
};

/*******************************************************
 * npc_mageguard_dalaran
 *******************************************************/

struct npc_mageguard_dalaran : public ScriptedAI
{
    npc_mageguard_dalaran(Creature* creature) : ScriptedAI(creature)
    {
        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_NORMAL, true);
        creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
    }

    void Reset() override { }

    void EnterCombat(Unit* /*who*/) override { }

    void AttackStart(Unit* /*who*/) override { }

    void MoveInLineOfSight(Unit* who) override

    {
        if (!who || !who->IsInWorld() || who->GetZoneId() != 4395)
            return;

        if (!me->IsWithinDist(who, 65.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!player || player->IsGameMaster() || player->IsBeingTeleported() ||
            player->HasAura(SPELL_SUNREAVER_DISGUISE_FEMALE) || player->HasAura(SPELL_SUNREAVER_DISGUISE_MALE) ||
            player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_FEMALE) || player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_MALE))
            return;

        switch (me->GetEntry())
        {
            case 29254:
                if (player->GetTeam() == HORDE)
                {
                    if (GetClosestCreatureWithEntry(me, NPC_APPLEBOUGH_A, 32.0f))
                    {
                        if (me->isInBackInMap(who, 12.0f))
                            DoCast(who, SPELL_TRESPASSER_A);
                    }
                    else
                        DoCast(who, SPELL_TRESPASSER_A);
                }
                break;
            case 29255:
                if (player->GetTeam() == ALLIANCE)
                {
                    if (GetClosestCreatureWithEntry(me, NPC_SWEETBERRY_H, 32.0f))
                    {
                        if (me->isInBackInMap(who, 12.0f))
                            DoCast(who, SPELL_TRESPASSER_H);
                    }
                    else
                        DoCast(who, SPELL_TRESPASSER_H);
                }
                break;
        }

        me->SetOrientation(me->GetHomePosition().GetOrientation());
        return;
    }

    void UpdateAI(uint32 /*diff*/) override { }
};

/*******************************************************
 * npc_minigob_manabonk
 *******************************************************/

struct npc_minigob_manabonk : public ScriptedAI
{
    npc_minigob_manabonk(Creature* creature) : ScriptedAI(creature)
    {
        me->setActive(true);
    }

    void Reset()
    {
        playerGuid = ObjectGuid();
        me->SetVisible(false);
        events.ScheduleEvent(EVENT_SELECT_TARGET, 1 * IN_MILLISECONDS);
    }

    void GetPlayersInDalaran(std::vector<Player*>& playerList) const
    {
        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            if (Player* player = itr->GetSource()->ToPlayer())
                if (player->GetZoneId() == ZONE_DALARAN && !player->IsFlying() && !player->IsMounted() && !player->IsGameMaster())
                    playerList.push_back(player);
    }

    static Player* SelectTargetInDalaran(std::vector<Player*>& PlayerInDalaranList)
    {
        if (PlayerInDalaranList.empty())
            return nullptr;

        return Trinity::Containers::SelectRandomContainerElement(PlayerInDalaranList);
    }

    void SendMailToPlayer(Player* player) const
    {
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        int16 deliverDelay = irand(MAIL_DELIVER_DELAY_MIN, MAIL_DELIVER_DELAY_MAX);
        MailDraft(MAIL_MINIGOB_ENTRY, true).SendMailTo(trans, MailReceiver(player), MailSender(MAIL_CREATURE, me->GetEntry()), MAIL_CHECK_MASK_NONE, deliverDelay);
        CharacterDatabase.CommitTransaction(trans);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            Position pos;

            switch (eventId)
            {
                case EVENT_SELECT_TARGET:
                {
                    std::vector<Player*> PlayerInDalaranList;
                    GetPlayersInDalaran(PlayerInDalaranList);

                    if (PlayerInDalaranList.empty() || urand(1, 100) > PlayerInDalaranList.size())
                        me->AddObjectToRemoveList();

                    me->SetVisible(true);
                    DoCastSelf(SPELL_TELEPORT_VISUAL);

                    if (Player* player = SelectTargetInDalaran(PlayerInDalaranList))
                    {
                        playerGuid = player->GetGUID();
                        Position pos = player->GetPosition();
                        float dist = frand(10.0f, 30.0f);
                        float angle = frand(0.0f, 1.0f) * M_PI * 2.0f;
                        player->MovePositionToFirstCollision(pos, dist, angle);
                        me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
                    }
                    events.ScheduleEvent(EVENT_LAUGH_1, 2 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_LAUGH_1:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH_NO_SHEATHE);
                    events.ScheduleEvent(EVENT_WANDER, 3 * IN_MILLISECONDS);
                    break;
                case EVENT_WANDER:
                    me->GetMotionMaster()->MoveRandom(8);
                    events.ScheduleEvent(EVENT_PAUSE, 1 * MINUTE);
                    break;
                case EVENT_PAUSE:
                    me->GetMotionMaster()->MoveIdle();
                    events.ScheduleEvent(EVENT_CAST, 2 * IN_MILLISECONDS);
                    break;
                case EVENT_CAST:
                    if (Player* player = me->GetMap()->GetPlayer(playerGuid))
                    {
                        DoCast(player, SPELL_MANABONKED);
                        SendMailToPlayer(player);
                    }
                    else
                        me->AddObjectToRemoveList();

                    events.ScheduleEvent(EVENT_LAUGH_2, 8 * IN_MILLISECONDS);
                    break;
                case EVENT_LAUGH_2:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH_NO_SHEATHE);
                    events.ScheduleEvent(EVENT_BLINK, 3 * IN_MILLISECONDS);
                    break;
                case EVENT_BLINK:
                    DoCastSelf(SPELL_IMPROVED_BLINK);
                    events.ScheduleEvent(EVENT_DESPAWN, 4 * IN_MILLISECONDS);
                    break;
                case EVENT_DESPAWN:
                    me->AddObjectToRemoveList();
                    break;
                default:
                    break;
            }
        }
    }

private:
    ObjectGuid playerGuid;
    EventMap events;
};

enum ArchmageLandalockQuests
{
    QUEST_SARTHARION_MUST_DIE               = 24579,
    QUEST_ANUBREKHAN_MUST_DIE               = 24580,
    QUEST_NOTH_THE_PLAGUEBINGER_MUST_DIE    = 24581,
    QUEST_INSTRUCTOR_RAZUVIOUS_MUST_DIE     = 24582,
    QUEST_PATCHWERK_MUST_DIE                = 24583,
    QUEST_MALYGOS_MUST_DIE                  = 24584,
    QUEST_FLAME_LEVIATHAN_MUST_DIE          = 24585,
    QUEST_RAZORSCALE_MUST_DIE               = 24586,
    QUEST_IGNIS_THE_FURNACE_MASTER_MUST_DIE = 24587,
    QUEST_XT_002_DECONSTRUCTOR_MUST_DIE     = 24588,
    QUEST_LORD_JARAXXUS_MUST_DIE            = 24589,
    QUEST_LORD_MARROWGAR_MUST_DIE           = 24590
};

enum ArchmageLandalockImages
{
    NPC_SARTHARION_IMAGE                    = 37849,
    NPC_ANUBREKHAN_IMAGE                    = 37850,
    NPC_NOTH_THE_PLAGUEBINGER_IMAGE         = 37851,
    NPC_INSTRUCTOR_RAZUVIOUS_IMAGE          = 37853,
    NPC_PATCHWERK_IMAGE                     = 37854,
    NPC_MALYGOS_IMAGE                       = 37855,
    NPC_FLAME_LEVIATHAN_IMAGE               = 37856,
    NPC_RAZORSCALE_IMAGE                    = 37858,
    NPC_IGNIS_THE_FURNACE_MASTER_IMAGE      = 37859,
    NPC_XT_002_DECONSTRUCTOR_IMAGE          = 37861,
    NPC_LORD_JARAXXUS_IMAGE                 = 37862,
    NPC_LORD_MARROWGAR_IMAGE                = 37864
};

struct npc_archmage_landalock : public ScriptedAI
{
    npc_archmage_landalock(Creature* creature) : ScriptedAI(creature)
    {
        _switchImageTimer = MINUTE * IN_MILLISECONDS;
        _summonGUID = 0;
    }

    uint32 GetImageEntry(uint32 QuestId)
    {
        switch (QuestId)
        {
            case QUEST_SARTHARION_MUST_DIE:
                return NPC_SARTHARION_IMAGE;
            case QUEST_ANUBREKHAN_MUST_DIE:
                return NPC_ANUBREKHAN_IMAGE;
            case QUEST_NOTH_THE_PLAGUEBINGER_MUST_DIE:
                return NPC_NOTH_THE_PLAGUEBINGER_IMAGE;
            case QUEST_INSTRUCTOR_RAZUVIOUS_MUST_DIE:
                return NPC_INSTRUCTOR_RAZUVIOUS_IMAGE;
            case QUEST_PATCHWERK_MUST_DIE:
                return NPC_PATCHWERK_IMAGE;
            case QUEST_MALYGOS_MUST_DIE:
                return NPC_MALYGOS_IMAGE;
            case QUEST_FLAME_LEVIATHAN_MUST_DIE:
                return NPC_FLAME_LEVIATHAN_IMAGE;
            case QUEST_RAZORSCALE_MUST_DIE:
                return NPC_RAZORSCALE_IMAGE;
            case QUEST_IGNIS_THE_FURNACE_MASTER_MUST_DIE:
                return NPC_IGNIS_THE_FURNACE_MASTER_IMAGE;
            case QUEST_XT_002_DECONSTRUCTOR_MUST_DIE:
                return NPC_XT_002_DECONSTRUCTOR_IMAGE;
            case QUEST_LORD_JARAXXUS_MUST_DIE:
                return NPC_LORD_JARAXXUS_IMAGE;
            default: //case QUEST_LORD_MARROWGAR_MUST_DIE:
                return NPC_LORD_MARROWGAR_IMAGE;
        }
    }

    void JustSummoned(Creature* image) override
    {
        if (image->GetEntry() != NPC_ANUBREKHAN_IMAGE)
        {
            image->GetMotionMaster()->MoveRotate(20000, ROTATE_DIRECTION_RIGHT); /// ???
        }

        image->m_Events.AddLambdaEventAtOffset([image]()
        {
            image->CastSpell(image, 59123);
        }, 500);

        _summonGUID = image->GetGUID();
    }

    void UpdateAI(uint32 diff) override
    {
        ScriptedAI::UpdateAI(diff);

        _switchImageTimer += diff;

        if (_switchImageTimer > MINUTE*IN_MILLISECONDS)
        {
            _switchImageTimer = 0;
            QuestRelationBounds objectQR = sObjectMgr->GetCreatureQuestRelationBounds(me->GetEntry());

            for (QuestRelations::const_iterator i = objectQR.first; i != objectQR.second; ++i)
            {
                uint32 questId = i->second;
                Quest const* quest = sObjectMgr->GetQuestTemplate(questId);

                if (!quest || !quest->IsWeekly())
                    continue;

                uint32 newEntry = GetImageEntry(questId);

                if (GUID_ENPART(_summonGUID) != newEntry)
                {
                    if (Creature* image = ObjectAccessor::GetCreature(*me, _summonGUID))
                        image->DespawnOrUnsummon();

                    float z = 653.622f;

                    if (newEntry == NPC_MALYGOS_IMAGE || newEntry == NPC_RAZORSCALE_IMAGE || newEntry == NPC_SARTHARION_IMAGE)
                        z += 3.0f;

                    me->SummonCreature(newEntry, 5703.077f, 583.9757f, z, 3.926991f);
                }
            }
        }
    }

private:
    uint32 _switchImageTimer;
    uint64 _summonGUID;
};

void AddSC_dalaran()
{
    new creature_script<npc_mageguard_dalaran>("npc_mageguard_dalaran");
    new creature_script<npc_minigob_manabonk>("npc_minigob_manabonk");
    new creature_script<npc_archmage_landalock>("npc_archmage_landalock");
}
