#pragma once

#include "../../Base/equip.hpp"
#include "../../Derived/helmet.hpp"
#include "../../Derived/chestplate.hpp"
#include "../../Derived/boots.hpp"

class IMyEquipBuilder
{
public:
    virtual void Reset() = 0;
    virtual void SetHelmet(std::shared_ptr<Equip> helmet) = 0;
    virtual void SetChestplate(std::shared_ptr<Equip> chestplate) = 0;
    virtual void SetBoots(std::shared_ptr<Equip> boots) = 0;

};