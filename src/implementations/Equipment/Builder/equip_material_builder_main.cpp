#include "../../../../include/Equipment/Builder/equip_material_builder_main.hpp"

//No Material
void EquipWithMaterialBuilder::BuildDecorativeHelmet(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Helmet>());
    builder->SetMaterial(std::make_shared<Decorative>());
    builder->SetName("Decorative Helmet");
}

void EquipWithMaterialBuilder::BuildDecorativeChestplate(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Chestplate>());
    builder->SetMaterial(std::make_shared<Decorative>());
    builder->SetName("Decorative Chestplate");
}

void EquipWithMaterialBuilder::BuildDecorativeBoots(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Boots>());
    builder->SetMaterial(std::make_shared<Decorative>());
    builder->SetName("Decorative Boots");
}

//No Material
void EquipWithMaterialBuilder::BuildNoMaterialHelmet(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Helmet>());
    builder->SetMaterial(std::make_shared<NoMaterial>());
    builder->SetName("No Material Helmet");
}

void EquipWithMaterialBuilder::BuildNoMaterialChestplate(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Chestplate>());
    builder->SetMaterial(std::make_shared<NoMaterial>());
    builder->SetName("No Material Chestplate");
}

void EquipWithMaterialBuilder::BuildNoMaterialBoots(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Boots>());
    builder->SetMaterial(std::make_shared<NoMaterial>());
    builder->SetName("No Material Boots");
}

//Iron
void EquipWithMaterialBuilder::BuildIronHelmet(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Helmet>());
    builder->SetMaterial(std::make_shared<Iron>());
    builder->SetName("Iron Helmet");
}

void EquipWithMaterialBuilder::BuildIronChestplate(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Chestplate>());
    builder->SetMaterial(std::make_shared<Iron>());
    builder->SetName("Iron Chestplate");
}

void EquipWithMaterialBuilder::BuildIronBoots(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Boots>());
    builder->SetMaterial(std::make_shared<Iron>());
    builder->SetName("Iron Boots");
}

//Gold
void EquipWithMaterialBuilder::BuildGoldHelmet(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Helmet>());
    builder->SetMaterial(std::make_shared<Gold>());
    builder->SetName("Gold Helmet");
}

void EquipWithMaterialBuilder::BuildGoldChestplate(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Chestplate>());
    builder->SetMaterial(std::make_shared<Gold>());
    builder->SetName("Gold Chestplate");
}

void EquipWithMaterialBuilder::BuildGoldBoots(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Boots>());
    builder->SetMaterial(std::make_shared<Gold>());
    builder->SetName("Gold Boots");
}

//Dimond
void EquipWithMaterialBuilder::BuildDimondHelmet(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Helmet>());
    builder->SetMaterial(std::make_shared<Dimond>());
    builder->SetName("Dimond Helmet");
}

void EquipWithMaterialBuilder::BuildDimondChestplate(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Chestplate>());
    builder->SetMaterial(std::make_shared<Dimond>());
    builder->SetName("Dimond Chestplate");
}

void EquipWithMaterialBuilder::BuildDimondBoots(std::shared_ptr<EquipBuilder> builder)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Boots>());
    builder->SetMaterial(std::make_shared<Dimond>());
    builder->SetName("Dimond Boots");
}
