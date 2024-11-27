#pragma once

#include <map>
#include <set>

#include "../Game/game_settings.hpp"

using GameSettings::NPCId;

static std::map<NPCId, std::set<NPCId>> EnemyMask{
    {NPCId::KnightId, {NPCId::SquirrelId}},
    {NPCId::SquirrelId, {NPCId::PegasusId}},
    {NPCId::PegasusId, {}},
};

bool InMaskAttack(NPCId attacker, NPCId target);