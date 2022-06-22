//UWoWCore
//Terrace of Endless Spring

#ifndef TERRACEOFENDLESSSPRING
#define TERRACEOFENDLESSSPRING

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum eData
{
    DATA_PROTECTORS          = 1,
    DATA_TSULONG             = 2,
    DATA_LEI_SHI             = 3,
    DATA_SHA_OF_FEAR         = 4,
};

enum eCreatures
{
    //Protectors
    NPC_PROTECTOR_KAOLAN     = 60583,
    NPC_ELDER_REGAIL         = 60585,
    NPC_ELDER_ASANI          = 60586,
    //
    NPC_TSULONG              = 62442,
    NPC_LEI_SHI              = 62983,
    NPC_SHA_OF_FEAR          = 60999,
};

enum eGameObjects
{   
    GO_LEI_SHI_ENT_DOOR      = 212916,
    GO_LEI_SHI_EX_DOOR       = 214634,
};

enum sAction
{
    ACTION_REMOVE_PROTECT      = 23,
};

#endif TERRACEOFENDLESSSPRING
