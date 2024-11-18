#include "../../../../include/Equipment/Equip/my_equip.hpp"

MyEquip::MyEquip() : additionArmor(0)
{
    armorSet.reserve(3);
}

void MyEquip::SetHelmet(Helmet* helmet)
{
    armorSet[HelmetId] = reinterpret_cast<Equip*>(helmet);
}

void MyEquip::SetChestplate(Chestplate* chestplate)
{
    armorSet[ChestplateId] = reinterpret_cast<Equip*>(chestplate);
}

void MyEquip::SetBoots(Boots* boots)
{
    armorSet[BootsId] = reinterpret_cast<Equip*>(boots);
}
