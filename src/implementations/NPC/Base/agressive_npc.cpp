#include "../../../../include/NPC/Base/agressive_npc.hpp"

void AgressiveNPC::SetAttackDamage(double attackDamage)
{
    attackDamage_ = attackDamage;
}

void AgressiveNPC::SetAttackDistance(double attackDistnce)
{
    attackDistance_ = attackDistnce;
}

double AgressiveNPC::GetAttackDistance() const
{
    return attackDistance_;
}

double AgressiveNPC::GetAttackDamage() const
{
    return attackDamage_;
}

bool AgressiveNPC::ReadyToAttack() const
{
    return reloadedTime <= Time::GetLastIterTime();
}

void AgressiveNPC::Reload()
{
    
}
