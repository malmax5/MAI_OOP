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

    void SetHelmet(Helmet* helmet);
    void SetChestplate(Chestplate* chestplate);
    void SetBoots(Boots* boots);

protected:
    double TotalArmor();

private:
    std::vector<Equip*> armorSet;
    double additionArmor;
};