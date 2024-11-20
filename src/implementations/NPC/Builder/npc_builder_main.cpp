#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Enums/hp_enum.hpp"
#include "../../../../include/NPC/Enums/armor_enum.hpp"
#include "../../../../include/NPC/Enums/speed_enum.hpp"
#include "../../../../include/NPC/Enums/attack_damage_enum.hpp"
#include "../../../../include/NPC/Enums/attack_distance_enum.hpp"

unsigned int UsageNPCFactory::npcCount = 0;
StandartEquipmentFactoryRandom* UsageNPCFactory::equipFactory = new StandartEquipmentFactoryRandom;

void AgressiveNPCBuilderMain::BuildNPCKnight(AgressiveNPCBuilder* builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(KnightHp);
    builder->SetBaseArmor(KnightArmor);
    builder->SetEquip(UsageNPCFactory::equipFactory->createEquip());
    builder->SetSpeed(KnightSpeed);
    builder->SetAttackDamage(KnightAttackDamage);
    builder->SetAttackDistance(KnightAttackDistance);
}

void PeacefulNPCBuilderMain::BuildNPCPegasus(PeacefulNPCBuilder* builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(PegasusHp);
    builder->SetBaseArmor(PegasusArmor);
    builder->SetEquip(UsageNPCFactory::equipFactory->createEquip());
    builder->SetSpeed(PegasusSpeed);
}

void AgressiveNPCBuilderMain::BuildNPCSquirrel(AgressiveNPCBuilder* builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(SquirrelHp);
    builder->SetBaseArmor(SquirrelArmor);
    builder->SetEquip(UsageNPCFactory::equipFactory->createEquip());
    builder->SetSpeed(SquirrelSpeed);
    builder->SetAttackDamage(SquirrelAttackDamage);
    builder->SetAttackDistance(SquirrelAttackDistance);
}
