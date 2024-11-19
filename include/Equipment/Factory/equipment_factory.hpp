#pragma once

#include <cstdlib>
#include <ctime>

#include "../Equip/Builder/MyEquip_Builder/myequip_builder.hpp"
#include "../Builder/equip_material_builder_main.hpp"
#include "../Equip/Builder/MyEquip_Builder/myequip_builder_main.hpp"

class EquipmentFactory
{
public:
    virtual MyEquip* createEquip() const = 0;
};

class StandartEquipmentFactoryRandom : public EquipmentFactory
{
public:
    MyEquip* createEquip() const override
    {
        std::srand(static_cast<unsigned int>(time(0)));

        WhatMaterial helmetMaterial = static_cast<WhatMaterial>(std::rand() % 5);
        WhatMaterial chestplateMaterial = static_cast<WhatMaterial>(std::rand() % 5);
        WhatMaterial bootsMaterial = static_cast<WhatMaterial>(std::rand() % 5);

        Helmet* helmet;
        Chestplate* chestplate;
        Boots* boots;
        MyEquip* equip;

        MyEquipBuilder myEquipBuilder;
        EquipWithMaterialBuilder equipWithMaterialBuilder;
        EquipBuilder equipBuilder;
        MyEquipBuilderMain myEquipBuilderMain;

        helmet = myEquipBuilderMain.BuildHelmetByMaterial(helmetMaterial, equipWithMaterialBuilder, equipBuilder);
        chestplate = myEquipBuilderMain.BuildChestplateByMaterial(chestplateMaterial, equipWithMaterialBuilder, equipBuilder);
        boots = myEquipBuilderMain.BuildBootsByMaterial(bootsMaterial, equipWithMaterialBuilder, equipBuilder);

        myEquipBuilder.Reset();
        myEquipBuilder.SetHelmet(helmet);
        myEquipBuilder.SetChestplate(chestplate);
        myEquipBuilder.SetBoots(boots);

        equip = myEquipBuilder.GetResult();

        return equip;
    }
};
