#pragma once

#include "../Base/material.hpp"

struct NoMaterial : virtual public Material, public CreateLog<NoMaterial>
{
public:
    NoMaterial();
    ~NoMaterial();
};