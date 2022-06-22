/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "SpellMgr.h"
#include "scarlet_monastery.h"
#include "LFGMgr.h"
#include "Group.h"

//this texts are already used by 3975 and 3976
enum Says
{
    SAY_ENTRANCE                = -1189001,
    SAY_REJOINED                = -1189002,
    SAY_LOST_HEAD               = -1189003,
    SAY_CONFLAGRATION           = -1189004,
    SAY_SPROUTING_PUMPKINS      = -1189005,
    SAY_PLAYER_DEATH            = -1189006,
    SAY_DEATH                   = -1189007
};

uint32 RandomLaugh[] = {11965, 11975, 11976};

enum Entry
{
    HH_MOUNTED                  = 23682,
    HH_DISMOUNTED               = 23800,  // unhorsed?? wtf type of engrish was that?
    HEAD                        = 23775,
    PULSING_PUMPKIN             = 23694,
    PUMPKIN_FIEND               = 23545,
    HELPER                      = 23686,
    WISP_INVIS                  = 24034
};

enum Spells
{
    SPELL_CLEAVE                = 42587,
    SPELL_CONFLAGRATION         = 42380,       //Phase 2, can't find real spell(Dim Fire?)
 // SPELL_CONFL_SPEED           = 22587,       //8% increase speed, value 22587 from SPELL_CONFLAGRATION mains that spell?
    SPELL_SUMMON_PUMPKIN        = 42394,

    SPELL_WHIRLWIND             = 43116,
    SPELL_IMMUNE                = 42556,
    SPELL_BODY_REGEN            = 42403,
    SPELL_CONFUSE               = 43105,

    SPELL_FLYING_HEAD           = 42399,       //visual flying head
    SPELL_HEAD                  = 42413,       //visual buff, "head"
    SPELL_HEAD_IS_DEAD          = 42428,       //at killing head, Phase 3

    SPELL_PUMPKIN_AURA          = 42280,
    SPELL_PUMPKIN_AURA_GREEN    = 42294,
    SPELL_SQUASH_SOUL           = 42514,
    SPELL_SPROUTING             = 42281,
    SPELL_SPROUT_BODY           = 42285,

    //Effects
    SPELL_RHYME_BIG             = 42909,
 // SPELL_RHYME_SMALL           = 42910,
    SPELL_HEAD_SPEAKS           = 43129,
    SPELL_HEAD_LANDS            = 42400,
    SPELL_BODY_FLAME            = 42074,
    SPELL_HEAD_FLAME            = 42971,
 // SPELL_ENRAGE_VISUAL         = 42438,       // he uses this spell?
    SPELL_WISP_BLUE             = 42821,
    SPELL_WISP_FLIGHT_PORT      = 42818,
 // SPELL_WISP_INVIS            = 42823,
    SPELL_SMOKE                 = 42355,
    SPELL_DEATH                 = 42566       //not correct spell
};

struct Locations
{
    float x, y, z;
};

static Locations FlightPoint[]=
{
    {1082.84f, 607.62f, -2.23f},
    {1093.84f, 608.62f, -0.63f},
    {1112.84f, 608.42f, 5.77f},
    {1132.14f, 609.22f, 5.77f},
    {1152.84f, 611.62f, 22.97f},
    {1167.64f, 614.82f, 30.17f},
    {1180.84f, 619.22f, 36.07f},
    {1190.14f, 625.62f, 39.77f},
    {1195.14f, 636.42f, 42.07f},
    {1192.84f, 648.92f, 43.57f},
    {1183.64f, 661.02f, 44.47f},
    {1172.84f, 668.52f, 44.47f},
    {1153.14f, 673.02f, 43.67f},
    {1129.84f, 673.92f, 40.77f},
    {1110.84f, 671.72f, 35.87f},
    {1099.34f, 666.82f, 30.67f},
    {1094.04f, 662.32f, 26.97f},
    {1090.24f, 655.02f, 22.07f},
    {1087.94f, 648.32f, 16.97f},
    {1086.64f, 639.82f, 9.37f},
    {1086.84f, 628.62f, -0.12f},//{1758.00f, 1367.00f, 19.51f}
};

static Locations Spawn[]=
{
    {1105.11f, 610.36f, -0.43f},    //spawn point for pumpkin shrine mob
    {1094.12f, 609.08f, -2.08f}     //spawn point for smoke
};

static const char* Text[]=
{
    "Horseman rise...",
    "Your time is nigh...",
    "You felt death once...",
    "Now, know demise!"
};

#define EMOTE_LAUGHS    "Headless Horseman laughs"  // needs assigned to db.

class mob_wisp_invis : public CreatureScript
{
public:
    mob_wisp_invis() : CreatureScript("mob_wisp_invis") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wisp_invisAI (creature);
    }

    struct mob_wisp_invisAI : public ScriptedAI
    {
        mob_wisp_invisAI(Creature* creature) : ScriptedAI(creature)
        {
            Creaturetype = delay = spell = spell2 = 0;
        }

        uint32 Creaturetype;
        uint32 delay;
        uint32 spell;
        uint32 spell2;
        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void SetType(uint32 _type)
        {
            switch (Creaturetype = _type)
            {
                case 1:
                    spell = SPELL_PUMPKIN_AURA_GREEN;
                    break;
                case 2:
                    delay = 15000;
                    spell = SPELL_BODY_FLAME;
                    spell2 = SPELL_DEATH;
                    break;
                case 3:
                    delay = 15000;
                    spell = SPELL_SMOKE;
                    break;
                case 4:
                    delay = 7000;
                    spell2 = SPELL_WISP_BLUE;
                    break;
            }
            if (spell)
                DoCast(me, spell);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_WISP_FLIGHT_PORT && Creaturetype == 4)
                me->SetDisplayId(2027);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who || Creaturetype != 1 || !who->isTargetableForAttack())
                return;

            if (me->IsWithinDist(who, 0.1f, false) && !who->HasAura(SPELL_SQUASH_SOUL))
                DoCast(who, SPELL_SQUASH_SOUL);
        }

        void UpdateAI(uint32 diff)
        {
            if (delay)
            {
                if (delay <= diff)
                {
                    me->RemoveAurasDueToSpell(SPELL_SMOKE);
                    if (spell2)
                        DoCast(me, spell2);
                    delay = 0;
                } else delay -= diff;
            }
        }
    };
};

class mob_head : public CreatureScript
{
public:
    mob_head() : CreatureScript("mob_head") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_headAI (creature);
    }

    struct mob_headAI : public ScriptedAI
    {
        mob_headAI(Creature* creature) : ScriptedAI(creature) {}

        uint64 bodyGUID;

        uint32 Phase;
        uint32 laugh;
        uint32 wait;

        bool withbody;
        bool die;

        void Reset()
        {
            Phase = 0;
            bodyGUID = 0;
            die = false;
            withbody = true;
            wait = 1000;
            laugh = urand(15000, 30000);
        }

        void EnterCombat(Unit* /*who*/) {}
        void SaySound(int32 textEntry, Unit* target = 0)
        {
            DoScriptText(textEntry, me, target);
            //DoCast(me, SPELL_HEAD_SPEAKS, true);
            Creature* speaker = DoSpawnCreature(HELPER, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 1000);
            if (speaker)
                speaker->CastSpell(speaker, SPELL_HEAD_SPEAKS, false);
            laugh += 3000;
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (withbody)
                return;

            switch (Phase)
            {
                case 1:
                    if (me->HealthBelowPctDamaged(67, damage))
                        Disappear();
                    break;
                case 2:
                    if (me->HealthBelowPctDamaged(34, damage))
                        Disappear();
                    break;
                case 3:
                    if (damage >= me->GetHealth())
                    {
                        die = true;
                        withbody = true;
                        wait = 300;
                        damage = me->GetHealth() - me->CountPctFromMaxHealth(1);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->StopMoving();
                        //me->GetMotionMaster()->MoveIdle();
                        DoCast(me, SPELL_HEAD_IS_DEAD);
                    }
                    break;
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell)
        {
            if (!withbody)
                return;

            if (spell->Id == SPELL_FLYING_HEAD)
            {
                if (Phase < 3)
                    ++Phase;
                else
                    Phase = 3;

                withbody = false;
                if (!bodyGUID)
                    bodyGUID = caster->GetGUID();
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_HEAD_LANDS, true);
                DoCast(me, SPELL_HEAD, false);
                SaySound(SAY_LOST_HEAD);
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveFleeing(caster->getVictim());
            }
        }

        void Disappear();
        void UpdateAI(uint32 diff)
        {
            if (!withbody)
            {
                if (wait <= diff)
                {
                    wait = 1000;
                    if (!me->getVictim())
                        return;
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveFleeing(me->getVictim());
                }
                else wait -= diff;

                if (laugh <= diff)
                {
                    laugh = urand(15000, 30000);
                    DoPlaySoundToSet(me, RandomLaugh[urand(0, 2)]);
                    //DoCast(me, SPELL_HEAD_SPEAKS, true); //this spell remove buff "head"
                    Creature* speaker = DoSpawnCreature(HELPER, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 1000);
                    if (speaker)
                        speaker->CastSpell(speaker, SPELL_HEAD_SPEAKS, false);
                    me->MonsterTextEmote(EMOTE_LAUGHS, 0);
                }
                else laugh -= diff;
            }
            else
            {
                if (die)
                {
                    if (wait <= diff)
                    {
                        die = false;
                        if (Unit* body = Unit::GetUnit(*me, bodyGUID))
                            body->Kill(body);
                        me->Kill(me);
                    }
                    else wait -= diff;
                }
            }
        }
    };
};

class boss_headless_horseman : public CreatureScript
{
public:
    boss_headless_horseman() : CreatureScript("boss_headless_horseman") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_headless_horsemanAI (creature);
    }

    struct boss_headless_horsemanAI : public ScriptedAI
    {
        boss_headless_horsemanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint64 headGUID;
        uint64 PlayerGUID;

        uint32 Phase;
        uint32 id;
        uint32 count;
        uint32 say_timer;

        uint32 conflagrate;
        uint32 summonadds;
        uint32 cleave;
        uint32 regen;
        uint32 whirlwind;
        uint32 laugh;
        uint32 burn;

        bool withhead;
        bool returned;
        bool IsFlying;
        bool wp_reached;
        bool burned;

        void Reset()
        {
            Phase = 1;
            conflagrate = 15000;
            summonadds = 15000;
            laugh = urand(16000, 20000);
            cleave = 2000;
            regen = 1000;
            burn = 6000;
            count = 0;
            say_timer = 3000;

            withhead = true;
            returned = true;
            burned = false;
            IsFlying = false;
            DoCast(me, SPELL_HEAD);
            if (headGUID)
            {
                if (Creature* Head = Unit::GetCreature((*me), headGUID))
                    Head->DisappearAndDie();

                headGUID = 0;
            }

            //if (instance)
            //    instance->SetData(DATA_HORSEMAN_EVENT, NOT_STARTED);
        }

        void FlyMode()
        {
            me->SetVisible(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            me->SetSpeed(MOVE_WALK, 5.0f, true);
            wp_reached = false;
            count = 0;
            say_timer = 3000;
            id = 0;
            Phase = 0;
        }

        void MovementInform(uint32 type, uint32 i)
        {
            if (type != POINT_MOTION_TYPE || !IsFlying || i != id)
                return;

            wp_reached = true;

            switch (id)
            {
                case 0:
                    me->SetVisible(true);
                    break;
                case 1:
                {
                    if (Creature* smoke = me->SummonCreature(HELPER, Spawn[1].x, Spawn[1].y, Spawn[1].z, 0, TEMPSUMMON_TIMED_DESPAWN, 20000))
                        CAST_AI(mob_wisp_invis::mob_wisp_invisAI, smoke->AI())->SetType(3);
                    DoCast(me, SPELL_RHYME_BIG);
                    break;
                }
                case 6:
                    if (instance)
                        instance->SetData(GAMEOBJECT_PUMPKIN_SHRINE, 0);   //hide gameobject
                    break;
                case 19:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                    break;
                case 20:
                {
                    Phase = 1;
                    IsFlying = false;
                    wp_reached = false;
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    SaySound(SAY_ENTRANCE);
                    if (Unit* player = Unit::GetUnit(*me, PlayerGUID))
                        DoStartMovement(player);
                    break;
                }
            }
            ++id;
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance)
                instance->SetData(DATA_HORSEMAN_EVENT, IN_PROGRESS);
            DoZoneInCombat();
        }

        void AttackStart(Unit* who)
        {
            ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (withhead && Phase != 0)
                ScriptedAI::MoveInLineOfSight(who);
        }

        void KilledUnit(Unit* player)
        {
            if (player->GetTypeId() == TYPEID_PLAYER)
            {
                if (withhead)
                    SaySound(SAY_PLAYER_DEATH);
                //maybe possible when player dies from conflagration
                else if (Creature* Head = Unit::GetCreature((*me), headGUID))
                    CAST_AI(mob_head::mob_headAI, Head->AI())->SaySound(SAY_PLAYER_DEATH);
            }
        }

        void SaySound(int32 textEntry, Unit* target = 0)
        {
            DoScriptText(textEntry, me, target);
            laugh += 4000;
        }

        Player* SelectRandomPlayer(float range = 0.0f, bool checkLoS = true)
        {
            Map* map = me->GetMap();
            if (!map->IsDungeon())
                return NULL;

            Map::PlayerList const &PlayerList = map->GetPlayers();
            if (PlayerList.isEmpty())
                return NULL;

            std::list<Player*> temp;
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if ((me->IsWithinLOSInMap(i->getSource()) || !checkLoS) && me->getVictim() != i->getSource() &&
                    me->IsWithinDistInMap(i->getSource(), range) && i->getSource()->IsAlive())
                    temp.push_back(i->getSource());

            if (!temp.empty())
            {
                std::list<Player*>::const_iterator j = temp.begin();
                advance(j, rand()%temp.size());
                return (*j);
            }
            return NULL;
        }

        void SpellHitTarget(Unit* unit, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_CONFLAGRATION && unit->HasAura(SPELL_CONFLAGRATION))
                SaySound(SAY_CONFLAGRATION, unit);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->StopMoving();
            //me->GetMotionMaster()->MoveIdle();
            SaySound(SAY_DEATH);
            if (Creature* flame = DoSpawnCreature(HELPER, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 60000))
                flame->CastSpell(flame, SPELL_BODY_FLAME, false);
            if (Creature* wisp = DoSpawnCreature(WISP_INVIS, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 60000))
                CAST_AI(mob_wisp_invis::mob_wisp_invisAI, wisp->AI())->SetType(4);
            if (instance)
                instance->SetData(DATA_HORSEMAN_EVENT, DONE);

            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            if (!players.isEmpty() && players.begin()->getSource() && players.begin()->getSource()->GetGroup())
                sLFGMgr->FinishDungeon(players.begin()->getSource()->GetGroup()->GetGUID(), 285);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell)
        {
            if (withhead)
                return;

            if (spell->Id == SPELL_FLYING_HEAD)
            {
                if (Phase < 3)
                    ++Phase;
                else
                    Phase = 3;
                withhead = true;
                me->RemoveAllAuras();
                me->SetName("Headless Horseman");
                me->SetFullHealth();
                SaySound(SAY_REJOINED);
                DoCast(me, SPELL_HEAD);
                caster->GetMotionMaster()->Clear(false);
                caster->GetMotionMaster()->MoveFollow(me, 6, float(urand(0, 5)));
                //DoResetThreat();//not sure if need
                std::list<HostileReference*>::const_iterator itr;
                for (itr = caster->getThreatManager().getThreatList().begin(); itr != caster->getThreatManager().getThreatList().end(); ++itr)
                {
                    Unit* unit = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                    if (unit && unit->IsAlive() && unit != caster)
                        me->AddThreat(unit, caster->getThreatManager().getThreat(unit));
                }
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (damage >= me->GetHealth() && withhead)
            {
                withhead = false;
                returned = false;
                damage = me->GetHealth() - me->CountPctFromMaxHealth(1);
                me->RemoveAllAuras();
                me->SetName("Headless Horseman, Unhorsed");

                if (!headGUID)
                    headGUID = DoSpawnCreature(HEAD, float(rand()%6), float(rand()%6), 0, 0, TEMPSUMMON_DEAD_DESPAWN, 0)->GetGUID();

                Unit* Head = Unit::GetUnit(*me, headGUID);
                if (Head && Head->IsAlive())
                {
                    Head->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    //Head->CastSpell(Head, SPELL_HEAD_INVIS, false);
                    me->InterruptNonMeleeSpells(false);
                    DoCast(me, SPELL_IMMUNE, true);
                    DoCast(me, SPELL_BODY_REGEN, true);
                    DoCast(Head, SPELL_FLYING_HEAD, true);
                    DoCast(me, SPELL_CONFUSE, false);                     //test
                    whirlwind = urand(4000, 8000);
                    regen = 0;
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (withhead)
            {
                switch (Phase)
                {
                    case 0:
                    {
                        if (!IsFlying)
                        {
                            if (say_timer <= diff)
                            {
                                say_timer = 3000;
                                Player* player = SelectRandomPlayer(100.0f, false);
                                if (count < 3)
                                {
                                    if (player)
                                        player->Say(Text[count], 0);
                                }
                                else
                                {
                                    DoCast(me, SPELL_RHYME_BIG);
                                    if (player)
                                    {
                                        player->Say(Text[count], 0);
                                        player->HandleEmoteCommand(ANIM_EMOTE_SHOUT);
                                    }
                                    wp_reached = true;
                                    IsFlying = true;
                                    count = 0;
                                    break;
                                }
                                ++count;
                            }
                            else say_timer -= diff;
                        }
                        else
                        {
                            if (wp_reached)
                            {
                                wp_reached = false;
                                me->GetMotionMaster()->Clear(false);
                                me->GetMotionMaster()->MovePoint(id, FlightPoint[id].x, FlightPoint[id].y, FlightPoint[id].z);
                            }
                        }
                    }
                    break;
                    case 1:
                        if (burned)
                            break;
                        if (burn <= diff)
                        {
                            if (Creature* flame = me->SummonCreature(HELPER, Spawn[0].x, Spawn[0].y, Spawn[0].z, 0, TEMPSUMMON_TIMED_DESPAWN, 17000))
                                CAST_AI(mob_wisp_invis::mob_wisp_invisAI, flame->AI())->SetType(2);
                            burned = true;
                        }
                        else burn -= diff;
                        break;
                    case 2:
                        if (conflagrate <= diff)
                        {
                            if (Unit* player = SelectRandomPlayer(30.0f))
                                DoCast(player, SPELL_CONFLAGRATION, false);
                            conflagrate = urand(10000, 16000);
                        }
                        else conflagrate -= diff;
                        break;
                    case 3:
                        if (summonadds <= diff)
                        {
                            me->InterruptNonMeleeSpells(false);
                            DoCast(me, SPELL_SUMMON_PUMPKIN);
                            SaySound(SAY_SPROUTING_PUMPKINS);
                            summonadds = urand(25000, 35000);
                        }
                        else summonadds -= diff;
                        break;
                }

                if (laugh <= diff)
                {
                    laugh = urand(11000, 22000);
                    me->MonsterTextEmote(EMOTE_LAUGHS, 0);
                    DoPlaySoundToSet(me, RandomLaugh[rand()%3]);
                }
                else laugh -= diff;

                if (UpdateVictim())
                {
                    DoMeleeAttackIfReady();
                    if (cleave <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        cleave = urand(2000, 6000);       //1 cleave per 2.0f-6.0fsec
                    }
                    else cleave -= diff;
                }
            }
            else
            {
                if (regen <= diff)
                {
                    regen = 1000;                   //"body calls head"
                    if (me->IsFullHealth() && !returned)
                    {
                        if (Phase > 1)
                            --Phase;
                        else
                            Phase = 1;
                        Creature* Head = Unit::GetCreature((*me), headGUID);
                        if (Head && Head->IsAlive())
                        {
                            CAST_AI(mob_head::mob_headAI, Head->AI())->Phase = Phase;
                            CAST_AI(mob_head::mob_headAI, Head->AI())->Disappear();
                        }
                        return;
                    }
                }
                else regen -= diff;

                if (whirlwind <= diff)
                {
                    whirlwind = urand(4000, 8000);
                    if (urand(0, 1))
                    {
                        me->RemoveAurasDueToSpell(SPELL_CONFUSE);
                        DoCast(me, SPELL_WHIRLWIND, true);
                        DoCast(me, SPELL_CONFUSE);
                    }
                    else
                        me->RemoveAurasDueToSpell(SPELL_WHIRLWIND);
                }
                else whirlwind -= diff;
            }
        }
    };
};

class mob_pulsing_pumpkin : public CreatureScript
{
public:
    mob_pulsing_pumpkin() : CreatureScript("mob_pulsing_pumpkin") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_pulsing_pumpkinAI (creature);
    }

    struct mob_pulsing_pumpkinAI : public ScriptedAI
    {
        mob_pulsing_pumpkinAI(Creature* creature) : ScriptedAI(creature) {}

        bool sprouted;
        uint64 debuffGUID;

        void Reset()
        {
            float x, y, z;
            me->GetPosition(x, y, z);   //this visual aura some under ground
            me->SetPosition(x, y, z + 0.35f, 0.0f);
            Despawn();
            Creature* debuff = DoSpawnCreature(HELPER, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 14500);
            if (debuff)
            {
                debuff->SetDisplayId(me->GetDisplayId());
                debuff->CastSpell(debuff, SPELL_PUMPKIN_AURA_GREEN, false);
                CAST_AI(mob_wisp_invis::mob_wisp_invisAI, debuff->AI())->SetType(1);
                debuffGUID = debuff->GetGUID();
            }
            sprouted = false;
            DoCast(me, SPELL_PUMPKIN_AURA, true);
            DoCast(me, SPELL_SPROUTING);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }

        void EnterCombat(Unit* /*who*/) {}

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_SPROUTING)
            {
                sprouted = true;
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                DoCast(me, SPELL_SPROUT_BODY, true);
                me->UpdateEntry(PUMPKIN_FIEND);
                DoStartMovement(me->getVictim());
            }
        }

        void Despawn()
        {
            if (!debuffGUID)
                return;

            Unit* debuff = Unit::GetUnit(*me, debuffGUID);
            if (debuff)
            {
                debuff->SetVisible(false);
                debuffGUID = 0;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (!sprouted)
                Despawn();
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who || !me->IsValidAttackTarget(who) || me->getVictim())
                return;

            me->AddThreat(who, 0.0f);
            if (sprouted)
                DoStartMovement(who);
        }

        void UpdateAI(uint32 /*diff*/)
        {
            if (sprouted && UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };
};

class go_loosely_turned_soil : public GameObjectScript
{
public:
    go_loosely_turned_soil() : GameObjectScript("go_loosely_turned_soil") { }

    bool OnGossipHello(Player* player, GameObject* soil)
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (instance)
        {
            if (instance->GetData(DATA_HORSEMAN_EVENT) != NOT_STARTED || instance->GetData64(NPC_HORSEMAN))
                return true;
            instance->SetData(DATA_HORSEMAN_EVENT, IN_PROGRESS);
        }
    /*  if (soil->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER && player->getLevel() > 64)
        {
            player->PrepareQuestMenu(soil->GetGUID());
            player->SendPreparedQuest(soil->GetGUID());
        }
        if (player->GetQuestStatus(11405) == QUEST_STATUS_INCOMPLETE && player->getLevel() > 64)
        { */
            player->AreaExploredOrEventHappens(11405);
            if (Creature* horseman = soil->SummonCreature(HH_MOUNTED, FlightPoint[20].x, FlightPoint[20].y, FlightPoint[20].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 0))
            {
                CAST_AI(boss_headless_horseman::boss_headless_horsemanAI, horseman->AI())->PlayerGUID = player->GetGUID();
                CAST_AI(boss_headless_horseman::boss_headless_horsemanAI, horseman->AI())->FlyMode();
            }
        //}
        return true;
    }
};

void mob_head::mob_headAI::Disappear()
{
    if (withbody)
        return;

    if (bodyGUID)
    {
        Creature* body = Unit::GetCreature((*me), bodyGUID);
        if (body && body->IsAlive())
        {
            withbody = true;
            me->RemoveAllAuras();
            body->RemoveAurasDueToSpell(SPELL_IMMUNE);//hack, SpellHit doesn't calls if body has immune aura
            DoCast(body, SPELL_FLYING_HEAD);
            me->SetFullHealth();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->GetMotionMaster()->MoveIdle();
            CAST_AI(boss_headless_horseman::boss_headless_horsemanAI, body->AI())->returned = true;
        }
    }
}

void AddSC_boss_headless_horseman()
{
    new boss_headless_horseman();
    new mob_head();
    new mob_pulsing_pumpkin();
    new mob_wisp_invis();
    new go_loosely_turned_soil();
}
