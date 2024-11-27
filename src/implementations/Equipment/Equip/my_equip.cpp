#include "../../../../include/Equipment/Equip/my_equip.hpp"

void MyEquip::SetHelmet(std::shared_ptr<Equip> helmet)
{
    armorSet[EquipTypeId::HelmetId] = helmet;
}

void MyEquip::SetChestplate(std::shared_ptr<Equip> chestplate)
{
    armorSet[EquipTypeId::ChestplateId] = chestplate;
}

void MyEquip::SetBoots(std::shared_ptr<Equip> boots)
{
    armorSet[EquipTypeId::BootsId] = boots;
}

double MyEquip::TotalArmor()
{
    double armor = 0;
    for (auto& elem : armorSet)
    {
        armor += elem.second->GetArmor() * elem.second->GetMaterial()->GetArmorMultiple();
    }
    return armor;
}
