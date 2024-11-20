#include "../../../../../../include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder.hpp"

void MyEquipBuilder::Reset()
{
    // myEquip_ =  std::make_shared<MyEquip>();
    myEquip_ = std::make_shared<MyEquip>();
}

void MyEquipBuilder::SetHelmet(std::shared_ptr<Equip> helmet)
{
    myEquip_->SetHelmet(helmet);
}

void MyEquipBuilder::SetChestplate(std::shared_ptr<Equip> chestplate)
{
    myEquip_->SetChestplate(chestplate);
}

void MyEquipBuilder::SetBoots(std::shared_ptr<Equip> boots)
{
    myEquip_->SetBoots(boots);
}

std::shared_ptr<MyEquip> MyEquipBuilder::GetResult()
{
    return myEquip_;
}
