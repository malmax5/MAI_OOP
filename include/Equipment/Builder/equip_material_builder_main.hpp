#pragma once

#include "../Equip/Builder/Equip_Builder/equip_builder.hpp"

#include "../Material/Derived/dimond.hpp"
#include "../Material/Derived/iron.hpp"
#include "../Material/Derived/gold.hpp"
#include "../Material/Derived/decorative.hpp"
#include "../Material/Derived/no_material.hpp"

class EquipWithMaterialBuilder
{
public:
    void BuildDecorativeHelmet(std::shared_ptr<EquipBuilder> builder);
    void BuildDecorativeChestplate(std::shared_ptr<EquipBuilder> builder);
    void BuildDecorativeBoots(std::shared_ptr<EquipBuilder> builder);

    void BuildNoMaterialHelmet(std::shared_ptr<EquipBuilder> builder);
    void BuildNoMaterialChestplate(std::shared_ptr<EquipBuilder> builder);
    void BuildNoMaterialBoots(std::shared_ptr<EquipBuilder> builder);

    void BuildIronHelmet(std::shared_ptr<EquipBuilder> builder);
    void BuildIronChestplate(std::shared_ptr<EquipBuilder> builder);
    void BuildIronBoots(std::shared_ptr<EquipBuilder> builder);

    void BuildGoldHelmet(std::shared_ptr<EquipBuilder> builder);
    void BuildGoldChestplate(std::shared_ptr<EquipBuilder> builder);
    void BuildGoldBoots(std::shared_ptr<EquipBuilder> builder);

    void BuildDimondHelmet(std::shared_ptr<EquipBuilder> builder);
    void BuildDimondChestplate(std::shared_ptr<EquipBuilder> builder);
    void BuildDimondBoots(std::shared_ptr<EquipBuilder> builder);
};