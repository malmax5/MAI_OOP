#include "../../../../include/Weapon/Derived/sniper_rifle.hpp"

SniperRifle::SniperRifle()
{
    LogCreate();
    SetWeaponName(demangle(typeid(*this).name()));
    SetWeaponId(WeaponId::SniperRifleId);
    SetAttackDamage(SniperRifleStat.attackDamege);
    SetAttackDistance(SniperRifleStat.attackDistance);
    SetReloadingTime(SniperRifleStat.reloadingTime);
}

SniperRifle::~SniperRifle()
{

}
