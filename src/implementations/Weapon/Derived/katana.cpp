#include "../../../../include/Weapon/Derived/katana.hpp"

Katana::Katana()
{
    LogCreate();
    SetWeaponId(WeaponId::KatanaId);
    SetAttackDamage(KatanaStat.attackDamege);
    SetAttackDistance(KatanaStat.attackDistance);
    SetReloadingTime(KatanaStat.reloadingTime);
}

Katana::~Katana()
{

}
