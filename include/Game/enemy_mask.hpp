#pragma once

#include <map>
#include <set>

#include "../NPC/Enums/type_id_enum.hpp"

static std::map<NPCId, std::set<NPCId>> EnemyMask{
    {KnightId, {SquirrelId}},
    {SquirrelId, {PegasusId}},
    {PegasusId, {}},
};

bool InMaskAttack(NPCId attacker, NPCId target);