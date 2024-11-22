#include <gtest/gtest.h>
#include "../include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_main.hpp"
#include "../include/Equipment/Material/Base/material.hpp"
#include "../include/Equipment/Material/Derived/no_material.hpp"
#include "../include/Equipment/Material/Derived/decorative.hpp"
#include "../include/Equipment/Material/Derived/iron.hpp"

TEST(MyEquipBuilderMainTest, BuildHelmetByMaterial) {
    MyEquipBuilderMain builderMain;
    std::shared_ptr<EquipWithMaterialBuilder> equipWithMaterialBuilder = std::make_shared<EquipWithMaterialBuilder>();
    std::shared_ptr<EquipBuilder> equipBuilder = std::make_shared<EquipBuilder>();

    std::shared_ptr<Equip> helmet = builderMain.BuildHelmetByMaterial(IronMaterial, equipWithMaterialBuilder, equipBuilder);

    ASSERT_NE(helmet, nullptr);
    ASSERT_EQ(helmet->GetMaterial()->GetName(), "Iron");
}

TEST(MyEquipBuilderMainTest, BuildChestplateByMaterial) {
    MyEquipBuilderMain builderMain;
    std::shared_ptr<EquipWithMaterialBuilder> equipWithMaterialBuilder = std::make_shared<EquipWithMaterialBuilder>();
    std::shared_ptr<EquipBuilder> equipBuilder = std::make_shared<EquipBuilder>();

    std::shared_ptr<Equip> chestplate = builderMain.BuildChestplateByMaterial(DecorativeMaterial, equipWithMaterialBuilder, equipBuilder);

    ASSERT_NE(chestplate, nullptr);
    ASSERT_EQ(chestplate->GetMaterial()->GetName(), "Decorative");
}

TEST(MyEquipBuilderMainTest, BuildBootsByMaterial) {
    MyEquipBuilderMain builderMain;
    std::shared_ptr<EquipWithMaterialBuilder> equipWithMaterialBuilder = std::make_shared<EquipWithMaterialBuilder>();
    std::shared_ptr<EquipBuilder> equipBuilder = std::make_shared<EquipBuilder>();

    std::shared_ptr<Equip> boots = builderMain.BuildBootsByMaterial(GoldMaterial, equipWithMaterialBuilder, equipBuilder);

    ASSERT_NE(boots, nullptr);
    ASSERT_EQ(boots->GetMaterial()->GetName(), "Gold");
}