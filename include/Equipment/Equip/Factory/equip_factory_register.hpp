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
    EquipFactoryRegister();
    std::shared_ptr<IEquipmentFactory> GetFactoryByEquipTypeId(EquipTypeId id);

private:
    void RegisterAllFactories();

private:
    std::map<EquipTypeId, std::shared_ptr<IEquipmentFactory>> factories;
};
