#include "../../../../include/Weapon/Derived/machine_gun.hpp"

MachineGun::MachineGun()
{
    LogCreate();
    SetWeaponName(demangle(typeid(*this).name()));
    SetWeaponId(WeaponId::MachineGunId);
    SetAttackDamage(MachineGunStat.attackDamege);
    SetAttackDistance(MachineGunStat.attackDistance);
    SetReloadingTime(MachineGunStat.reloadingTime);
}

MachineGun::~MachineGun()
{

}
