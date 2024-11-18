#pragma once

#include "../../Base/equip.hpp"

class IEquipBuilder
{
public:
    virtual void Reset() = 0;
    virtual void SetArmor(double armor) = 0;
    virtual void SetMaterial(Material* material) = 0;
    virtual void SetName(std::string name) = 0;

};