#pragma once

#include "../../Material/Base/material.hpp"

struct Equip
{
public:
    double GetArmor();
    Material GetMaterial();

protected:
    void SetArmor(double armor);
    void SetMaterial(Material material)

private:
    double armor_;
    Material material_;
};
