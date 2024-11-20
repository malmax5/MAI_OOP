#pragma once

#include <vector>

#include "Base/equip.hpp"
#include "Derived/helmet.hpp"
#include "Derived/chestplate.hpp"
#include "Derived/boots.hpp"

enum ArmorId
{
    HelmetId = 0,
    ChestplateId = 1,
    BootsId = 2
};

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
