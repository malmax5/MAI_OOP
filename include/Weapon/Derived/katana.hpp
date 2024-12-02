#pragma once

#include "../Base/weapon.hpp"

class Katana : virtual public Weapon, public CreateLog<Katana>
{
public:
    Katana();
    ~Katana();
};
