#pragma once

#include "../Base/material.hpp"

struct Decorative : virtual public Material, public CreateLog<Decorative>
{
public:
    Decorative();
    ~Decorative();
};
