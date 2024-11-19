#include "../../../../include/Equipment/Builder/equip_material_builder_main.hpp"
#include "../../../../Log/log.hpp"

//No Material
void EquipWithMaterialBuilder::BuildDecorativeHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new Decorative);
    builder->SetName("Decorative Helmet");
    logger->log("created Decorative Helmet");
}

void EquipWithMaterialBuilder::BuildDecorativeChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new Decorative);
    builder->SetName("Decorative Chestplate");
    logger->log("created Decorative Chestplate");
}

void EquipWithMaterialBuilder::BuildDecorativeBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new NoMaterial);
    builder->SetName("Decorative Boots");
    logger->log("created Decorative Boots");
}

//No Material
void EquipWithMaterialBuilder::BuildNoMaterialHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new NoMaterial);
    builder->SetName("No Material Helmet");
    logger->log("created No Material Helmet");
}

void EquipWithMaterialBuilder::BuildNoMaterialChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new NoMaterial);
    builder->SetName("No Material Chestplate");
    logger->log("created No Material Chestplate");
}

void EquipWithMaterialBuilder::BuildNoMaterialBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new NoMaterial);
    builder->SetName("No Material Boots");
    logger->log("created No Material Boots");
}

//Iron
void EquipWithMaterialBuilder::BuildIronHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new Iron);
    builder->SetName("Iron Helmet");
    logger->log("created Iron Helmet");
}

void EquipWithMaterialBuilder::BuildIronChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new Iron);
    builder->SetName("Iron Chestplate");
    logger->log("created Iron Chestplate");
}

void EquipWithMaterialBuilder::BuildIronBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new Iron);
    builder->SetName("Iron Boots");
    logger->log("created Iron Boots");
}

//Gold
void EquipWithMaterialBuilder::BuildGoldHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new Gold);
    builder->SetName("Gold Helmet");
    logger->log("created Gold Helmet");
}

void EquipWithMaterialBuilder::BuildGoldChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new Gold);
    builder->SetName("Gold Chestplate");
    logger->log("created Gold Chestplate");
}

void EquipWithMaterialBuilder::BuildGoldBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new Gold);
    builder->SetName("Gold Boots");
    logger->log("created Gold Boots");
}

//Dimond
void EquipWithMaterialBuilder::BuildDimondHelmet(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Helmet);
    builder->SetMaterial(new Dimond);
    builder->SetName("Dimond Helmet");
    logger->log("created Dimond Helmet");
}

void EquipWithMaterialBuilder::BuildDimondChestplate(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Chestplate);
    builder->SetMaterial(new Dimond);
    builder->SetName("Dimond Chestplate");
    logger->log("created Dimond Chestplate");
}

void EquipWithMaterialBuilder::BuildDimondBoots(EquipBuilder* builder)
{
    builder->Reset();
    builder->SetEquip(new Boots);
    builder->SetMaterial(new Dimond);
    builder->SetName("Dimond Boots");
    logger->log("created Dimond Boots");
}
