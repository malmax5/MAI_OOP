#include "../../../../include/Weapon/Derived/knife.hpp"

Knife::Knife()
{
    LogCreate();
    SetWeaponName(demangle(typeid(*this).name()));
    SetWeaponId(WeaponId::KnifeId);
    SetAttackDamage(KnifeStat.attackDamege);
    SetAttackDistance(KnifeStat.attackDistance);
    SetReloadingTime(KnifeStat.reloadingTime);
}

Knife::~Knife()
{

}
