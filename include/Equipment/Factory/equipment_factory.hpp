#pragma once

#include <cstdlib>
#include <ctime>

#include "../Equip/Builder/MyEquip_Builder/myequip_builder.hpp"
#include "../Equip/Factory/equip_factory_register.hpp"

class EquipmentFactory
{
public:
    virtual std::shared_ptr<MyEquip> CreateEquip() const = 0;
};

class StandartEquipmentFactoryRandom : public EquipmentFactory
{
public:
    std::shared_ptr<MyEquip> CreateEquip() const override
    {
        int start = 0;
        int end = 4;
        int rand1 = std::rand() % (end - start + 1) + start;
        int rand2 = std::rand() % (end - start + 1) + start;
        int rand3 = std::rand() % (end - start + 1) + start;
        
        WhatMaterial helmetMaterial = static_cast<WhatMaterial>(rand1);
        WhatMaterial chestplateMaterial = static_cast<WhatMaterial>(rand2);
        WhatMaterial bootsMaterial = static_cast<WhatMaterial>(rand3);

        std::shared_ptr<Equip> helmet = std::make_shared<Equip>();
        std::shared_ptr<Equip> chestplate = std::make_shared<Equip>();
        std::shared_ptr<Equip> boots = std::make_shared<Equip>();

        std::shared_ptr<MyEquipBuilder> myEquipBuilder = std::make_shared<MyEquipBuilder>();

        
        helmet = EquipFactoryRegister::GetInstance().GetFactoryByEquipTypeId(HelmetId)->CreateEquip(helmetMaterial);
        chestplate = EquipFactoryRegister::GetInstance().GetFactoryByEquipTypeId(ChestplateId)->CreateEquip(chestplateMaterial);
        boots = EquipFactoryRegister::GetInstance().GetFactoryByEquipTypeId(BootsId)->CreateEquip(bootsMaterial);

        myEquipBuilder->Reset();
        myEquipBuilder->SetHelmet(helmet);
        myEquipBuilder->SetChestplate(chestplate);
        myEquipBuilder->SetBoots(boots);

        return std::shared_ptr<MyEquip>(myEquipBuilder->GetResult());
    }
};
