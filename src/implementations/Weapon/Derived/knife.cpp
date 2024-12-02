#include "../../../../include/Weapon/Derived/knife.hpp"

Knife::Knife()
{
    LogCreate();
    SetAttackDamage(KnifeStat.attackDamege);
    SetAttackDistance(KnifeStat.attackDistance);
    SetReloadingTime(KnifeStat.reloadingTime);
}

Knife::~Knife()
{

}
