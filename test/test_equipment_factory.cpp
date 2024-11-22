#include <gtest/gtest.h>
#include "../include/Equipment/Factory/equipment_factory.hpp"

// Тест для проверки создания случайного набора экипировки
TEST(EquipmentFactoryTest, CreateRandomEquip) {
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел

    StandartEquipmentFactoryRandom factory;
    std::shared_ptr<MyEquip> equip = factory.createEquip();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->armorSet.size(), 3); // Проверка, что в наборе 3 элемента

    double totalArmor = equip->TotalArmor();
    ASSERT_GT(totalArmor, 0); // Проверка, что общая броня больше 0
}

// Тест для проверки создания набора экипировки с определенными материалами
TEST(EquipmentFactoryTest, CreateSpecificEquip) {
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел

    StandartEquipmentFactoryRandom factory;
    std::shared_ptr<MyEquip> equip = factory.createEquip();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->armorSet.size(), 3); // Проверка, что в наборе 3 элемента

    // Проверка материалов каждого элемента экипировки
    for (const auto& item : equip->armorSet) {
        std::shared_ptr<Material> material = item->GetMaterial();
        ASSERT_NE(material, nullptr);
        ASSERT_GT(material->GetArmorMultiple(), 0); // Проверка, что множитель брони больше 0
    }
}

// Тест для проверки создания набора экипировки с нулевой броней
TEST(EquipmentFactoryTest, CreateZeroArmorEquip) {
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел

    StandartEquipmentFactoryRandom factory;
    std::shared_ptr<MyEquip> equip = factory.createEquip();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->armorSet.size(), 3); // Проверка, что в наборе 3 элемента

    double totalArmor = equip->TotalArmor();
    ASSERT_GE(totalArmor, 0); // Проверка, что общая броня не меньше 0
}

// Тест для проверки создания набора экипировки с определенным именем
TEST(EquipmentFactoryTest, CreateNamedEquip) {
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел

    StandartEquipmentFactoryRandom factory;
    std::shared_ptr<MyEquip> equip = factory.createEquip();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->armorSet.size(), 3); // Проверка, что в наборе 3 элемента

    // Проверка имени каждого элемента экипировки
    for (const auto& item : equip->armorSet) {
        std::string name = item->GetName();
        ASSERT_FALSE(name.empty()); // Проверка, что имя не пустое
    }
}
