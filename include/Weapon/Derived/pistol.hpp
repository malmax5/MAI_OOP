#pragma once

#include "../Base/weapon.hpp"

class Pistol : virtual public Weapon, public CreateLog<Pistol>
{
public:
    Pistol();
    ~Pistol();
};
