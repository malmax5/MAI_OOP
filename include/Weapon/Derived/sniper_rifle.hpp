#pragma once

#include "../Base/weapon.hpp"

class SniperRifle : virtual public Weapon, public CreateLog<SniperRifle>
{
public:
    SniperRifle();
    ~SniperRifle();
};
