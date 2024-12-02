#pragma once

#include "../Base/weapon.hpp"

class Knife : virtual public Weapon, public CreateLog<Knife>
{
public:
    Knife();
    ~Knife();
};
