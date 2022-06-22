#include "grim_batol.h"
#include "NewScriptPCH.h"


//todo: щит ночных кошмаров, аое, евент с адами

enum ScriptTexts
{
    SAY_AGGRO    = 0,
    SAY_KILL    = 1,
    SAY_DEATH    = 2,
    SAY_GALE    = 3,
    SAY_ADDS    = 4,
};

enum Spells
{
    SPELL_ENFEEBLING_BLOW            = 75789,
    SPELL_ENFEEBLING_BLOW_H            = 91091,
    SPELL_BINDING_SHADOWS            = 79466,
    SPELL_BINDING_SHADOWS_H            = 91081, 
    SPELL_BINDING_SHADOWS_AURA        = 75861,
    SPELL_BINDING_SHADOWS_AURA_H    = 91079,
    SPELL_SIPHON_ESSENSE            = 75755,
    SPELL_SIPHON_ESSENSE_H            = 91028,
    SPELL_UMBRAL_MENDING            = 75763,
    SPELL_UMBRAL_MENDING_H            = 91040,
    SPELL_SHADOW_GALE_SPEED_TRIGGER    = 75675,
    SPELL_SHADOW_GALE_SPEED            = 75694,
    SPELL_SHADOW_GALE                = 75664,
    SPELL_SHADOW_GALE_H                = 91086,
    SPELL_SHADOW_GALE_DMG            = 75692,
    SPELL_SHADOW_GALE_DMG_H            = 91087,
    SPELL_TWILIGHT_CORRUPTION        = 75520,
    SPELL_TWILIGHT_CORRUPTION_H        = 91049,
    SPELL_TWILIGHT_CORRUPTION_DMG    = 75566,
    SPELL_SUMMON_TWILIGHT_HATCHLING = 91058,
    SPELL_SPAWN_FACELESS            = 75704,
    SPELL_SPAWN_FACELESS_H            = 91072,
    SPELL_TWILIGHT_PORTAL_VISUAL    = 95716,
    SPELL_TWILIGHT_BLAST_TRIGGER    = 76192,
    SPELL_TWILIGHT_BLAST_DMG        = 76194,
    SPELL_TWILIGHT_BLAST_DMG_H        = 91042,
    SPELL_SHIELD_OF_NIGHTMARES        = 75809,
};

enum Adds
{
    NPC_FACELESS_CORRUPTOR        = 40600,
    NPC_FACELESS_CORRUPTOR_H    = 48844,
    NPC_FACELESS_PORTAL_STALKER = 44314,
    NPC_ALEXSTRASZA_EGG            = 40486,
    NPC_TWILIGHT_HATCHLING        = 39388,
    NPC_SHADOW_GALE_STALKER        = 40567,
};

enum Events
{
    EVENT_ENFEEBLING_BLOW            = 1,
    EVENT_BINDING_SHADOWS            = 2,
    EVENT_ADDS                        = 3,
    EVENT_SIPHON_ESSENSE            = 4,
    EVENT_UMBRAL_MENDING            = 5,
    EVENT_REMOVE_TWILIGHT_PORTAL    = 6,
    EVENT_SHADOW_GALE                = 7,
    EVENT_TWILIGHT_CORRUPTION        = 8,
    EVENT_CORRUPTOR_MOVE            = 9,
    EVENT_SHIELD_OF_NIGHTMARES        = 10,
};

enum Points
{
    POINT_SHADOWGALE    = 1001,
    POINT_EGG            = 1002,
};

const Position erudaxportalPos = {-641.515f, -827.8f, 235.5f, 3.069f};
const Position neareggPos[2] = 
{
    {-719.67f, -839.64f, 232.43f, 0.0f},
    //{-731.72f, -787.40f, 232.47f, 2.25f},
    {-730.63f, -864.46f, 232.44f, 4.71f},
};
const Position shadowgalePos[3] = 
{
    {-745.07f, -845.16f, 232.41f, 0.0f},
    {-724.05f, -823.47f, 232.41f, 0.0f},
    {-741.81f, -819.44f, 232.41f, 0.0f},
};
const Position eggPos[23]    =
{
    {-720.21f, -875.28f, 232.56f, 4.59f},
    {-728.52f, -875.78f, 232.55f, 3.33f},
    {-736.79f, -877.43f, 232.58f, 3.33f},
    {-748.38f, -876.34f, 233.23f, 2.87f},
    {-757.47f, -873.80f, 233.23f, 2.87f},
    {-749.23f, -871.13f, 233.23f, 0.30f},
    {-740.28f, -870.06f, 232.58f, 6.17f},
    {-731.70f, -868.19f, 232.47f, 0.00f},
    {-752.09f, -860.58f, 232.54f, 3.13f},
    {-747.30f, -779.60f, 233.23f, 1.92f},
    {-740.44f, -778.07f, 233.23f, 0.22f},
    {-729.57f, -778.52f, 232.57f, 0.11f},
    {-719.22f, -770.13f, 233.44f, 0.72f},
    {-722.09f, -780.99f, 232.55f, 4.45f},
    {-735.99f, -786.08f, 232.57f, 3.05f},
    {-751.92f, -788.38f, 233.23f, 3.33f},
    {-745.56f, -785.41f, 233.23f, 0.43f},
    {-757.08f, -780.37f, 233.23f, 2.68f},
    {-746.64f, -770.96f, 233.23f, 0.95f},
    {-731.53f, -770.02f, 236.14f, 0.10f},
    {-730.15f, -885.09f, 235.96f, 5.93f},
    {-717.82f, -887.81f, 233.95f, 6.05f},
    {-751.01f, -886.38f, 234.87f, 3.27f},
};

class boss_erudax : public CreatureScript
{
    public:
        boss_erudax() : CreatureScript("boss_erudax") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_erudaxAI(creature);
        }

        struct boss_erudaxAI : public ScriptedAI
        {
            boss_erudaxAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            SummonList summons;
            Creature* FacelessPortalStalker;
            Creature* ShadowGaleTrigger;

            void Reset()
            {
                summons.DespawnAll();
                for (uint8 i = 0; i < 13; i++)
                    me->SummonCreature(NPC_ALEXSTRASZA_EGG, eggPos[i]);
                events.Reset();
                if (pInstance)
                    pInstance->SetData(DATA_ERUDAX, NOT_STARTED);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                if (summon->GetEntry() == NPC_FACELESS_CORRUPTOR ||
                    summon->GetEntry() == NPC_FACELESS_CORRUPTOR_H)
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        summon->AI()->AttackStart(target);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
            }

            void EnterCombat(Unit* who)
            {
                Talk(SAY_AGGRO);
                FacelessPortalStalker = me->SummonCreature(NPC_FACELESS_PORTAL_STALKER, erudaxportalPos,TEMPSUMMON_MANUAL_DESPAWN);
                events.ScheduleEvent(EVENT_SHADOW_GALE, urand(25000, 26000));
                events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, urand(4000, 6000));
                events.ScheduleEvent(EVENT_BINDING_SHADOWS, urand(9000, 11000));
                if (pInstance)
                    pInstance->SetData(DATA_ERUDAX, IN_PROGRESS);
            }
            
            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);
                summons.DespawnAll();
                if (pInstance)
                    pInstance->SetData(DATA_ERUDAX, DONE);
            }

            void KilledUnit(Unit* victim)
            {
                Talk(SAY_KILL);                
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->GetDistance(me->GetHomePosition()) > 100.0f)
                {
                    EnterEvadeMode();
                    return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_SHADOW_GALE:
                        Talk(SAY_GALE);
                        if (ShadowGaleTrigger = me->SummonCreature(NPC_SHADOW_GALE_STALKER, shadowgalePos[urand(0, 2)]))
                            ShadowGaleTrigger->CastSpell(ShadowGaleTrigger, SPELL_SHADOW_GALE_SPEED_TRIGGER, false);
                        //132 error
                        //DoCast(me, SPELL_SHADOW_GALE);
                        events.ScheduleEvent(EVENT_ADDS, 16500); 
                        break;
                    case EVENT_REMOVE_TWILIGHT_PORTAL:
                        if (FacelessPortalStalker)
                            FacelessPortalStalker->RemoveAurasDueToSpell(SPELL_TWILIGHT_PORTAL_VISUAL);
                        break;
                    case EVENT_ADDS:
                        if (ShadowGaleTrigger)
                            ShadowGaleTrigger->DespawnOrUnsummon();
                        Talk(SAY_ADDS);
                        if (FacelessPortalStalker)
                        {
                            FacelessPortalStalker->CastSpell(FacelessPortalStalker, SPELL_TWILIGHT_PORTAL_VISUAL, true);
                            me->CastSpell(FacelessPortalStalker, SPELL_SPAWN_FACELESS, true);
                        }
                        events.ScheduleEvent(EVENT_SHIELD_OF_NIGHTMARES, urand(4000, 7000));
                        events.ScheduleEvent(EVENT_REMOVE_TWILIGHT_PORTAL, 7000);
                        events.ScheduleEvent(EVENT_SHADOW_GALE, urand(40000,44000));
                        break;
                    case EVENT_ENFEEBLING_BLOW:
                        DoCast(me->getVictim(), SPELL_ENFEEBLING_BLOW);
                        events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, urand(20000, 30000));
                        break;
                    case EVENT_BINDING_SHADOWS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, DUNGEON_MODE(SPELL_BINDING_SHADOWS, SPELL_BINDING_SHADOWS_H));
                        events.ScheduleEvent(EVENT_BINDING_SHADOWS, urand(20000, 30000));
                        break;
                    case EVENT_SHIELD_OF_NIGHTMARES:
                        DoCast(me, SPELL_SHIELD_OF_NIGHTMARES);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class npc_erudax_faceless_corruptor : public CreatureScript
{
    public:

        npc_erudax_faceless_corruptor() : CreatureScript("npc_erudax_faceless_corruptor"){}

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_erudax_faceless_corruptorAI(pCreature);
        }

        struct npc_erudax_faceless_corruptorAI : public ScriptedAI
        {
            npc_erudax_faceless_corruptorAI(Creature* creature) : ScriptedAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                pInstance = creature->GetInstanceScript();
            }
            
            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
            }

            void EnterCombat(Unit* attacker)
            {
                events.ScheduleEvent(EVENT_UMBRAL_MENDING, urand(15000, 20000));
                events.ScheduleEvent(EVENT_SIPHON_ESSENSE, urand(5000, 7000));
            }

            void JustDied(Unit* killer)
            {
                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 diff)
            {
                if (!pInstance || !UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_UMBRAL_MENDING:
                        if (Creature* erudax = Unit::GetCreature(*me, pInstance->GetData64(DATA_ERUDAX)))
                            DoCast(erudax, SPELL_UMBRAL_MENDING);
                        events.ScheduleEvent(EVENT_UMBRAL_MENDING, urand(15000, 20000));
                        break;
                    case EVENT_SIPHON_ESSENSE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_SIPHON_ESSENSE);
                        events.ScheduleEvent(EVENT_SIPHON_ESSENSE, urand(7000, 10000));
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class npc_alexstrasza_egg : public CreatureScript
{
public:
    npc_alexstrasza_egg() : CreatureScript("npc_alexstrasza_egg") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_alexstrasza_eggAI (creature);
    }

    struct npc_alexstrasza_eggAI : public Scripted_NoMovementAI
    {
        npc_alexstrasza_eggAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void JustDied(Unit* killer)
        {
            DoCast(me, SPELL_SUMMON_TWILIGHT_HATCHLING, true);
        }

        void JustSummoned(Creature* summon)
        {
            if (!pInstance)
                return;

            if (summon->GetEntry() == NPC_TWILIGHT_HATCHLING)
                if (Creature* _erudax = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_ERUDAX)))
                    if (Unit* target = _erudax->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        summon->AI()->AttackStart(target);
        }
    };
};

class npc_shadow_gale_stalker : public CreatureScript
{
public:
    npc_shadow_gale_stalker() : CreatureScript("npc_shadow_gale_stalker") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_shadow_gale_stalkerAI (creature);
    }

    struct npc_shadow_gale_stalkerAI : public Scripted_NoMovementAI
    {
        npc_shadow_gale_stalkerAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }


        void Reset()
        {
        }
    };
};

class npc_erudax_twilight_hatchling : public CreatureScript
{
public:
    npc_erudax_twilight_hatchling() : CreatureScript("npc_erudax_twilight_hatchling") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_erudax_twilight_hatchlingAI (creature);
    }

    struct npc_erudax_twilight_hatchlingAI : public Scripted_NoMovementAI
    {
        npc_erudax_twilight_hatchlingAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            SetCombatMovement(false);
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset()
        {
            me->SetCanFly(true);
        }

        void JustDied(Unit* killer)
        {
            me->DespawnOrUnsummon();
        }

        void IsSummonedBy(Unit* owner)
        {
            DoCast(me, SPELL_TWILIGHT_BLAST_TRIGGER);
        }

        void UpdateAI(uint32 diff)
        {
            if (!pInstance)
                return;

            if (pInstance->GetBossState(DATA_ERUDAX) != IN_PROGRESS)
                me->DespawnOrUnsummon();
        }
    };
};

class spell_erudax_shadow_gale: public SpellScriptLoader
{
    public:
        spell_erudax_shadow_gale() : SpellScriptLoader("spell_erudax_shadow_gale") { }


        class spell_erudax_shadow_gale_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_shadow_gale_SpellScript);


            void HandleScript()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (GetHitUnit()->FindNearestCreature(NPC_SHADOW_GALE_STALKER, 5.0f))
                    SetHitDamage(0);
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_erudax_shadow_gale_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_erudax_shadow_gale_SpellScript();
        }
};

void AddSC_boss_erudax()
{
    new boss_erudax();
    new npc_erudax_faceless_corruptor();
    new npc_alexstrasza_egg();
    new npc_shadow_gale_stalker();
    new npc_erudax_twilight_hatchling();
    new spell_erudax_shadow_gale();
}