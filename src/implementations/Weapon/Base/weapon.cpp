#include "../../../../include/Weapon/Base/weapon.hpp"

double Weapon::GetAttackDamage()
{
    return attackDamage_;
}

double Weapon::GetAttackDistance()
{
    return attackDistance_;
}

double Weapon::GetReloadingTime()
{
    return reloadingTime_;
}

void Weapon::SetAttackDamage(double attackDamage)
{
    attackDamage_ = attackDamage;
}

void Weapon::SetAttackDistance(double attackDistance)
{
    attackDistance_ = attackDistance;
}

void Weapon::SetReloadingTime(double reloadingTime)
{
    reloadingTime_ = reloadingTime;
}
