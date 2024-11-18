#pragma once

#include "../../Base/equip.hpp"
#include "../../Derived/helmet.hpp"
#include "../../Derived/chestplate.hpp"
#include "../../Derived/boots.hpp"

class IMyEquipBuilder
{
public:
    virtual void Reset() = 0;
    virtual void SetHelmet(Helmet* helmet) = 0;
    virtual void SetChestplate(Chestplate* chestplate) = 0;
    virtual void SetBoots(Boots* boots) = 0;

};