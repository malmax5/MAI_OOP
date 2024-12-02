#pragma once

#include "../Base/equip.hpp"

struct Boots : virtual public Equip, public CreateLog<Boots>
{
public:
    Boots();
    ~Boots();
};