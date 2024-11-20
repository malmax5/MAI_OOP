#pragma once

#include "myequip_builder_interface.hpp"

#include "../../my_equip.hpp"

class MyEquipBuilder : IMyEquipBuilder
{
public:
    void Reset() override;
    void SetHelmet(std::shared_ptr<Equip> helmet) override;
    void SetChestplate(std::shared_ptr<Equip> chestplate) override;
    void SetBoots(std::shared_ptr<Equip> boots) override;
    std::shared_ptr<MyEquip> GetResult();

private:
    std::shared_ptr<MyEquip> myEquip_;
};