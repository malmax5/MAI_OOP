#pragma once

#include "../Base/equip.hpp"

struct Chestplate : virtual public Equip, public CreateLog<Chestplate>
{
public:
    Chestplate();
    ~Chestplate();
};