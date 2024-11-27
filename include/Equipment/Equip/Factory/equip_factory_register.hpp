#pragma once

#include <map>
#include <memory>

#include "../equip_type_id.hpp"
#include "equip_factory_interface.hpp"
#include "helmet_factory.hpp"
#include "chestplate_factory.hpp"
#include "boots_factory.hpp"

class EquipFactoryRegister
{
public:
    static EquipFactoryRegister& GetInstance();
    std::shared_ptr<IEquipmentFactory> GetFactoryByEquipTypeId(EquipTypeId id);

private:
    EquipFactoryRegister();
    void RegisterAllFactories();

private:
    std::map<EquipTypeId, std::shared_ptr<IEquipmentFactory>> factories;
};