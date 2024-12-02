#include "../../../../include/Weapon/Derived/pistol.hpp"

Pistol::Pistol()
{
    LogCreate();
    SetWeaponId(WeaponId::PistolId);
    SetAttackDamage(PistolStat.attackDamege);
    SetAttackDistance(PistolStat.attackDistance);
    SetReloadingTime(PistolStat.reloadingTime);
}

Pistol::~Pistol()
{

}
