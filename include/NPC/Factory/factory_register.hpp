#pragma once

#include <map>
#include <memory>

#include "../../Game/game_settings.hpp"

#include "npc_factory_interface.hpp"
#include "knight_factory.hpp"
#include "pegasus_factory.hpp"
#include "squirrel_factory.hpp"

using GameSettings::NPCId;

class FactoryRegister
{
public:
    static FactoryRegister& GetInstance();
    std::shared_ptr<INPCFactory> GetFactoryByNPCTypeId(NPCId id);

private:
    FactoryRegister();
    void RegisterAllFactories();

private:
    std::map<NPCId, std::shared_ptr<INPCFactory>> factories;
};
