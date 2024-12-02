#include "../../../../include/Weapon/Derived/knife.hpp"

Knife::Knife()
{
    LogCreate();
    SetWeaponId(WeaponId::KnifeId);
    SetAttackDamage(KnifeStat.attackDamege);
    SetAttackDistance(KnifeStat.attackDistance);
    SetReloadingTime(KnifeStat.reloadingTime);
}

Knife::~Knife()
{

}
