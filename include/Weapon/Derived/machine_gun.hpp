#pragma once

#include "../Base/weapon.hpp"

class MachineGun : virtual public Weapon, public CreateLog<MachineGun>
{
public:
    MachineGun();
    ~MachineGun();
};
