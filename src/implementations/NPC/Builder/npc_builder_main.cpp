#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Enums/hp_enum.hpp"
#include "../../../../include/NPC/Enums/armor_enum.hpp"
#include "../../../../include/NPC/Enums/speed_enum.hpp"

unsigned int NPCBuilderMain::npcCount = 0;
StandartEquipmentFactoryRandom* NPCBuilderMain::equipFactory = new StandartEquipmentFactoryRandom;

void NPCBuilderMain::BuildNPCKnight(NPCBuilder* builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(KnightHp);
    builder->SetBaseArmor(KnightArmor);
    builder->SetEquip(NPCBuilderMain::equipFactory->createEquip());
    builder->SetSpeed(KnightSpeed);
}

void NPCBuilderMain::BuildNPCPegasus(NPCBuilder* builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(PegasusHp);
    builder->SetBaseArmor(PegasusArmor);
    builder->SetEquip(NPCBuilderMain::equipFactory->createEquip());
    builder->SetSpeed(PegasusSpeed);
}

void NPCBuilderMain::BuildNPCSquirrel(NPCBuilder* builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(SquirrelHp);
    builder->SetBaseArmor(SquirrelArmor);
    builder->SetEquip(NPCBuilderMain::equipFactory->createEquip());
    builder->SetSpeed(SquirrelSpeed);
}
