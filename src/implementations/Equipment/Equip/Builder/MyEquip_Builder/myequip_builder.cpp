#include "../../../../../../include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder.hpp"

void MyEquipBuilder::Reset()
{
    myEquip_ = new MyEquip;
}

void MyEquipBuilder::SetHelmet(Helmet* helmet)
{
    myEquip_->SetHelmet(helmet);
}

void MyEquipBuilder::SetChestplate(Chestplate* chestplate)
{
    myEquip_->SetChestplate(chestplate);
}

void MyEquipBuilder::SetBoots(Boots* boots)
{
    myEquip_->SetBoots(boots);
}

MyEquip* MyEquipBuilder::GetResult()
{
    return myEquip_;
}
