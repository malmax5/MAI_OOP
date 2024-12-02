#include "../../../../include/Weapon/Derived/automatic_rifle.hpp"

AutomaticRifle::AutomaticRifle()
{
    LogCreate();
    SetWeaponName(demangle(typeid(*this).name()));
    SetWeaponId(WeaponId::AutomaticRifleId);
    SetAttackDamage(AutomaticRifleStat.attackDamege);
    SetAttackDistance(AutomaticRifleStat.attackDistance);
    SetReloadingTime(AutomaticRifleStat.reloadingTime);
}

AutomaticRifle::~AutomaticRifle()
{

}
