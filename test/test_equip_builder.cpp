#include <gtest/gtest.h>
#include "../include/Equipment/Equip/Builder/Equip_Builder/equip_builder.hpp"
#include "../include/Equipment/Material/Base/material.hpp"
#include "../include/Equipment/Material/Derived/no_material.hpp"
#include "../include/Equipment/Material/Derived/decorative.hpp"
#include "../include/Equipment/Material/Derived/iron.hpp"

TEST(EquipBuilderTest, BuildEquip) {
    EquipBuilder builder;
    std::shared_ptr<Material> material = std::make_shared<Iron>();

    builder.Reset();
    builder.SetMaterial(material);
    builder.SetName("Iron Helmet");

    std::shared_ptr<Equip> equip = builder.GetResult();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->GetName(), "Iron Helmet");
}

TEST(EquipBuilderTest, BuildEquipWithNoMaterial) {
    EquipBuilder builder;
    std::shared_ptr<Material> material = std::make_shared<NoMaterial>();

    builder.Reset();
    builder.SetMaterial(material);
    builder.SetName("No Material Helmet");

    std::shared_ptr<Equip> equip = builder.GetResult();

    ASSERT_NE(equip, nullptr);
    ASSERT_EQ(equip->GetName(), "No Material Helmet");
}