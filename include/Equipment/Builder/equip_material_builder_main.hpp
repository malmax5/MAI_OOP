#include "../Equip/Builder/Equip_Builder/equip_builder.hpp"

#include "../Material/Derived/dimond.hpp"
#include "../Material/Derived/iron.hpp"
#include "../Material/Derived/gold.hpp"

class EquipWithMaterialBuilder
{
public:
    void BuildIronHelmet(EquipBuilder* builder);
    void BuildIronChestplate(EquipBuilder* builder);
    void BuildIronBoots(EquipBuilder* builder);

    void BuildGoldHelmet(EquipBuilder* builder);
    void BuildGoldChestplate(EquipBuilder* builder);
    void BuildGoldBoots(EquipBuilder* builder);

    void BuildDimondHelmet(EquipBuilder* builder);
    void BuildDimondChestplate(EquipBuilder* builder);
    void BuildDimondBoots(EquipBuilder* builder);
};