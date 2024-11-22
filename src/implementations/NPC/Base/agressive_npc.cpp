#include "../../../../include/NPC/Base/agressive_npc.hpp"

void AgressiveNPC::SetAttackDamage(double attackDamage)
{
    attackDamage_ = attackDamage;
}

void AgressiveNPC::SetAttackDistance(double attackDistnce)
{
    attackDistance_ = attackDistnce;
}

double AgressiveNPC::GetAttackDistance()
{
    return attackDistance_;
}

double AgressiveNPC::GetAttackDamage()
{
    return attackDamage_;
}

void AgressiveNPC::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    return;
}
