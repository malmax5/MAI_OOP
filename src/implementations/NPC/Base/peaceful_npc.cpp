#include "../../../../include/NPC/Base/peaceful_npc.hpp"

double PeacefulNPC::GetAttackDistance()
{
    return 0;
}

double PeacefulNPC::GetAttackDamage()
{
    return 0;
}

void PeacefulNPC::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    return;
}
