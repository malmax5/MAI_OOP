#pragma once

#include "npc_builder.hpp"
#include "../../Equipment/Factory/equipment_factory.hpp"
#include "../../Weapon/Factory/weapon_factory.hpp"
#include "../../Game/game_settings.hpp"

using namespace GameSettings;

class UsageNPCFactory
{
protected:
    static unsigned int npcCount;
    static std::shared_ptr<StandartEquipmentFactoryRandom> equipFactory;
    static std::shared_ptr<StandartWeaponFactoryRandom> weaponFactory;
};

class PeacefulNPCBuilderMain : private UsageNPCFactory
{
public:
    void BuildNPCPegasus(std::shared_ptr<PegasusBuilder> builder);
};

class AgressiveNPCBuilderMain : private UsageNPCFactory
{
public:
    void BuildNPCKnight(std::shared_ptr<KnightBuilder> builder);
    void BuildNPCSquirrel(std::shared_ptr<SquirrelBuilder> builder);
};
