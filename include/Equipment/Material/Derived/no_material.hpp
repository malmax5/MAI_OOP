#pragma once

#include "../Base/material.hpp"

struct NoMaterial : virtual public Material
{
public:
    NoMaterial();
};