#pragma once

#include "myequip_builder_interface.hpp"

#include "../../my_equip.hpp"

class MyEquipBuilder : IMyEquipBuilder
{
public:
    void Reset() override;
    void SetHelmet(Helmet* helmet) override;
    void SetChestplate(Chestplate* chestplate) override;
    void SetBoots(Boots* boots) override;
    MyEquip* GetResult();

private:
    MyEquip* myEquip_;
};