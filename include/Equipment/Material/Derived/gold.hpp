#pragma once

#include "../Base/material.hpp"

struct Gold : virtual public Material, public CreateLog<Gold>
{
public:
    Gold();
    ~Gold();
};