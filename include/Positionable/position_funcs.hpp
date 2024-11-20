#pragma once

#include "../NPC/Base/npc.hpp"
#include "cmath"

class NPCPositionFuncs
{
public:
    static double DistanceBetNPC(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2);

};