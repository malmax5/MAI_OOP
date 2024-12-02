#include "../../../../include/Weapon/Derived/automatic_rifle.hpp"

AutomaticRifle::AutomaticRifle()
{
    LogCreate();
    SetAttackDamage(AutomaticRifleStat.attackDamege);
    SetAttackDistance(AutomaticRifleStat.attackDistance);
    SetReloadingTime(AutomaticRifleStat.reloadingTime);
}

AutomaticRifle::~AutomaticRifle()
{

}
