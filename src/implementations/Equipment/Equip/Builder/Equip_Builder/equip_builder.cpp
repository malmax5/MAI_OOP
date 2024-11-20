#include "../../../../../../include/Equipment/Equip/Builder/Equip_Builder/equip_builder.hpp"

void EquipBuilder::Reset()
{
    equip_ = std::make_shared<Equip>();
}

void EquipBuilder::SetEquip(std::shared_ptr<Equip> equip)
{
    equip_ = equip;
}

void EquipBuilder::SetMaterial(std::shared_ptr<Material> material)
{
    equip_->SetMaterial(material);
}

void EquipBuilder::SetName(std::string name)
{
    equip_->SetName(name);
}

std::shared_ptr<Equip> EquipBuilder::GetResult()
{
    return equip_;
}
