#include "../../../../include/Equipment/Equip/my_equip.hpp"

MyEquip::MyEquip()
{
    armorSet.resize(3);
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

double MyEquip::TotalArmor()
{
    double armor = 0;
    for (auto& elem : armorSet)
    {
        armor += elem->GetArmor() * elem->GetMaterial()->GetArmorMultiple();
    }
    return armor;
}
