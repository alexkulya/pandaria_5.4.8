#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum TirisfalGlades
{
    NPC_ARADNE                              = 50372,
    NPC_RISEN_RECRUIT                       = 50414,
    NPC_DEATHKNELL_GRAVE_TARGET             = 50373,
    NPC_MINDLESS_ZOMBIE                     = 1501,

    SPELL_RAISE_UNDEAD                      = 93446,
    SPELL_SUMMON_RISEN_DEAD                 = 93447,
    SPELL_DIRT_EXPLOSION                    = 89199,
    SPELL_CHURNING_DIRT                     = 92788,
    SPELL_ENRAGE                            = 44427,
    SPELL_RISEN_DEAD_TRANSFORM              = 93460,

    ARADNE_MOVEMENT_POINT_01                = 4,
    ARADNE_MOVEMENT_POINT_02                = 12,
    ARADNE_MOVEMENT_POINT_03                = 15,
    ARADNE_MOVEMENT_POINT_04                = 20,
    ARADNE_MOVEMENT_POINT_05                = 26,
    ARADNE_MOVEMENT_POINT_06                = 31,
    ARADNE_MOVEMENT_POINT_07                = 33,
    ARADNE_MOVEMENT_POINT_08                = 37,

    ARADNE_PHASE_00                         = 0,
    ARADNE_PHASE_01                         = 1,
    ARADNE_PHASE_02                         = 2,
    ARADNE_PHASE_03                         = 3,
    ARADNE_PHASE_04                         = 4,

    GRAVE_TARGET_PHASE_00                   = 0,
    GRAVE_TARGET_PHASE_01                   = 1,
    GRAVE_TARGET_PHASE_02                   = 2,
    GRAVE_TARGET_PHASE_03                   = 3,
    GRAVE_TARGET_PHASE_04                   = 4,

    RISEN_DEAD_PHASE_00                     = 0,
    RISEN_DEAD_PHASE_01                     = 1,
    RISEN_DEAD_PHASE_02                     = 2,
    RISEN_DEAD_PHASE_03                     = 3,
    RISEN_DEAD_PHASE_04                     = 4,

    ARADNE_TEXT_01                          = 0,

    RISEN_DEAD_TEXT_01                      = 0,
    RISEN_DEAD_TEXT_02                      = 1,
    RISEN_DEAD_TEXT_03                      = 2,
    RISEN_DEAD_TEXT_04                      = 3,
    RISEN_DEAD_TEXT_05                      = 4,
    RISEN_DEAD_TEXT_06                      = 5,
    RISEN_DEAD_TEXT_07                      = 6,
    RISEN_DEAD_TEXT_08                      = 7,
    RISEN_DEAD_TEXT_09                      = 8,
    RISEN_DEAD_TEXT_10                      = 9,
    RISEN_DEAD_TEXT_11                      = 10,

    RISEN_DEAD_PATH_01                      = 50374*100,
    RISEN_DEAD_PATH_02                      = 50374*100+01,

    RISEN_DEAD_VISUAL_EQUIP_WEAPON_01       = 10614,
    RISEN_DEAD_VISUAL_EQUIP_WEAPON_02       = 1984,

    UNDERTAKER_MORDO_PHASE_00               = 0,
    UNDERTAKER_MORDO_PHASE_01               = 1,
    UNDERTAKER_MORDO_PHASE_02               = 2,
    UNDERTAKER_MORDO_PHASE_03               = 3,
    UNDERTAKER_MORDO_PHASE_04               = 4,
    UNDERTAKER_MORDO_PHASE_05               = 5,
    UNDERTAKER_MORDO_PHASE_06               = 6,
    UNDERTAKER_MORDO_PHASE_07               = 7,
    UNDERTAKER_MORDO_PHASE_08               = 8,
    UNDERTAKER_MORDO_PHASE_09               = 9,

    UNDERTAKER_MORDO_TEXT_01                = 0,
    UNDERTAKER_MORDO_TEXT_02                = 1,

    RISEN_RECRUIT_TEXT_01                   = 0,

    RISEN_RECRUIT_PATH_01                   = 50414*100,
    RISEN_RECRUIT_PATH_02                   = 50414*100+1,

    MINDLESS_ZOMBIE_ATTACK_EVENT_STEP_01    = 1,
    MINDLESS_ZOMBIE_ATTACK_EVENT_STEP_02    = 2
};

struct npc_aradne : public ScriptedAI
{
    npc_aradne(Creature *c) : ScriptedAI(c) { }

    uint32 m_timer;
    uint32 m_phase;

    void Reset() override
    {
        m_timer = 0;
        m_phase = TirisfalGlades::ARADNE_PHASE_00;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == MovementGeneratorType::WAYPOINT_MOTION_TYPE)
        {
            switch (id)
            {
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_01:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_02:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_03:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_04:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_05:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_06:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_07:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
                case TirisfalGlades::ARADNE_MOVEMENT_POINT_08:
                    m_phase = TirisfalGlades::ARADNE_PHASE_01;
                    m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
                    break;
            }
        }
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_timer <= diff)
        {
            m_timer = 1 * TimeConstants::IN_MILLISECONDS;
            StartAnimation();
        }
        else m_timer -= diff;
    }

    void StartAnimation()
    {
        switch (m_phase)
        {
            case TirisfalGlades::ARADNE_PHASE_01:
                if (Creature* npc = me->FindNearestCreature(TirisfalGlades::NPC_DEATHKNELL_GRAVE_TARGET, 15.0f))
                    me->SetFacingToObject(npc);

                m_timer = uint32(0.5) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::ARADNE_PHASE_02;
                break;

            case TirisfalGlades::ARADNE_PHASE_02:
                if (Creature* npc = me->FindNearestCreature(TirisfalGlades::NPC_DEATHKNELL_GRAVE_TARGET, 15.0f))
                    me->CastSpell(npc, TirisfalGlades::SPELL_RAISE_UNDEAD, false);

                m_timer = 2 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::ARADNE_PHASE_03;
                break;
            case TirisfalGlades::ARADNE_PHASE_03:
                Talk(TirisfalGlades::ARADNE_TEXT_01);
                m_timer = uint32(0.5) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::ARADNE_PHASE_04;
                break;
            default:
                m_timer = 0;
                m_phase = TirisfalGlades::ARADNE_PHASE_00;
                break;
        }
    }
};

struct npc_deathknell_grave_target : public ScriptedAI
{
    npc_deathknell_grave_target(Creature *c) : ScriptedAI(c) { }

    uint32 m_timer;
    uint32 m_phase;

    void Reset() override
    {
        m_timer = 0;
        m_phase = TirisfalGlades::GRAVE_TARGET_PHASE_00;
    }

    void SpellHit(Unit* caster, SpellInfo const* spell)
    {
        if (spell->Id == TirisfalGlades::SPELL_RAISE_UNDEAD)
        {
            m_timer = uint32(0.1) * TimeConstants::IN_MILLISECONDS;
            m_phase = TirisfalGlades::GRAVE_TARGET_PHASE_01;
        }
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_timer <= diff)
        {
            m_timer = 1 * TimeConstants::IN_MILLISECONDS;
            StartAnimation();
        }
        else m_timer -= diff;
    }

    void StartAnimation()
    {
        switch (m_phase)
        {
            case TirisfalGlades::GRAVE_TARGET_PHASE_01:
                DoCast(me, TirisfalGlades::SPELL_DIRT_EXPLOSION);
                DoCast(me, TirisfalGlades::SPELL_CHURNING_DIRT);
                m_phase = TirisfalGlades::GRAVE_TARGET_PHASE_02;
                break;
            case TirisfalGlades::GRAVE_TARGET_PHASE_02:
                me->CastSpell(me, SPELL_SUMMON_RISEN_DEAD, true);
                m_phase = TirisfalGlades::GRAVE_TARGET_PHASE_03;
                m_timer = 3 * TimeConstants::IN_MILLISECONDS;
                break;
            case TirisfalGlades::GRAVE_TARGET_PHASE_03:
                me->RemoveAllAuras();
                m_phase = TirisfalGlades::GRAVE_TARGET_PHASE_04;
                break;
            case TirisfalGlades::GRAVE_TARGET_PHASE_04:
                m_timer = 0;
                m_phase = TirisfalGlades::GRAVE_TARGET_PHASE_00;
                break;
        }
    }
};

struct npc_risen_dead : public ScriptedAI
{
    npc_risen_dead(Creature *c) : ScriptedAI(c) { }

    uint32 m_timer;
    uint32 m_phase;
    uint32 m_WishToBeDead;

    void Reset() override
    {
        m_timer = 2 * TimeConstants::IN_MILLISECONDS;
        m_phase = TirisfalGlades::RISEN_DEAD_PHASE_00;
        m_WishToBeDead = urand(0, 100);
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_timer <= diff)
        {
            m_timer = 1 * TimeConstants::IN_MILLISECONDS;
            StartAnimation();
        }
        else m_timer -= diff;
    }

    void StartAnimation()
    {
        if (m_WishToBeDead < 33)
            ShowDeadScene();
        else if (m_WishToBeDead < 66)
            ShowLifeScene();
        else
            ShowRunningScene();
    }

    void ShowDeadScene()
    {
        switch (m_phase)
        {
            case TirisfalGlades::RISEN_DEAD_PHASE_00:
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_QUESTION);
                m_timer = uint32(0.2) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_01;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_01:
                if (Creature* aradne = me->FindNearestCreature(TirisfalGlades::NPC_ARADNE, 20.0f))
                    Talk(TirisfalGlades::RISEN_DEAD_TEXT_08, aradne);

                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_02;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_02:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_03);
                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_03;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_03:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_02);
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_09);
                me->Kill(me);
                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_04;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_04:
                m_timer = 0;
                me->DespawnOrUnsummon();
                break;
        }
    }

    void ShowRunningScene()
    {
        switch (m_phase)
        {
            case TirisfalGlades::RISEN_DEAD_PHASE_00:
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_QUESTION);
                m_timer = uint32(0.2) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_01;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_01:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_01);
                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_02;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_02:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_04);
                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_03;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_03:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_07);
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_10);
                me->UpdateEntry(NPC_MINDLESS_ZOMBIE);
                me->CastSpell(me, TirisfalGlades::SPELL_ENRAGE, true);
                me->GetMotionMaster()->MovePath(RISEN_DEAD_PATH_01, false);
                m_timer = 10 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_04;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_04:
                m_timer = 0;
                me->DespawnOrUnsummon();
                break;
        }
    }

    void ShowLifeScene()
    {
        switch (m_phase)
        {
            case TirisfalGlades::RISEN_DEAD_PHASE_00:
                me->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
                m_timer = uint32(0.2) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_01;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_01:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_01);
                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_02;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_02:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_06);
                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_03;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_03:
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_05);
                Talk(TirisfalGlades::RISEN_DEAD_TEXT_11);
                SetEquipmentSlots(false, RISEN_DEAD_VISUAL_EQUIP_WEAPON_01, RISEN_DEAD_VISUAL_EQUIP_WEAPON_02);
                me->GetMotionMaster()->MovePath(RISEN_DEAD_PATH_02, false);
                m_timer = 40 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::RISEN_DEAD_PHASE_04;
                break;
            case TirisfalGlades::RISEN_DEAD_PHASE_04:
                m_timer = 0;
                me->DespawnOrUnsummon();
                break;
        }
    }
};

struct npc_undertaker_mordo : public ScriptedAI
{
    npc_undertaker_mordo(Creature *c) : ScriptedAI(c) { }

    uint32 m_timer;
    uint32 m_phase;
    Creature* m_npc;

    void Reset() override
    {
        m_timer = urand(30, 45) * TimeConstants::IN_MILLISECONDS;
        m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_00;
        m_npc = nullptr;
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_timer <= diff)
        {
            m_timer = 1 * TimeConstants::IN_MILLISECONDS;
            StartAnimation();
        }
        else m_timer -= diff;
    }

    void StartAnimation()
    {
        switch (m_phase)
        {
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_00:
                if (Creature* npc_trigger = me->FindNearestCreature(TirisfalGlades::NPC_DEATHKNELL_GRAVE_TARGET, 20.0f))
                    if (m_npc = me->SummonCreature(TirisfalGlades::NPC_RISEN_RECRUIT, npc_trigger->GetPositionX(), npc_trigger->GetPositionY(), npc_trigger->GetPositionZ(), 1.0f, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 46 * TimeConstants::IN_MILLISECONDS))
                        m_npc->GetMotionMaster()->MovePath(TirisfalGlades::RISEN_RECRUIT_PATH_01, false);

                m_timer = 5 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_01;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_01:
                Talk(UNDERTAKER_MORDO_TEXT_01);
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_TALK);
                m_timer = 3 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_02;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_02:
                if (m_npc && m_npc->IsAlive())
                {
                    m_npc->SetStandState(UnitStandStateType::UNIT_STAND_STATE_KNEEL);
                    m_npc->SetFacingToObject(me);
                }
                m_timer = 1 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_03;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_03:
                me->HandleEmoteCommandWithDelay(6 * TimeConstants::IN_MILLISECONDS, EMOTE_STATE_USE_STANDING);
                me->HandleEmoteCommandWithDelay(7 * TimeConstants::IN_MILLISECONDS, EMOTE_STATE_NONE);
                m_timer = uint32(7.5) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_04;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_04:
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_POINT);
                m_timer = uint32(2.5) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_05;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_05:
                Talk(UNDERTAKER_MORDO_TEXT_02);
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_TALK);
                m_timer = uint32(0.5) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_06;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_06:
                if (m_npc && m_npc->IsAlive())
                {
                    m_npc->AddAura(TirisfalGlades::SPELL_RISEN_DEAD_TRANSFORM, m_npc);
                    m_npc->CastSpell(m_npc, TirisfalGlades::SPELL_RISEN_DEAD_TRANSFORM);
                    m_npc->SetDisplayId(36775);
                    m_npc->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                }
                m_timer = 2 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_07;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_07:
                if (m_npc && m_npc->IsAlive())
                {
                    m_npc->HandleEmoteCommand(Emote::EMOTE_ONESHOT_TALK);
                    m_npc->AI()->Talk(RISEN_RECRUIT_TEXT_01);
                }
                m_timer = 3 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_08;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_08:
                if (m_npc && m_npc->IsAlive())
                    m_npc->HandleEmoteCommand(Emote::EMOTE_ONESHOT_SALUTE);
                m_timer = 2 * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_09;
                break;
            case TirisfalGlades::UNDERTAKER_MORDO_PHASE_09:
                if (m_npc && m_npc->IsAlive())
                    m_npc->GetMotionMaster()->MovePath(TirisfalGlades::RISEN_RECRUIT_PATH_02, false);
                m_timer = urand(15, 45) * TimeConstants::IN_MILLISECONDS;
                m_phase = TirisfalGlades::UNDERTAKER_MORDO_PHASE_00;
                break;
        }
    }

    /*void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == TirisfalGlades::QUEST_THE_SHADOW_GRAVE)
            player->CastSpell(player, TirisfalGlades::SPELL_SUMMON_DARNELL);
    }*/
};

struct npc_mindless_zombie : public ScriptedAI
{
    npc_mindless_zombie(Creature *c) : ScriptedAI(c) { }

    EventMap events;
    bool _crazed;

    void Reset() override
    {
        me->RemoveAllAuras();
        _crazed = false;
        me->GetMotionMaster()->MoveRandom(15.f);

        if (!_crazed && roll_chance_i(20))
        {
            _crazed = true;
            events.ScheduleEvent(TirisfalGlades::MINDLESS_ZOMBIE_ATTACK_EVENT_STEP_01, urand(28, 57) * TimeConstants::IN_MILLISECONDS);
        }
    }

    void UpdateAI(const uint32 diff) override
    {
        events.Update(diff);

        if (!me->IsInCombat())
        {
            if (Player* player = me->SelectNearestPlayer(15.0f))
            {
                if (!player->IsInCombat())
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case TirisfalGlades::MINDLESS_ZOMBIE_ATTACK_EVENT_STEP_01:
                            {
                                me->SetFacingToObject(player);
                                me->CastSpell(me, TirisfalGlades::SPELL_ENRAGE, true);
                                me->SetWalk(false);
                                me->GetMotionMaster()->MoveFollow(player, 1.0f, 0.0f);
                                events.ScheduleEvent(TirisfalGlades::MINDLESS_ZOMBIE_ATTACK_EVENT_STEP_02, urand(4, 6) * TimeConstants::IN_MILLISECONDS);
                                break;
                            }
                            case TirisfalGlades::MINDLESS_ZOMBIE_ATTACK_EVENT_STEP_02:
                            {
                                me->GetMotionMaster()->Clear();
                                me->GetMotionMaster()->MoveRandom(15.f);
                                me->RemoveAllAuras();
                                break;
                            }
                        }
                    }
                }
            }
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_tirisfal_glades()
{
    new creature_script<npc_aradne>("npc_aradne");
    new creature_script<npc_deathknell_grave_target>("npc_deathknell_grave_target");
    new creature_script<npc_risen_dead>("npc_risen_dead");
    new creature_script<npc_undertaker_mordo>("npc_undertaker_mordo");
    new creature_script<npc_mindless_zombie>("npc_mindless_zombie");
}
