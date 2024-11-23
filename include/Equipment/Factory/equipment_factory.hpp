#pragma once

#include <cstdlib>
#include <ctime>

#include "../Equip/Builder/MyEquip_Builder/myequip_builder.hpp"
#include "../Equip/Builder/Equip_Builder/equip_builder_main.hpp"

class EquipmentFactory
{
public:
    virtual std::shared_ptr<MyEquip> createEquip() const = 0;
};

class StandartEquipmentFactoryRandom : public EquipmentFactory
{
public:
    std::shared_ptr<MyEquip> createEquip() const override
    {
        int start = 0;
        int end = 4;
        int rand1 = std::rand() % (end - start + 1) + start;
        int rand2 = std::rand() % (end - start + 1) + start;
        int rand3 = std::rand() % (end - start + 1) + start;
        
        WhatMaterial helmetMaterial = static_cast<WhatMaterial>(rand1);
        WhatMaterial chestplateMaterial = static_cast<WhatMaterial>(rand2);
        WhatMaterial bootsMaterial = static_cast<WhatMaterial>(rand3);

        std::shared_ptr<Equip> helmet;
        std::shared_ptr<Equip> chestplate;
        std::shared_ptr<Equip> boots;
        std::shared_ptr<MyEquip> equip;

        std::shared_ptr<MyEquipBuilder> myEquipBuilder = std::make_shared<MyEquipBuilder>();
        std::shared_ptr<EquipBuilder> equipBuilder = std::make_shared<EquipBuilder>();
        std::shared_ptr<MyEquipBuilderMain> myEquipBuilderMain = std::make_shared<MyEquipBuilderMain>();

        helmet = myEquipBuilderMain->BuildHelmetByMaterial(helmetMaterial, equipBuilder);
        chestplate = myEquipBuilderMain->BuildChestplateByMaterial(chestplateMaterial, equipBuilder);
        boots = myEquipBuilderMain->BuildBootsByMaterial(bootsMaterial, equipBuilder);

        myEquipBuilder->Reset();
        myEquipBuilder->SetHelmet(helmet);
        myEquipBuilder->SetChestplate(chestplate);
        myEquipBuilder->SetBoots(boots);

        return std::shared_ptr<MyEquip>(myEquipBuilder->GetResult());
    }
};
