#pragma once

#include "../Base/material.hpp"

struct Diamond : virtual public Material, public CreateLog<Diamond>
{
public:
    Diamond();
    ~Diamond();
};
