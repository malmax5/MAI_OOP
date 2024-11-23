#pragma once

#include <memory>

#include "../../Base/equip.hpp"

class IEquipBuilder
{
public:
    virtual void Reset() = 0;
    virtual void SetEquip(std::shared_ptr<Equip> equip) = 0;
    virtual void SetMaterial(std::shared_ptr<Material> material) = 0;

};