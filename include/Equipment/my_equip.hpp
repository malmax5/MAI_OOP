#pragma once

#include <vector>

#include "Equip/Base/equip.hpp"
#include "Equip/Derived/helmet.hpp"
#include "Equip/Derived/chestplate.hpp"
#include "Equip/Derived/boots.hpp"

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

    void SetHelmet(Helmet helmet);
    void SetChestplate(Chestplate chestplate);
    void SetBoots(Boots boots);

protected:
    double TotalArmor();

private:
    std::vector<Equip> armorSet;
    double additionArmor;
};