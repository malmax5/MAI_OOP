#pragma once

#include "equip_builder_interface.hpp"

#include "../../my_equip.hpp"

class EquipBuilder : IEquipBuilder
{
public:
    void Reset() override;
    void SetEquip(std::shared_ptr<Equip> equip) override;
    void SetMaterial(std::shared_ptr<Material> material) override;
    std::shared_ptr<Equip> GetResult();

private:
    std::shared_ptr<Equip> equip_;
};
