#include "/home/cbf/MAI/OOP/Lab_6/include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_main.hpp"

#include <iostream>

int main()
{
    MyEquipBuilderMain builder;
    MyEquip* equip = builder.BuildSetByMask(IronMaterial, GoldMaterial, DimondMaterial);

    std::cout << equip->TotalArmor();

}