#pragma once

#include "equip_builder_interface.hpp"

#include "../../my_equip.hpp"

class EquipBuilder : IEquipBuilder
{
public:
    void Reset() override;
    void SetEquip(Equip* equip) override;
    void SetMaterial(Material* material) override;
    void SetName(std::string name) override;
    Equip* GetResult();

private:
    Equip* equip_;
};
