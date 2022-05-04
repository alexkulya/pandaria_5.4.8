////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"

//Spells
enum Spells
{
	//Phase one
	SPELL_TWILIGHT_CHANNEL             = 57797,
	SPELL_TWILIGHT_PORTAL_VISUAL       = 51807,
	//Phase two  
    SPELL_AURA_OF_DREAD                = 41142,
	SPELL_SUNDER_ARMOR                 = 59350,
    SPELL_UNHOLY_POWER                 = 69167,
	SPELL_BURNING_FISTS                = 67333,
	SPELL_PAIN_AND_SUFFERING           = 73790,
    SPELL_FIERY_COMBUSTION             = 74562,
	SPELL_MARK_OF_COMBUSTION           = 74567,
	//Phase three 
	SPELL_HIGH_SECURITY_SHADOW_PRISON  = 45922,
	SPELL_FINGER_OF_DEATH              = 31984,
	SPELL_BERSERK                      = 41924,
};

//Creatures
enum Creatures
{
    NPC_ANCIENT_WISP         = 5000006,
	NPC_TWILIGHT_PORTAL      = 5000007,
};

//Creature sounds
#define	SOUND_ONAGGRO       8595 
#define	SOUND_ONSLAY        8602
#define	SOUND_ONDEATH       8594

//Emotes
#define EMOTE_ONAGGRO      "Assistance will arrive soon, stand tall!" 
#define EMOTE_STRENGTH     "Maximus' strength is increasing!"  
#define EMOTE_FAIL         "The Twilight General begins to cast Finger of Death, we are lost..." 
#define EMOTE_WIN          "We did it! Help is seconds away!"

//Maximus AI:
class boss_maximus : public CreatureScript
{
public:
	boss_maximus() : CreatureScript("boss_maximus"){ }

	CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_maximusAI (creature);
    }

    struct boss_maximusAI : public ScriptedAI
	{
		boss_maximusAI(Creature* creature) : ScriptedAI(creature), summons(me){ }

        uint32 ChannelTwilight_Timer;

		uint32 AuraOfDread_Timer;
        uint32 SunderArmor_Timer;
		uint32 UnholyPower_Timer;
        uint32 BurningFists_Timer;
        uint32 PainAndSuffering_Timer;
		uint32 FieryCombustion_Timer;
      
		uint32 SummonWisp_Timer;
		uint32 WispCount;

        uint32 Enrage_Timer;
		uint32 FingerOfDeath_Timer;

        bool IsChanneling;
        bool Enraged;
        bool BelowTwentyPercent;
        bool HasProtected;

        SummonList summons;

		//When resetting:
        void Reset()
        {
            ChannelTwilight_Timer = 0;

			AuraOfDread_Timer = 2000;
            SunderArmor_Timer = 5000;
			UnholyPower_Timer = 9750;
            BurningFists_Timer = 10000;
            PainAndSuffering_Timer = urand(10000, 17500);
			FieryCombustion_Timer = urand(7500, 15000);

			FingerOfDeath_Timer = 1;
            Enrage_Timer = 300000;

            SummonWisp_Timer = 5000;
			WispCount = 0;

            IsChanneling = false;
            Enraged = false;
            BelowTwentyPercent = false;
            HasProtected = false;
            summons.DespawnAll();

            me->RemoveAllAuras(); 
            me->SetFullHealth();
		}

		//When entering combat:
        void EnterCombat(Unit* who)
		{
		    me->MonsterYell("My powers are renewed!", LANG_UNIVERSAL, me->GetGUID());
            DoPlaySoundToSet(me, SOUND_ONAGGRO);
            me->MonsterTextEmote(EMOTE_ONAGGRO, 0, true);

            me->InterruptSpell(CURRENT_CHANNELED_SPELL);
            me->RemoveAllAuras(); 
            DoZoneInCombat();
            summons.DoZoneInCombat();
        }

		//When summoned creature:
        void JustSummoned(Creature* summoned)
		{
            if (summoned->GetEntry() == NPC_ANCIENT_WISP)
                summoned->AI()->AttackStart(me);
            else
            {
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
		}

		//When despawning summoned creature:
        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
        }

		//When reached home position:
        void JustReachedHome()
        {
            DoCast(me, SPELL_TWILIGHT_CHANNEL);
        }

		//When killed a unit:
	    void KilledUnit(Unit* /*who*/)
		{
		    me->MonsterYell("You are terminated.", LANG_UNIVERSAL, me->GetGUID());
            DoPlaySoundToSet(me, SOUND_ONSLAY);
		}

		//When died:
	    void JustDied(Unit* /*killer*/)
		{
		    me->MonsterYell("I have.. failed...", LANG_UNIVERSAL, me->GetGUID());
            DoPlaySoundToSet(me, SOUND_ONDEATH);

            me->RemoveAllAuras(); 
		}		

		//Stay up to date
        void UpdateAI(const uint32 diff)
        {
			//Channel on Twilight Portal
		    if (ChannelTwilight_Timer <= diff)
			{
			    if (!IsChanneling)
                {
                    DoCast(me, SPELL_TWILIGHT_CHANNEL);
                    IsChanneling = true;
                }
			} else ChannelTwilight_Timer -= diff;             	
		
            if (!UpdateVictim())
                return;

            if (me->HealthBelowPct(20) && !BelowTwentyPercent && !Enraged)
                BelowTwentyPercent = true;

			//When enraged:
            if (Enrage_Timer < diff && !Enraged)
            {
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveIdle();
                me->RemoveAllAuras(); 
                me->MonsterTextEmote(EMOTE_FAIL, 0, true);
                Enraged = true;
            } else Enrage_Timer -= diff;

            if (Enraged)
            {
                DoCast(me, SPELL_BERSERK);

				//Finger of Death timer
                if (FingerOfDeath_Timer <= diff)
                {
                    if (Unit *Target = SelectTarget (SELECT_TARGET_RANDOM, 0))
			        DoCast (Target, SPELL_FINGER_OF_DEATH);
                    FingerOfDeath_Timer = 1000;
                } else FingerOfDeath_Timer -= diff;
                return; 
			}

			//When below 20% health:
            if (BelowTwentyPercent && !Enraged)
            {
                if (!HasProtected)
                {
                    me->RemoveAllAuras(); 
	                DoCast (me, SPELL_HIGH_SECURITY_SHADOW_PRISON);

                    me->MonsterTextEmote(EMOTE_WIN, 0, true);
                    HasProtected = true;
                }

				//Summon Wisp timer
                if (SummonWisp_Timer <= diff)
                {
                    DoSpawnCreature(NPC_ANCIENT_WISP, float(rand()%40), float(rand()%40), 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
					SummonWisp_Timer = 2500;
                    ++WispCount;
                } else SummonWisp_Timer -= diff;

                if (WispCount >= 10)
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);		    		
				   return;
			}

		        //Aura of Dread Timer
		        if (AuraOfDread_Timer <= diff)
		        {
			        DoCast (me->getVictim(), SPELL_AURA_OF_DREAD);
			        AuraOfDread_Timer = 2500;
		        } else AuraOfDread_Timer -= diff;

		        //Sunder Armor Timer
		        if (SunderArmor_Timer <= diff)
		        {
			        DoCast (me->getVictim(), SPELL_SUNDER_ARMOR);
			        SunderArmor_Timer = 15000;
                } else SunderArmor_Timer -= diff;

		        //Burning Fists Timer
			    if (BurningFists_Timer <= diff)
		        {
			        DoCast (me->getVictim(), SPELL_BURNING_FISTS);
			        BurningFists_Timer = 25001;
                } else BurningFists_Timer -= diff;

		    	//Unholy Power Timer
		     	if (UnholyPower_Timer <= diff)
		        {
		        	DoCast (me->getVictim(), SPELL_UNHOLY_POWER);
		        	UnholyPower_Timer = 25000;
		            me->MonsterTextEmote(EMOTE_STRENGTH, 0, true);
                } else UnholyPower_Timer -= diff;

		        //Pain and Suffering Timer
		        if (PainAndSuffering_Timer <= diff)
		        {
                    if (Unit *Target = SelectTarget (SELECT_TARGET_RANDOM, 0))
			        DoCast (Target, SPELL_PAIN_AND_SUFFERING);
			        PainAndSuffering_Timer = urand(10000, 17500);
		        } else PainAndSuffering_Timer -= diff;
 
			    //Fiery Combustion Timer
		        if (FieryCombustion_Timer <= diff)
		        {
                    if (Unit *Target = SelectTarget (SELECT_TARGET_RANDOM, 0))
			        DoCast (Target, SPELL_FIERY_COMBUSTION);
			        FieryCombustion_Timer = urand(12500, 20000);      
		        } else FieryCombustion_Timer -= diff;			

            DoMeleeAttackIfReady();
        }
    };
};

//Twilight Portal AI:
class npc_twilight_portal : public CreatureScript
{
public:
    npc_twilight_portal() : CreatureScript("npc_twilight_portal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_twilight_portalAI(creature);
	}

    struct npc_twilight_portalAI : public Scripted_NoMovementAI
    {
		npc_twilight_portalAI(Creature* creature) : Scripted_NoMovementAI(creature){ }

		//When resetting:
        void Reset()
        {
			DoCast (me, SPELL_TWILIGHT_PORTAL_VISUAL);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

		//Stay up to date
        void UpdateAI(const uint32 diff)
        {
			if (!UpdateVictim())
				return;
        }
	};
};

//Ancient Wisp AI:
class npc_ancient_wisp : public CreatureScript
{
public:
    npc_ancient_wisp() : CreatureScript("npc_ancient_wisp") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ancient_wispAI(creature);
	}

    struct npc_ancient_wispAI : public ScriptedAI
    {
        npc_ancient_wispAI(Creature* creature) : ScriptedAI(creature)
        {
            MaximusGUID = 0;
        }

        uint64 MaximusGUID;
        uint32 Check_Timer;
		uint64 TargetGUID;

        uint32 ChangeTarget_Timer;

		//When resetting:
        void Reset()
        {
            Check_Timer = 1000;
            ChangeTarget_Timer = 7500;

            TargetGUID = 0;
        }

		//When moving in line of sight:
        void MoveInLineOfSight(Unit* who)
        {
            if (!TargetGUID && who->GetTypeId() == TYPEID_PLAYER)
                TargetGUID = who->GetGUID();
        }

        void EnterCombat(Unit* /*who*/)
		{ 
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
		}

		//When taking damage:
        void DamageTaken(Unit* /*done_by*/, uint32 &damage) { damage = 0; }

		//When reached waypoint:
        void WaypointReached(uint32 /*i*/){ }

		//Stay up to date
        void UpdateAI(const uint32 diff)
        {
			//Change target timer
            if (ChangeTarget_Timer <= diff)
            {
                if (Unit* temp = Unit::GetUnit(*me, TargetGUID))
                {
                    me->GetMotionMaster()->MoveFollow(temp, 0.0f, 0.0f);
                    TargetGUID = 0;
                }
                else
                {
                    Position pos;
                    me->GetRandomNearPosition(pos, 40);
                    me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                }

                ChangeTarget_Timer = 5000;
            } else ChangeTarget_Timer -= diff;
        }
	};
};

void AddSC_boss_maximus()
{
    new boss_maximus();
	new npc_ancient_wisp();
	new npc_twilight_portal();
}