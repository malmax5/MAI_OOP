#include "../../../../include/Weapon/Derived/sniper_rifle.hpp"

SniperRifle::SniperRifle()
{
    LogCreate();
    SetWeaponId(WeaponId::SniperRifleId);
    SetAttackDamage(SniperRifleStat.attackDamege);
    SetAttackDistance(SniperRifleStat.attackDistance);
    SetReloadingTime(SniperRifleStat.reloadingTime);
}

SniperRifle::~SniperRifle()
{

}
