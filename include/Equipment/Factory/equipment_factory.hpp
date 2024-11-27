#pragma once

#include <cstdlib>
#include <ctime>

#include "../Equip/Builder/MyEquip_Builder/myequip_builder.hpp"
#include "../Equip/Factory/equip_factory_register.hpp"

#include "../../Game/game_settings.hpp"

using GameSettings::MaterialId;
using GameSettings::EquipTypeId;

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
        
        MaterialId helmetMaterial = static_cast<MaterialId>(rand1);
        MaterialId chestplateMaterial = static_cast<MaterialId>(rand2);
        MaterialId bootsMaterial = static_cast<MaterialId>(rand3);

        std::shared_ptr<Equip> helmet = std::make_shared<Equip>();
        std::shared_ptr<Equip> chestplate = std::make_shared<Equip>();
        std::shared_ptr<Equip> boots = std::make_shared<Equip>();

        std::shared_ptr<MyEquipBuilder> myEquipBuilder = std::make_shared<MyEquipBuilder>();

        
        helmet = EquipFactoryRegister::GetInstance().GetFactoryByEquipTypeId(EquipTypeId::HelmetId)->CreateEquip(helmetMaterial);
        chestplate = EquipFactoryRegister::GetInstance().GetFactoryByEquipTypeId(EquipTypeId::ChestplateId)->CreateEquip(chestplateMaterial);
        boots = EquipFactoryRegister::GetInstance().GetFactoryByEquipTypeId(EquipTypeId::BootsId)->CreateEquip(bootsMaterial);

        myEquipBuilder->Reset();
        myEquipBuilder->SetHelmet(helmet);
        myEquipBuilder->SetChestplate(chestplate);
        myEquipBuilder->SetBoots(boots);

        return std::shared_ptr<MyEquip>(myEquipBuilder->GetResult());
    }
};
