#include "../../../../include/Weapon/Derived/katana.hpp"

Katana::Katana()
{
    LogCreate();
    SetWeaponName(demangle(typeid(*this).name()));
    SetWeaponId(WeaponId::KatanaId);
    SetAttackDamage(KatanaStat.attackDamege);
    SetAttackDistance(KatanaStat.attackDistance);
    SetReloadingTime(KatanaStat.reloadingTime);
}

Katana::~Katana()
{

}
