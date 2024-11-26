#pragma once

#include <vector>

#include "Base/equip.hpp"
#include "Derived/helmet.hpp"
#include "Derived/chestplate.hpp"
#include "Derived/boots.hpp"
#include "equip_type_id.hpp"

class MyEquip
{
public:
    MyEquip();

    void SetHelmet(std::shared_ptr<Equip> helmet);
    void SetChestplate(std::shared_ptr<Equip> chestplate);
    void SetBoots(std::shared_ptr<Equip> boots);

public:
    double TotalArmor();

public:
    std::vector<std::shared_ptr<Equip>> armorSet;
};
