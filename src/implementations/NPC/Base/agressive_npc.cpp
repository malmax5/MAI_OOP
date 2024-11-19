#include "../../../../include/NPC/Base/agressive_npc.hpp"

double AgressiveNPC::GetAttackDamage()
{
    return attackDamage_;
}

double AgressiveNPC::GetAttackDistance()
{
    return attackDistance_;
}

NPC* AgressiveNPC::GetTarget()
{
    return target_;
}

void AgressiveNPC::SetAttackDamage(double attackDamage)
{
    attackDamage_ = attackDamage;
}

void AgressiveNPC::SetAttackDistance(double attackDistnce)
{
    attackDistance_ = attackDistnce;
}

void AgressiveNPC::SetTarget(NPC* target)
{
    target_ = target;
}
