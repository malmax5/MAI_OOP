#include "../../../../include/Equipment/Builder/equip_material_builder_main.hpp"

//Iron
void EquipWithMaterialBuilder::BuildIronHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new Iron);
    builder->SetName("Iron Helmet");
}

void EquipWithMaterialBuilder::BuildIronChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new Iron);
    builder->SetName("Iron Chestplate");
}

void EquipWithMaterialBuilder::BuildIronBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new Iron);
    builder->SetName("Iron Boots");
}

//Gold
void EquipWithMaterialBuilder::BuildGoldHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new Gold);
    builder->SetName("Gold Helmet");
}

void EquipWithMaterialBuilder::BuildGoldChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new Gold);
    builder->SetName("Gold Chestplate");
}

void EquipWithMaterialBuilder::BuildGoldBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new Gold);
    builder->SetName("Gold Boots");
}

//Dimond
void EquipWithMaterialBuilder::BuildDimondHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new Dimond);
    builder->SetName("Dimond Helmet");
}

void EquipWithMaterialBuilder::BuildDimondChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new Dimond);
    builder->SetName("Dimond Chestplate");
}

void EquipWithMaterialBuilder::BuildDimondBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new Dimond);
    builder->SetName("Dimond Boots");
}
