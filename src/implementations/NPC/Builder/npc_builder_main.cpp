#include "../../../../include/NPC/Builder/npc_builder_main.hpp"

unsigned int UsageNPCFactory::npcCount = 0;
std::shared_ptr<StandartEquipmentFactoryRandom> UsageNPCFactory::equipFactory = std::make_shared<StandartEquipmentFactoryRandom>();

void AgressiveNPCBuilderMain::BuildNPCKnight(std::shared_ptr<KnightBuilder> builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(KnightStat.hp);
    builder->SetBaseArmor(KnightStat.armor);
    builder->SetEquip(UsageNPCFactory::equipFactory->CreateEquip());
    builder->SetSpeed(KnightStat.speed);
    builder->SetAttackDamage(KnightStat.attackDamage);
    builder->SetAttackDistance(KnightStat.attackDistance);
}

void PeacefulNPCBuilderMain::BuildNPCPegasus(std::shared_ptr<PegasusBuilder> builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(PegasusStat.hp);
    builder->SetBaseArmor(PegasusStat.armor);
    builder->SetEquip(UsageNPCFactory::equipFactory->CreateEquip());
    builder->SetSpeed(PegasusStat.speed);
}

void AgressiveNPCBuilderMain::BuildNPCSquirrel(std::shared_ptr<SquirrelBuilder> builder)
{
    builder->Reset();
    builder->SetCurrentId(npcCount++);
    builder->SetHp(SquirrelStat.hp);
    builder->SetBaseArmor(SquirrelStat.armor);
    builder->SetEquip(UsageNPCFactory::equipFactory->CreateEquip());
    builder->SetSpeed(SquirrelStat.speed);
    builder->SetAttackDamage(SquirrelStat.attackDamage);
    builder->SetAttackDistance(SquirrelStat.attackDistance);
}
