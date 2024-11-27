#pragma once

#include <map>

#include "Base/equip.hpp"
#include "Derived/helmet.hpp"
#include "Derived/chestplate.hpp"
#include "Derived/boots.hpp"
#include "../../Game/game_settings.hpp"

using GameSettings::EquipTypeId;

class MyEquip
{
public:
    void SetHelmet(std::shared_ptr<Equip> helmet);
    void SetChestplate(std::shared_ptr<Equip> chestplate);
    void SetBoots(std::shared_ptr<Equip> boots);

public:
    double TotalArmor();

public:
    std::map<EquipTypeId, std::shared_ptr<Equip>> armorSet;
};
