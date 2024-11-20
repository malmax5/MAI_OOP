#include "../../../../include/NPC/Base/agressive_npc.hpp"

double AgressiveNPC::GetAttackDamage()
{
    return attackDamage_;
}

double AgressiveNPC::GetAttackDistance()
{
    return attackDistance_;
}

std::shared_ptr<NPC> AgressiveNPC::GetTarget()
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

void AgressiveNPC::SetTarget(std::shared_ptr<NPC> target)
{
    target_ = target;
}
