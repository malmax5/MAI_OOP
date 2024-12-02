#pragma once

#include "../Base/weapon.hpp"

class AutomaticRifle : virtual public Weapon, public CreateLog<AutomaticRifle>
{
public:
    AutomaticRifle();
    ~AutomaticRifle();
};
