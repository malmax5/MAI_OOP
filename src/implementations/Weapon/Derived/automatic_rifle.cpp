#include "../../../../include/Weapon/Derived/automatic_rifle.hpp"

AutomaticRifle::AutomaticRifle()
{
    LogCreate();
    SetWeaponId(WeaponId::AutomaticRifleId);
    SetAttackDamage(AutomaticRifleStat.attackDamege);
    SetAttackDistance(AutomaticRifleStat.attackDistance);
    SetReloadingTime(AutomaticRifleStat.reloadingTime);
}

AutomaticRifle::~AutomaticRifle()
{

}
