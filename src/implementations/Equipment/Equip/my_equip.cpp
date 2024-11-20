#include "../../../../include/Equipment/Equip/my_equip.hpp"

MyEquip::MyEquip()
{
    armorSet.resize(3);
}

void MyEquip::SetHelmet(std::shared_ptr<Equip> helmet)
{
    armorSet[HelmetId] = helmet;
}

void MyEquip::SetChestplate(std::shared_ptr<Equip> chestplate)
{
    armorSet[ChestplateId] = chestplate;
}

void MyEquip::SetBoots(std::shared_ptr<Equip> boots)
{
    armorSet[BootsId] = boots;
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
