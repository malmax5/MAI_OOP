#include "../../../../include/Weapon/Derived/pistol.hpp"

Pistol::Pistol()
{
    LogCreate();
    SetWeaponName(demangle(typeid(*this).name()));
    SetWeaponId(WeaponId::PistolId);
    SetAttackDamage(PistolStat.attackDamege);
    SetAttackDistance(PistolStat.attackDistance);
    SetReloadingTime(PistolStat.reloadingTime);
}

Pistol::~Pistol()
{

}
