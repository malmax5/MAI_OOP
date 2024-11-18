#include "../../../../../../include/Equipment/Equip/Builder/Equip_Builder/equip_builder.hpp"

void EquipBuilder::Reset()
{
    equip_ = new Equip;
}

void EquipBuilder::SetArmor(double armor)
{
    equip_->SetArmor(armor);
}

void EquipBuilder::SetMaterial(Material* material)
{
    equip_->SetMaterial(material);
}

void EquipBuilder::SetName(std::string name)
{
    equip_->SetName(name);
}

Equip* EquipBuilder::GetResult()
{
    return equip_;
}
