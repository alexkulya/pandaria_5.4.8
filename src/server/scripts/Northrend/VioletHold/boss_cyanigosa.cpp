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

#include "ScriptPCH.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_ARCANE_VACUUM                         = 58694,
    SPELL_BLIZZARD                              = 58693,
    SPELL_BLIZZARD_H                            = 59369,
    SPELL_MANA_DESTRUCTION                      = 59374,
    SPELL_TAIL_SWEEP                            = 58690,
    SPELL_TAIL_SWEEP_H                          = 59283,
    SPELL_UNCONTROLLABLE_ENERGY                 = 58688,
    SPELL_UNCONTROLLABLE_ENERGY_H               = 59281,
    SPELL_TRANSFORM                             = 58668
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_DISRUPTION                              = 4, // unused
    SAY_BREATH_ATTACK                           = 5, // unused
    SAY_SPECIAL_ATTACK                          = 6, // unused
};

class boss_cyanigosa : public CreatureScript
{
    public:
        boss_cyanigosa() : CreatureScript("boss_cyanigosa") { }

        struct boss_cyanigosaAI : public ScriptedAI
        {
            boss_cyanigosaAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            uint32 uiArcaneVacuumTimer;
            uint32 uiBlizzardTimer;
            uint32 uiManaDestructionTimer;
            uint32 uiTailSweepTimer;
            uint32 uiUncontrollableEnergyTimer;

            InstanceScript* instance;

            void Reset() override
            {
                uiArcaneVacuumTimer = 10000;
                uiBlizzardTimer = 15000;
                uiManaDestructionTimer = 30000;
                uiTailSweepTimer = 5000;
                uiUncontrollableEnergyTimer = 25000;
                if (instance)
                    instance->SetData(DATA_CYANIGOSA_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);

                if (instance)
                    instance->SetData(DATA_CYANIGOSA_EVENT, IN_PROGRESS);
            }

            void SpellHitTarget (Unit* target, const SpellInfo* spell) override
            {
                if (spell->Id == SPELL_ARCANE_VACUUM)
                {
                    if (target->ToPlayer())
                        target->ToPlayer()->TeleportTo(me->GetMapId(),me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0);
                }
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                if (instance && instance->GetData(DATA_REMOVE_NPC) == 1)
                {
                    me->DespawnOrUnsummon();
                    instance->SetData(DATA_REMOVE_NPC, 0);
                }

                if (!UpdateVictim())
                    return;

                if (uiArcaneVacuumTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(SPELL_ARCANE_VACUUM);
                        uiArcaneVacuumTimer = 30000;
                    }
                } else uiArcaneVacuumTimer -= diff;

                if (uiBlizzardTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_BLIZZARD);
                        uiBlizzardTimer = 15000;
                    }
                } else uiBlizzardTimer -= diff;

                if (uiTailSweepTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(DUNGEON_MODE(SPELL_TAIL_SWEEP, SPELL_TAIL_SWEEP_H));
                        uiTailSweepTimer = 5000;
                    }
                } else uiTailSweepTimer -= diff;

                if (uiUncontrollableEnergyTimer <= diff)
                {
                    DoCastVictim(SPELL_UNCONTROLLABLE_ENERGY);
                    uiUncontrollableEnergyTimer = 25000;
                } else uiUncontrollableEnergyTimer -= diff;

                if (IsHeroic())
                {
                    if (uiManaDestructionTimer <= diff)
                    {
                        if (!me->IsNonMeleeSpellCasted(false))
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_MANA_DESTRUCTION);
                            uiManaDestructionTimer = 30000;
                        }
                    } else uiManaDestructionTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);

                if (instance)
                    instance->SetData(DATA_CYANIGOSA_EVENT, DONE);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(SAY_SLAY);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_cyanigosaAI(creature);
        }
};

void AddSC_boss_cyanigosa()
{
    new boss_cyanigosa();
}
