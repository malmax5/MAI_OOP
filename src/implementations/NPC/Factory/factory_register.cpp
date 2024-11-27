#include "../../../../include/NPC/Factory/factory_register.hpp"

FactoryRegister& FactoryRegister::GetInstance()
{
    static FactoryRegister instance;
    return instance;
}

FactoryRegister::FactoryRegister()
{
    RegisterAllFactories();
}

void FactoryRegister::RegisterAllFactories()
{
    factories[NPCId::KnightId] = std::make_shared<KnightFactory>();
    factories[NPCId::PegasusId] = std::make_shared<PegasusFactory>();
    factories[NPCId::SquirrelId] = std::make_shared<SquirrelFactory>();
}

std::shared_ptr<INPCFactory> FactoryRegister::GetFactoryByNPCTypeId(NPCId id)
{
    return factories[id];
}
