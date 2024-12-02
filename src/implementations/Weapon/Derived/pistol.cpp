#include "../../../../include/Weapon/Derived/pistol.hpp"

Pistol::Pistol()
{
    LogCreate();
    SetAttackDamage(PistolStat.attackDamege);
    SetAttackDistance(PistolStat.attackDistance);
    SetReloadingTime(PistolStat.reloadingTime);
}

Pistol::~Pistol()
{

}
