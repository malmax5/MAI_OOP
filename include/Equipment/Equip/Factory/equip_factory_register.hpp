#pragma once

#include <map>
#include <memory>

#include "../../../Game/game_settings.hpp"
#include "equip_factory_interface.hpp"
#include "helmet_factory.hpp"
#include "chestplate_factory.hpp"
#include "boots_factory.hpp"

using GameSettings::EquipTypeId;

class EquipFactoryRegister
{
public:
    static EquipFactoryRegister& GetInstance();
    std::shared_ptr<IEquipmentFactory> GetFactoryByEquipTypeId(GameSettings::EquipTypeId id);

private:
    EquipFactoryRegister();
    void RegisterAllFactories();

private:
    std::map<GameSettings::EquipTypeId, std::shared_ptr<IEquipmentFactory>> factories;
};