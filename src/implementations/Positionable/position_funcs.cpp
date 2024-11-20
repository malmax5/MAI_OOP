#include "../../../include/Positionable/position_funcs.hpp"

double NPCPositionFuncs::DistanceBetNPC(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2)
{
    return sqrt(pow(npc1->GetXCord() - npc2->GetXCord(), 2) +
                pow(npc1->GetYCord() - npc2->GetYCord(), 2));
}
