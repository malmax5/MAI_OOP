#include <gtest/gtest.h>
#include "../include/Equipment/Factory/equipment_factory.hpp"

TEST(EquipmentFactoryTest, CreateRandomEquip) {
    std::srand(std::time(nullptr));

    StandartEquipmentFactoryRandom factory;
    std::shared_ptr<MyEquip> equip = factory.createEquip();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->armorSet.size(), 3);

    double totalArmor = equip->TotalArmor();
    ASSERT_GT(totalArmor, 0);
}

TEST(EquipmentFactoryTest, CreateZeroArmorEquip) {
    std::srand(std::time(nullptr));

    StandartEquipmentFactoryRandom factory;
    std::shared_ptr<MyEquip> equip = factory.createEquip();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->armorSet.size(), 3);

    double totalArmor = equip->TotalArmor();
    ASSERT_GE(totalArmor, 0);
}

TEST(EquipmentFactoryTest, CreateNamedEquip) {
    std::srand(std::time(nullptr));

    StandartEquipmentFactoryRandom factory;
    std::shared_ptr<MyEquip> equip = factory.createEquip();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->armorSet.size(), 3);

    for (const auto& item : equip->armorSet) {
        std::string name = item->GetName();
        ASSERT_FALSE(name.empty());
    }
}
