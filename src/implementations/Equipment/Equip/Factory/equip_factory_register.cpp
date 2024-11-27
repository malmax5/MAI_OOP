#include "../../../../../include/Equipment/Equip/Factory/equip_factory_register.hpp"

EquipFactoryRegister& EquipFactoryRegister::GetInstance()
{
    static EquipFactoryRegister instance;
    return instance;
}

EquipFactoryRegister::EquipFactoryRegister()
{
    RegisterAllFactories();
}

void EquipFactoryRegister::RegisterAllFactories()
{
    factories[EquipTypeId::HelmetId] = std::make_shared<HelmetFactory>();
    factories[EquipTypeId::ChestplateId] = std::make_shared<ChestplateFactory>();
    factories[EquipTypeId::BootsId] = std::make_shared<BootsFactory>();
}

std::shared_ptr<IEquipmentFactory> EquipFactoryRegister::GetFactoryByEquipTypeId(EquipTypeId id)
{
    return factories[id];
}