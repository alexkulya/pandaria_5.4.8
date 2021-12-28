#ifndef DIRE_MAUL_H_
#define DIRE_MAUL_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

const Position ironbarkPath[4]
{
    { -42.31f, -267.44f, -57.32f, 6.05f },
    {   7.69f, -288.92f, -52.41f, 5.89f },
    {  63.08f, -269.52f, -53.95f, 0.33f },
    { 127.53f, -278.66f, -55.88f, 6.16f },
};

enum eCreatures
{
    NPC_OLD_IRONBARK = 11491,
};

enum eGameObjects
{
    GO_CONSERVATORY_DOOR = 176907,
};

#endif // DIRE_MAUL_H_