#pragma once

#include "npc_builder.hpp"
#include "../../Equipment/Factory/equipment_factory.hpp"

class UsageNPCFactory
{
protected:
    static unsigned int npcCount;
    static StandartEquipmentFactoryRandom* equipFactory;
};

class PeacefulNPCBuilderMain : private UsageNPCFactory
{
public:
    void BuildNPCPegasus(PeacefulNPCBuilder* builder);
};

class AgressiveNPCBuilderMain : private UsageNPCFactory
{
public:
    void BuildNPCKnight(AgressiveNPCBuilder* builder);
    void BuildNPCSquirrel(AgressiveNPCBuilder* builder);
};
