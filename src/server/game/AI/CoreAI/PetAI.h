/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_PETAI_H
#define TRINITY_PETAI_H

#include "CreatureAI.h"
#include "Timer.h"
#include "ScriptedCreature.h"

class Creature;
class Spell;

class PetAI : public CreatureAI
{
    public:

        explicit PetAI(Creature* c);
        ~PetAI();

        void UpdateAI(uint32);
        static int Permissible(const Creature*);

        void KilledUnit(Unit* /*victim*/);
        void AttackStart(Unit* target);
        void MovementInform(uint32 moveType, uint32 data);
        void OwnerAttackedBy(Unit* attacker);
        void OwnerAttacked(Unit* target);
        void AttackedBy(Unit* attacker);
        void ReceiveEmote(Player* player, uint32 textEmote);

        // The following aren't used by the PetAI but need to be defined to override
        //  default CreatureAI functions which interfere with the PetAI
        //
        void MoveInLineOfSight(Unit* /*who*/) { } // CreatureAI interferes with returning pets
        void MoveInLineOfSight_Safe(Unit* /*who*/) { } // CreatureAI interferes with returning pets
        void EnterEvadeMode() { } // For fleeing, pets don't use this type of Evade mechanic

        void SpellRequiresMovement(Unit* target, Spell* spell) override;
        void OnPetCommand(CommandStates) override;

    private:
        bool _needToStop(void);
        void _stopAttack(void);
        bool IsTargetReachable(Unit const* target) const;

        void UpdateAllies();

        float GetSpellAttackRange() const;

        TimeTracker i_tracker;
        bool inCombat;
        std::set<uint64> m_AllySet;
        uint32 m_updateAlliesTimer;

        Unit* SelectNextTarget(bool allowAutoSelect) const;
        void HandleReturnMovement();
        void DoAttack(Unit* target, bool chase);
        bool CanAttack(Unit* target);
        void ClearCharmInfoFlags();
        void TryToCastSpell(Unit* target, uint32 spell);

        // Just for more compability with icc
        void ChaseUntilSpellCasted(Unit* target, Spell* spell);
        void ResetDelayedSpellIfNeed();
        bool TryToCastDelayedSpell();
        void RestoreLastActionIfNeed();

        bool m_pureCaster = false;
        AssistBehavior m_assist{ me };

        enum class LastActionType
        {
            Follow,
            Attack,
            Stay,
        };

        struct LastAction
        {
            bool NeedToRestore = false;
            bool MovingToStayPosition = false;
            LastActionType Type = LastActionType::Follow;
            Position StayPosition;
            uint64 AttackingGuid = 0;
        };

        LastAction m_lastAction;
        uint64 m_delayedSpellTarget = 0;
        Spell* m_delayedSpell = nullptr;
};
#endif
