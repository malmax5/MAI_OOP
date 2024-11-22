#include <gtest/gtest.h>
#include "../include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder.hpp"
#include "../include/Equipment/Equip/Derived/helmet.hpp"
#include "../include/Equipment/Equip/Derived/chestplate.hpp"
#include "../include/Equipment/Equip/Derived/boots.hpp"

TEST(MyEquipBuilderTest, BuildMyEquip) {
    MyEquipBuilder builder;
    std::shared_ptr<Equip> helmet = std::make_shared<Helmet>();
    std::shared_ptr<Equip> chestplate = std::make_shared<Chestplate>();
    std::shared_ptr<Equip> boots = std::make_shared<Boots>();

    builder.Reset();
    builder.SetHelmet(helmet);
    builder.SetChestplate(chestplate);
    builder.SetBoots(boots);

    std::shared_ptr<MyEquip> myEquip = builder.GetResult();

    ASSERT_NE(myEquip, nullptr);
    ASSERT_EQ(myEquip->armorSet.size(), 3);
    ASSERT_EQ(myEquip->armorSet[0], helmet);
    ASSERT_EQ(myEquip->armorSet[1], chestplate);
    ASSERT_EQ(myEquip->armorSet[2], boots);
}

TEST(MyEquipBuilderTest, BuildMyEquipWithEmptySet) {
    MyEquipBuilder builder;

    builder.Reset();

    std::shared_ptr<MyEquip> myEquip = builder.GetResult();

    ASSERT_NE(myEquip, nullptr);
}