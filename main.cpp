#include "/home/cbf/MAI/OOP/Lab_6/include/Equipment/Factory/equipment_factory.hpp"

#include <iostream>

int main()
{
    StandartEquipmentFactoryRandom factory;
    MyEquip* equip = factory.createEquip();

    std::cout << equip->TotalArmor();

}