#pragma once

#include <map>
#include <memory>

#include "../Enums/type_id_enum.hpp"
#include "npc_factory_interface.hpp"
#include "knight_factory.hpp"
#include "pegasus_factory.hpp"
#include "squirrel_factory.hpp"

class FactoryRegister
{
public:
    FactoryRegister();
    std::shared_ptr<INPCFactory> GetFactoryByNPCTypeId(NPCId id);

private:
    void RegisterAllFactories();

private:
    std::map<NPCId, std::shared_ptr<INPCFactory>> factories;
};
