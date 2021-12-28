/*
* Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
* Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
* Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

/* ScriptData
SDName: Elwynn_Forest
SD%Complete: 50
SDCategory: Elwynn Forest
EndScriptData */

/* ContentData
npc_blackrock_spy
npc_blackrock_invader
npc_stormwind_infantry
npc_blackrock_battle_worg
npc_goblin_assassin
EndContentData */

#include "ScriptPCH.h"
#include "../AI/SmartScripts/SmartAI.h"

enum eYells
{
    SAY_BLACKROCK_COMBAT_1    = -1000015,
    SAY_BLACKROCK_COMBAT_2    = -1000016,
    SAY_BLACKROCK_COMBAT_3    = -1000017,
    SAY_BLACKROCK_COMBAT_4    = -1000018,
    SAY_BLACKROCK_COMBAT_5    = -1000019,
    SAY_ASSASSIN_COMBAT_1     = -1000020,
    SAY_ASSASSIN_COMBAT_2     = -1000021,
    SAY_INFANTRY_YELL         = 1,          //Stormwind Infantry Yell phrase from Group 1

    // Alliance Way
    SAY_INTRO                 = 0,
    SAY_SPECIAL_1,
    SAY_SPECIAL_2,
    SAY_SPECIAL_3,
    SAY_SPECIAL_4,
    SAY_SPECIAL_5,
    SAY_SPECIAL_6,
    SAY_SPECIAL_7,
    SAY_SPECIAL_8,
    SAY_SPECIAL_9,
    SAY_SPECIAL_10,
    SAY_SPECIAL_11,
    SAY_SPECIAL_12,
    SAY_SPECIAL_13,
    SAY_SPECIAL_14,
    SAY_SPECIAL_15,
    SAY_SPECIAL_16,
    SAY_SPECIAL_17,
    SAY_SPECIAL_18,
    SAY_SPECIAL_19,
};

enum eMisc
{
    WORG_FIGHTING_FACTION = 232,        //Faction used by worgs to be able to attack infantry
    WORG_FACTION_RESTORE  = 32,         //Default Blackrock Battle Worg Faction
    WORG_GROWL            = 2649,       //Worg Growl Spell
    AI_HEALTH_MIN         = 85,         //Minimum health for AI staged fight between Blackrock Battle Worgs and Stormwind Infantry
    INFANTRY_YELL_CHANCE  = 10           //% Chance for Stormwind Infantry to Yell - May need further adjustment... should be low chance
};

enum eQuests
{
    QUEST_ALLIANCE_WAY       = 30988,
    QUEST_AN_OLD_PIT_FIGHTER = 30989,
};

enum eCreatures
{
    NPC_KING_VARIAN_WRYNN         = 29611,
    NPC_VARIAN_WRYNN_ALLIANCE_WAY = 61796,
    NPC_AYISA_ALLIANCE_WAY        = 61792,
    NPC_JO_JO_ALLIANCE_WAY        = 61793,
    NPC_BLACKROCK_BATTLE_WORG     = 49871,      //Blackrock Battle Worg NPC ID
    NPC_STORMWIND_INFANTRY        = 49869,      //Stormwind Infantry NPC ID
    NPC_WALK_WITH_VARIAN_CREDIT   = 61798,
    NPC_FIGHT_WITH_VARIAN_CREDIT  = 61824,
};

enum eSpells
{
    SPELL_SUMMON_VARIAN            = 120352,
    SPELL_SUMMON_AYSA_AND_JOJO     = 120344,
    SPELL_SPYING                   = 92857,
    SPELL_SNEAKING                 = 93046,
    SPELL_SPYGLASS                 = 80676,
    SPELL_VARIAN_GET_PUNCHED_SCENE = 120568, // SPELL_EFFECT_186 not implemented in core
};

enum eActions
{
    ACTION_AN_OLD_PIT_FIGHTER,
};

const Position AysaJojoStandPos[2]
{
    { -8331.30f, 290.36f, 156.83f, 5.99f }, // Ayisa
    { -8313.47f, 277.04f, 156.83f, 2.26f },
};

const Position VarianPath[9]
{
    { -8363.68f, 241.96f, 155.31f, 1.50f },
    { -8358.11f, 258.80f, 155.34f, 1.25f },
    { -8343.70f, 269.41f, 155.34f, 0.63f },
    { -8325.33f, 246.29f, 155.34f, 5.39f },
    { -8277.68f, 283.86f, 155.34f, 0.67f },
    { -8315.63f, 331.37f, 155.34f, 2.25f },
    { -8339.31f, 312.58f, 155.34f, 3.76f },
    { -8334.64f, 307.08f, 157.34f, 5.34f },
    { -8323.51f, 293.86f, 156.83f, 5.34f },
};

const Position VarianHomePath[3]
{
    { -8338.44f, 274.53f, 157.34f, 3.78f },
    { -8362.87f, 254.89f, 155.34f, 3.78f },
    { -8363.05f, 232.23f, 157.07f, 2.23f },
};

/*######
## npc_blackrock_spy
######*/

class npc_blackrock_spy : public CreatureScript
{
    public:
        npc_blackrock_spy() : CreatureScript("npc_blackrock_spy") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blackrock_spyAI (creature);
        }

        struct npc_blackrock_spyAI : public ScriptedAI
        {
            npc_blackrock_spyAI(Creature* creature) : ScriptedAI(creature)
            {
                CastSpying();
            }

            void CastSpying()
            {
                GetCreature(-8868.88f, -99.1016f);
                GetCreature(-8936.5f, -246.743f);
                GetCreature(-8922.44f, -73.9883f);
                GetCreature(-8909.68f, -40.0247f);
                GetCreature(-8834.85f, -119.701f);
                GetCreature(-9022.08f, -163.965f);
                GetCreature(-8776.55f, -79.158f);
                GetCreature(-8960.08f, -63.767f);
                GetCreature(-8983.12f, -202.827f);
            }

            void GetCreature(float X, float Y)
            {
                if (me->GetHomePosition().GetPositionX() == X && me->GetHomePosition().GetPositionY() == Y)
                    if (!me->IsInCombat() && !me->HasAura(SPELL_SPYING))
                        DoCast(me, SPELL_SPYING);

                CastSpyglass();
            }

            void CastSpyglass()
            {
                Spyglass(-8868.88f, -99.1016f, -8936.5f, -246.743f, -8922.44f, -73.9883f, -8909.68f, -40.0247f, -8834.85f,
                    -119.701f, -9022.08f, -163.965f, -8776.55f, -79.158f, -8960.08f, -63.767f, -8983.12f, -202.827f);
            }

            void Spyglass(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4, float X5, float Y5,
                float X6, float Y6, float X7, float Y7, float X8, float Y8, float X9, float Y9)
            {
                if ((me->GetHomePosition().GetPositionX() != X1 && me->GetHomePosition().GetPositionY() != Y1) &&
                    (me->GetHomePosition().GetPositionX() != X2 && me->GetHomePosition().GetPositionY() != Y2) &&
                    (me->GetHomePosition().GetPositionX() != X3 && me->GetHomePosition().GetPositionY() != Y3) &&
                    (me->GetHomePosition().GetPositionX() != X4 && me->GetHomePosition().GetPositionY() != Y4) &&
                    (me->GetHomePosition().GetPositionX() != X5 && me->GetHomePosition().GetPositionY() != Y5) &&
                    (me->GetHomePosition().GetPositionX() != X6 && me->GetHomePosition().GetPositionY() != Y6) &&
                    (me->GetHomePosition().GetPositionX() != X7 && me->GetHomePosition().GetPositionY() != Y7) &&
                    (me->GetHomePosition().GetPositionX() != X8 && me->GetHomePosition().GetPositionY() != Y8) &&
                    (me->GetHomePosition().GetPositionX() != X9 && me->GetHomePosition().GetPositionY() != Y9))
                    if (me->GetHomePosition().GetPositionX() == me->GetPositionX() && me->GetHomePosition().GetPositionY() == me->GetPositionY())
                        if (!me->IsInCombat() && !me->HasAura(SPELL_SPYGLASS))
                            DoCast(me, SPELL_SPYGLASS);
            }

            void EnterCombat(Unit* who)
            {
                Talk(RAND(SAY_BLACKROCK_COMBAT_1, SAY_BLACKROCK_COMBAT_2, SAY_BLACKROCK_COMBAT_3, SAY_BLACKROCK_COMBAT_4, SAY_BLACKROCK_COMBAT_5), me);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                CastSpyglass();

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };
};

/*######
## npc_blackrock_invader
######*/

class npc_blackrock_invader : public CreatureScript
{
    public:
        npc_blackrock_invader() : CreatureScript("npc_blackrock_invader") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blackrock_invaderAI (creature);
        }

        struct npc_blackrock_invaderAI : public ScriptedAI
        {
            npc_blackrock_invaderAI(Creature* creature) : ScriptedAI(creature) {}

            void EnterCombat(Unit* who)
            {
                Talk(RAND(SAY_BLACKROCK_COMBAT_1, SAY_BLACKROCK_COMBAT_2, SAY_BLACKROCK_COMBAT_3, SAY_BLACKROCK_COMBAT_4, SAY_BLACKROCK_COMBAT_5), me);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };
};

/*######
## npc_goblin_assassin
######*/

class npc_goblin_assassin : public CreatureScript
{
    public:
        npc_goblin_assassin() : CreatureScript("npc_goblin_assassin") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_goblin_assassinAI (creature);
        }

        struct npc_goblin_assassinAI : public ScriptedAI
        {
            npc_goblin_assassinAI(Creature* creature) : ScriptedAI(creature)
            {
                if (!me->IsInCombat() && !me->HasAura(SPELL_SPYING))
                    DoCast(SPELL_SNEAKING);
            }

            void EnterCombat(Unit* who)
            {
                Talk(RAND(SAY_ASSASSIN_COMBAT_1, SAY_ASSASSIN_COMBAT_2), me);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };
};

/*######
## npc_stormwind_infantry
######*/

class npc_stormwind_infantry : public CreatureScript
{
    public:
        npc_stormwind_infantry() : CreatureScript("npc_stormwind_infantry") {}

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_stormwind_infantryAI (creature);
        }

        struct npc_stormwind_infantryAI : public ScriptedAI
        {
            npc_stormwind_infantryAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 tSeek, cYell,tYell;

            void Reset()
            {
                tSeek=urand(1000,2000);
                cYell=urand(0, 100);
                tYell=urand(5000, 60000);
            }

            void DamageTaken(Unit* who, uint32& damage)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)//If damage taken from player
                {
                    me->getThreatManager().resetAllAggro();
                    who->AddThreat(me, 1.0f);
                    me->AddThreat(who, 1.0f);
                    me->AI()->AttackStart(who);
                }
                else if (who->IsPet())//If damage taken from pet
                {
                    me->getThreatManager().resetAllAggro();
                    me->AddThreat(who, 1.0f);
                    me->AI()->AttackStart(who);
                }
                if (who->GetEntry() == NPC_BLACKROCK_BATTLE_WORG && me->HealthBelowPct(AI_HEALTH_MIN))//If damage taken from Blackrock Battle Worg
                {
                    damage = 0;//We do not want to do damage if Blackrock Battle Worg is below preset HP level (currently 85% - Blizzlike)
                    me->AddThreat(who, 1.0f);
                    me->AI()->AttackStart(who);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
                else
                {
                    if (tYell <= diff)//Chance to yell every 5 to 10 seconds
                    {
                        if (cYell < INFANTRY_YELL_CHANCE)//Roll for random chance to Yell phrase
                        {
                            me->AI()->Talk(SAY_INFANTRY_YELL); //Yell phrase
                            tYell=urand(10000, 120000);//After First yell, change time range from 10 to 120 seconds
                        }
                        else
                            tYell=urand(10000, 120000);//From 10 to 120 seconds
                    }
                    else
                    {
                        tYell -= diff;
                        DoMeleeAttackIfReady(); //Else do standard attack
                    }
                }
            }
        };
};

/*######
## npc_blackrock_battle_worg
######*/

class npc_blackrock_battle_worg : public CreatureScript
{
    public:
        npc_blackrock_battle_worg() : CreatureScript("npc_blackrock_battle_worg") {}

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blackrock_battle_worgAI (creature);
        }

        struct npc_blackrock_battle_worgAI : public ScriptedAI
        {
            npc_blackrock_battle_worgAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 tSeek, tGrowl;

            void Reset()
            {
                tSeek=urand(1000,2000);
                tGrowl=urand(8500,10000);
                me->setFaction(WORG_FACTION_RESTORE);//Restore our faction on reset
            }

            void DamageTaken(Unit* who, uint32& damage)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)//If damage taken from player
                {
                    me->getThreatManager().resetAllAggro();
                    who->AddThreat(me, 1.0f);
                    me->AddThreat(who, 1.0f);
                    me->AI()->AttackStart(who);
                }
                else if (who->IsPet())//If damage taken from pet
                {
                    me->getThreatManager().resetAllAggro();
                    me->AddThreat(who, 1.0f);
                    me->AI()->AttackStart(who);
                }
                if (who->GetEntry() == NPC_STORMWIND_INFANTRY && me->HealthBelowPct(AI_HEALTH_MIN))//If damage taken from Stormwind Infantry
                {
                    damage = 0;//We do not want to do damage if Stormwind Infantry is below preset HP level (currently 85% - Blizzlike)
                    me->AddThreat(who, 1.0f);
                    me->AI()->AttackStart(who);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (tSeek <= diff)
                {
                    if ((me->IsAlive()) && (!me->IsInCombat() && (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) <= 1.0f)))
                        if (Creature* enemy = me->FindNearestCreature(NPC_STORMWIND_INFANTRY,1.0f, true))
                        {
                            me->setFaction(WORG_FIGHTING_FACTION);//We must change our faction to one which is able to attack Stormwind Infantry (Faction 232 works well)
                            me->AI()->AttackStart(enemy);
                            tSeek = urand(1000,2000);
                        }
                }
                else
                    tSeek -= diff;

                if (UpdateVictim())
                {
                    if (tGrowl <=diff)
                    {
                        DoCast(me->GetVictim(), WORG_GROWL);//Do Growl if ready
                        tGrowl=urand(8500,10000);
                    }
                    else
                    {
                       tGrowl -= diff;
                       DoMeleeAttackIfReady();//Else do standard attack
                    }
                }
                else
                {
                    me->setFaction(WORG_FACTION_RESTORE);//Reset my faction if not in combat
                    return;
                }
            }
        };
};

// King Varian Wrynn 29611
class npc_king_varian_wrynn : public CreatureScript
{
    public:
        npc_king_varian_wrynn() : CreatureScript("npc_king_varian_wrynn") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ALLIANCE_WAY)
                player->CastSpell(creature, SPELL_SUMMON_VARIAN, true);

            return false;
        }

        struct npc_king_varian_wrynnAI : public SmartAI
        {
            npc_king_varian_wrynnAI(Creature* creature) : SmartAI(creature) { }

            void EnterCombat(Unit* who) override
            {
                SmartAI::EnterCombat(who);
            }

            void UpdateAI(uint32 diff) override
            {
                SmartAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_king_varian_wrynnAI(creature);
        }
};

// Varian Wrynn Alliance Way 61796
class npc_varian_wrynn_alliance_way_quest : public CreatureScript
{
    public:
        npc_varian_wrynn_alliance_way_quest() : CreatureScript("npc_varian_wrynn_alliance_way_quest") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_AN_OLD_PIT_FIGHTER)
                player->CastSpell(creature, SPELL_SUMMON_VARIAN, true);

            return false;
        }

        struct npc_varian_wrynn_alliance_way_questAI : public ScriptedAI
        {
            npc_varian_wrynn_alliance_way_questAI(Creature* creature) : ScriptedAI(creature) { }

            uint64 summonerGUID;
            uint32 delay;

            void IsSummonedBy(Unit* summoner) override
            {
                summonerGUID = summoner->GetGUID();
                me->SetFacingToObject(summoner);
                me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->SetPhaseMask(2, true);

                if (summoner->ToPlayer() && summoner->ToPlayer()->GetQuestStatus(QUEST_ALLIANCE_WAY) == QUEST_STATUS_REWARDED)
                {
                    DoAction(ACTION_AN_OLD_PIT_FIGHTER);
                    return;
                }

                delay = 0;
                me->m_Events.Schedule(delay += 1500, 17, [this]()
                {
                    Movement::MoveSplineInit init(me);
                    for (auto itr : VarianPath)
                        init.Path().push_back(G3D::Vector3(itr.GetPositionX(), itr.GetPositionY(), itr.GetPositionZ()));

                    init.SetWalk(true);
                    init.Launch();

                    me->m_Events.Schedule(delay += me->GetSplineDuration(), 16, [this]()
                    {
                        me->SetFacingTo(Position::NormalizeOrientation(me->GetOrientation() + M_PI));
                        me->DespawnOrUnsummon(1 * IN_MILLISECONDS);

                        if (Player* owner = ObjectAccessor::GetPlayer(*me, summonerGUID))
                        {
                            owner->KilledMonsterCredit(NPC_WALK_WITH_VARIAN_CREDIT);

                            delay = 0;
                            owner->m_Events.Schedule(delay += 1000, 1, [owner]()
                            {
                                owner->SetPhaseMask(1, true);
                            });
                        }
                    });

                    delay = 0;
                    me->m_Events.Schedule(delay += 2000, 1, [this]()
                    {
                        Talk(SAY_INTRO);
                    });

                    me->m_Events.Schedule(delay += 5000, 2, [this]()
                    {
                        Talk(SAY_SPECIAL_1);
                    });

                    me->m_Events.Schedule(delay += 5000, 3, [this]()
                    {
                        Talk(SAY_SPECIAL_2);
                    });

                    me->m_Events.Schedule(delay += 7000, 4, [this]()
                    {
                        Talk(SAY_SPECIAL_3);
                    });

                    me->m_Events.Schedule(delay += 9000, 5, [this]()
                    {
                        Talk(SAY_SPECIAL_4);
                    });

                    me->m_Events.Schedule(delay += 5000, 6, [this]()
                    {
                        Talk(SAY_SPECIAL_5);
                    });

                    me->m_Events.Schedule(delay += 9000, 7, [this]()
                    {
                        Talk(SAY_SPECIAL_6);
                    });

                    me->m_Events.Schedule(delay += 10000, 8, [this]()
                    {
                        Talk(SAY_SPECIAL_7);
                    });

                    me->m_Events.Schedule(delay += 5000, 9, [this]()
                    {
                        Talk(SAY_SPECIAL_8);
                    });

                    me->m_Events.Schedule(delay += 6000, 10, [this]()
                    {
                        Talk(SAY_SPECIAL_9);
                    });

                    me->m_Events.Schedule(delay += 5000, 11, [this]()
                    {
                        Talk(SAY_SPECIAL_10);
                    });

                    me->m_Events.Schedule(delay += 7000, 12, [this]()
                    {
                        Talk(SAY_SPECIAL_11);
                    });

                    me->m_Events.Schedule(delay += 9000, 13, [this]()
                    {
                        Talk(SAY_SPECIAL_12);
                    });

                    me->m_Events.Schedule(delay += 14000, 14, [this]()
                    {
                        Talk(SAY_SPECIAL_13);
                    });
                });
            }

            void DoAction(int32 actionId) override
            {
                if (actionId == ACTION_AN_OLD_PIT_FIGHTER)
                {
                    delay = 0;
                    me->m_Events.Schedule(delay += 1500, 18, [this]()
                    {
                        Talk(SAY_SPECIAL_14);
                    });

                    me->m_Events.Schedule(delay += 11000, 20, [this]()
                    {
                        me->setFaction(16);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                        Talk(SAY_SPECIAL_15);
                    });

                    me->m_Events.Schedule(delay += 9300, 21, [this]()
                    {
                        Talk(SAY_SPECIAL_16);
                    });

                    me->m_Events.Schedule(delay += 6000, 22, [this]()
                    {
                        Talk(SAY_SPECIAL_17);
                    });

                    me->m_Events.Schedule(delay += 12000, 23, [this]()
                    {
                        Talk(SAY_SPECIAL_18);
                    });

                    me->m_Events.Schedule(delay += 2900, 24, [this]()
                    {
                        if (Player* owner = ObjectAccessor::GetPlayer(*me, summonerGUID))
                        {
                            owner->KilledMonsterCredit(NPC_FIGHT_WITH_VARIAN_CREDIT);
                            owner->CombatStop();
                        }

                        me->CombatStop();
                        me->setFaction(35);
                    });

                    me->m_Events.Schedule(delay += 3500, 25, [this]()
                    {
                        Talk(SAY_SPECIAL_19);
                    });

                    me->m_Events.Schedule(delay += 2300, 26, [this]()
                    {
                        Movement::MoveSplineInit init(me);
                        for (auto itr : VarianHomePath)
                            init.Path().push_back(G3D::Vector3(itr.GetPositionX(), itr.GetPositionY(), itr.GetPositionZ()));

                        init.SetUncompressed();
                        init.Launch();

                        delay = 0;
                        me->m_Events.Schedule(delay += me->GetSplineDuration(), 27, [this]()
                        {
                            if (Player* owner = ObjectAccessor::GetPlayer(*me, summonerGUID))
                                owner->SetPhaseMask(1, true);

                            me->DespawnOrUnsummon();
                        });
                    });
                }
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                damage = 0;
                me->HandleEmoteCommand(EMOTE_ONESHOT_DODGE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_varian_wrynn_alliance_way_questAI(creature);
        }
};

// Ayisa and Jo Jo Alliance way 61792, 61793
class npc_ayisa_jojo_alliance_way_quest : public CreatureScript
{
    public:
        npc_ayisa_jojo_alliance_way_quest() : CreatureScript("npc_ayisa_jojo_alliance_way_quest") { }

        struct npc_ayisa_jojo_alliance_way_questAI : public ScriptedAI
        {
            npc_ayisa_jojo_alliance_way_questAI(Creature* creature) : ScriptedAI(creature) { }

            uint64 summonerGUID;
            uint32 delay;
            uint8 point;
            bool follow;

            void IsSummonedBy(Unit* summoner) override
            {
                point = 0;
                summonerGUID = summoner->GetGUID();
                me->SetPhaseMask(2, true);
                me->DespawnOrUnsummon(2 * MINUTE * IN_MILLISECONDS + 30 * IN_MILLISECONDS);
                follow = true;

                if (summoner->ToPlayer() && summoner->ToPlayer()->GetQuestStatus(QUEST_ALLIANCE_WAY) == QUEST_STATUS_REWARDED)
                {
                    DoAction(ACTION_AN_OLD_PIT_FIGHTER);
                    follow = false;
                    return;
                }

                if (me->GetEntry() == NPC_AYISA_ALLIANCE_WAY)
                {
                    delay = 0;
                    me->m_Events.Schedule(delay += 23000, 1, [this]()
                    {
                        Talk(SAY_INTRO);
                    });

                    me->m_Events.Schedule(delay += 25000, 1, [this]()
                    {
                        Talk(SAY_SPECIAL_1);
                    });

                    me->m_Events.Schedule(delay += 53000, 1, [this]()
                    {
                        Talk(SAY_SPECIAL_2);
                    });
                }
            }

            void DoAction(int32 actionId) override
            {
                if (actionId == ACTION_AN_OLD_PIT_FIGHTER)
                {
                    delay = 0;
                    me->m_Events.Schedule(delay += 11000, 19, [this]()
                    {
                        Movement::MoveSplineInit init(me);
                        point = me->GetEntry() == NPC_AYISA_ALLIANCE_WAY ? 0 : 1;
                        init.MoveTo(AysaJojoStandPos[point].GetPositionX(), AysaJojoStandPos[point].GetPositionY(), AysaJojoStandPos[point].GetPositionZ());

                        init.Launch();

                        me->m_Events.Schedule(delay += 19000, 21, [this]()
                        {
                            if (me->GetEntry() == NPC_AYISA_ALLIANCE_WAY)
                                if (Unit* owner = ObjectAccessor::GetUnit(*me, summonerGUID))
                                    Talk(SAY_SPECIAL_3, owner);
                        });

                        me->m_Events.Schedule(delay += 10800, 22, [this]()
                        {
                            follow = true;
                        });

                        delay = 0;
                        me->m_Events.Schedule(delay += me->GetSplineDuration(), 20, [this]()
                        {
                            me->SetFacingTo(AysaJojoStandPos[point].GetOrientation());
                        });
                    });
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (follow)
                    if (Unit* owner = ObjectAccessor::GetUnit(*me, summonerGUID))
                        me->GetMotionMaster()->MoveFollow(owner, 2.5f, me->GetAngle(owner));
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ayisa_jojo_alliance_way_questAI(creature);
        }
};

// Summon Varian alliance way 120352
class spell_summ_varian_alliance_way : public SpellScript
{
    PrepareSpellScript(spell_summ_varian_alliance_way);

    void HandleAfterCast()
    {
        if (Player* pCaster = GetCaster()->ToPlayer())
        {
            pCaster->SetPhaseMask(3, true);
            pCaster->CastSpell(pCaster, SPELL_SUMMON_AYSA_AND_JOJO, true);
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_summ_varian_alliance_way::HandleAfterCast);
    }
};

enum Hogger
{
    SAY_AGGRO                  = 0,
    SAY_HELP                   = 1,
    SAY_GRR                    = 2,
    SAY_NO                     = 3,
    SAY_EATING                 = 4,
    SAY_STUNNED                = 5,
    SAY_NO_HURT                = 6,

    SPELL_TELEPORT_VISUAL_ONLY = 64446,
    SPELL_VICIOUS_SLICE        = 87337,
    SPELL_EATING               = 87351,
    SPELL_UPSET_STOMACH        = 87352,
    SPELL_SUMMON_MINIONS       = 87366,
    SPELL_BLOODY_STRIKE        = 87359,

    NPC_HOGGER                 = 448,
    NPC_DUMAS                  = 46940,
    NPC_ANDROMATH              = 46941,
    NPC_JONATHAN               = 46942,
    NPC_RAGAMUFFIN             = 46943,
    NPC_TRIGGER_MEAT           = 45979,

    PHASE_EATING               = 1,
    PHASE_EATING_ENDED         = 2,
    PHASE_FINAL                = 3,

    EVENT_CAST_VICIOUS_SLICE = 1,
    EVENT_HALF_HP_ONCE       = 2,
    EVENT_CAST_BLOODY_STRIKE = 3,
    EVENT_BACK_TO_FIGHT      = 4,
    EVENT_SUMMON_GUARDS      = 5,
    EVENT_SUMMON_KIDS        = 6,
    EVENT_SAY_GRR            = 7,
    EVENT_SAY_NO             = 8
};

struct npc_hogger : public ScriptedAI
{
    npc_hogger(Creature* creature) : ScriptedAI(creature)
    {
        if (Creature* trigger_meat = me->FindNearestCreature(NPC_TRIGGER_MEAT, 30))
            trigger_meat_guid = trigger_meat->GetGUID();
    }

    void Reset()
    {
        me->SetReactState(REACT_AGGRESSIVE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        phase = 0;
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (urand(0, 9) < 3) // 30% Шанс для текста
            Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_CAST_VICIOUS_SLICE, 3000);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (!phase && !HealthAbovePct(50))
        {
            Talk(SAY_HELP);
            me->CastSpell(me, SPELL_SUMMON_MINIONS, true);
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            phase = PHASE_EATING;
            events.CancelEvent(EVENT_CAST_VICIOUS_SLICE);
            events.ScheduleEvent(EVENT_HALF_HP_ONCE, 4000);
        }
        else if (phase == PHASE_EATING && me->HasAura(SPELL_UPSET_STOMACH))
        {
            Talk(SAY_STUNNED);
            phase = PHASE_EATING_ENDED;
            events.CancelEvent(EVENT_CAST_BLOODY_STRIKE);
            events.RescheduleEvent(EVENT_BACK_TO_FIGHT, 10000);
        }
        if (damage >= me->GetHealth() && phase != PHASE_FINAL)
        {
            Talk(SAY_NO_HURT);
            me->RemoveAllAuras();
            me->AttackStop();
            attacker->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetWalk(true);
            me->GetMotionMaster()->MovePoint(1, -10136.9f, 670.009f, 36.03682f);
            damage = me->GetHealth() - 1;
            phase = PHASE_FINAL;
            events.Reset();
            if (Player* player = me->GetLootRecipient())
                player->RewardPlayerAndGroupAtKill(me, false);
        }
        else if (phase == PHASE_FINAL)
        {
            attacker->AttackStop();
            damage = me->GetHealth() - 1;
        }
    }

    void MovementInform(uint32 /*type*/, uint32 waypoint_id) override
    {
        switch (waypoint_id)
        {
            case 0:
                me->CastSpell(me, SPELL_EATING, true);
                events.ScheduleEvent(EVENT_CAST_BLOODY_STRIKE, 0);
                events.ScheduleEvent(EVENT_BACK_TO_FIGHT, 15000);
                break;
            case 1:
                events.ScheduleEvent(EVENT_SUMMON_GUARDS, 1000);
                break;
        }
    }

    void SetData(uint32 /*type*/, uint32 /*data*/) override
    {
        me->CastSpell(me, SPELL_TELEPORT_VISUAL_ONLY, true);
        me->DespawnOrUnsummon(1000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CAST_VICIOUS_SLICE:
                    if (Unit* vict = me->GetVictim())
                        me->CastSpell(vict, SPELL_VICIOUS_SLICE, false);

                    events.ScheduleEvent(EVENT_CAST_VICIOUS_SLICE, 12000);
                    break;
                case EVENT_HALF_HP_ONCE:
                {
                    Talk(SAY_EATING);
                    float trigger_x, trigger_y;
                    if (Creature* trigger_meat = ObjectAccessor::GetCreature(*me, trigger_meat_guid))
                    {
                        trigger_meat->GetPosition(trigger_x, trigger_y);
                        const float angle = me->GetAngle(trigger_x, trigger_y);
                        const float x = trigger_meat->GetPositionX() - 2 * cos(angle);
                        const float y = trigger_meat->GetPositionY() - 2 * sin(angle);
                        const float z = trigger_meat->GetMap()->GetHeight(x, y, trigger_meat->GetPositionZ());
                        me->GetMotionMaster()->MovePoint(0, x, y, z);
                    }
                    break;
                }
                case EVENT_CAST_BLOODY_STRIKE:
                    if (Creature* meatTrigger = ObjectAccessor::GetCreature(*me, trigger_meat_guid))
                        me->CastSpell(meatTrigger, SPELL_BLOODY_STRIKE, false);

                    events.ScheduleEvent(EVENT_CAST_BLOODY_STRIKE, 3000);
                    break;
                case EVENT_BACK_TO_FIGHT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    phase = PHASE_EATING_ENDED;
                    events.CancelEvent(EVENT_CAST_BLOODY_STRIKE);
                    events.ScheduleEvent(EVENT_CAST_VICIOUS_SLICE, 3000);
                    break;
                case EVENT_SUMMON_GUARDS:
                    me->SummonCreature(NPC_JONATHAN, -10128.3f, 656.465f, 36.05443f, 2.045435f, TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(NPC_DUMAS, -10132.9f, 653.561f, 36.05033f, 2.020999f, TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(NPC_ANDROMATH, -10123.0f, 656.875f, 36.05113f, 1.971813f, TEMPSUMMON_MANUAL_DESPAWN);
                    events.ScheduleEvent(EVENT_SUMMON_KIDS, 4000);
                    break;
                case EVENT_SUMMON_KIDS:
                {
                    if (Creature* ragamuffin1 = me->SummonCreature(NPC_RAGAMUFFIN, -10130.9f, 653.302f, 36.05013f, 1.652422f, TEMPSUMMON_TIMED_DESPAWN, 7500))
                        ragamuffin1->AI()->SetData(0, 1);

                    if (Creature* ragamuffin2 = me->SummonCreature(NPC_RAGAMUFFIN, -10122.5f, 660.198f, 36.03663f, 2.837752f, TEMPSUMMON_TIMED_DESPAWN, 6500))
                        ragamuffin2->AI()->SetData(0, 2);

                    events.ScheduleEvent(EVENT_SAY_GRR, 8500);
                    break;
                }
                case EVENT_SAY_GRR:
                    Talk(SAY_GRR);
                    if (Creature* jonathan = me->FindNearestCreature(NPC_JONATHAN, 10))
                        me->SetFacingToObject(jonathan);
                    events.ScheduleEvent(EVENT_SAY_NO, 15000);
                    break;
                case EVENT_SAY_NO:
                    Talk(SAY_NO);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap events;
    uint64 trigger_meat_guid;
    uint8 phase = 0;
};

enum MinionOfHogger
{
    SPELL_ADVENTURERS_RUSH = 87402
};

struct npc_minion_of_hogger : public ScriptedAI
{
    npc_minion_of_hogger(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastAOE(SPELL_ADVENTURERS_RUSH);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->GetVictim())
            me->AI()->AttackStart(summoner->GetVictim());
    }
};

void AddSC_elwynn_forest()
{
    new npc_blackrock_spy();
    new npc_goblin_assassin();
    new npc_blackrock_invader();
    new npc_stormwind_infantry();
    new npc_blackrock_battle_worg();
    new npc_king_varian_wrynn();
    new npc_varian_wrynn_alliance_way_quest();
    new npc_ayisa_jojo_alliance_way_quest();
    new spell_script<spell_summ_varian_alliance_way>("spell_summ_varian_alliance_way");
    new creature_script<npc_hogger>("npc_hogger");
    new creature_script<npc_minion_of_hogger>("npc_minion_of_hogger");
}
