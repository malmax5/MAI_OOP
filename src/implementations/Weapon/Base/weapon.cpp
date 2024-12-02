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

WeaponId Weapon::GetWeaponId()
{
    return id_;
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

void Weapon::SetWeaponId(WeaponId id)
{
    id_ = id;
}
