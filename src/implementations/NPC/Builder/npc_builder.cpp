#include "../../../../include/NPC/Builder/npc_builder.hpp"

#include <iostream>

void PeacefulNPCBuilder::Reset()
{
    npc_ = std::make_shared<PeacefulNPC>();
}

void PeacefulNPCBuilder::SetCurrentId(unsigned int currentId)
{
    npc_->SetCurrentId(currentId);
}

void PeacefulNPCBuilder::SetHp(double hp)
{
    npc_->SetHp(hp);
}

void PeacefulNPCBuilder::SetBaseArmor(double armor)
{
    npc_->SetBaseArmor(armor);
}

void PeacefulNPCBuilder::SetEquip(std::shared_ptr<MyEquip> equip)
{
    npc_->SetEquip(equip);
}

void PeacefulNPCBuilder::SetSpeed(double speed)
{
    npc_->SetSpeed(speed);
}

std::shared_ptr<PeacefulNPC> PeacefulNPCBuilder::GetResult()
{
    return npc_;
}


void AgressiveNPCBuilder::Reset()
{
    npc_ = std::make_shared<AgressiveNPC>();
}

void AgressiveNPCBuilder::SetCurrentId(unsigned int currentId)
{
    npc_->SetCurrentId(currentId);
}

void AgressiveNPCBuilder::SetHp(double hp)
{
    npc_->SetHp(hp);
}

void AgressiveNPCBuilder::SetBaseArmor(double armor)
{
    npc_->SetBaseArmor(armor);
}

void AgressiveNPCBuilder::SetEquip(std::shared_ptr<MyEquip> equip)
{
    npc_->SetEquip(equip);
}

void AgressiveNPCBuilder::SetSpeed(double speed)
{
    npc_->SetSpeed(speed);
}

void AgressiveNPCBuilder::SetAttackDamage(double attackDamage)
{
    npc_->SetAttackDamage(attackDamage);
}

void AgressiveNPCBuilder::SetAttackDistance(double attackDistance)
{
    npc_->SetAttackDistance(attackDistance);
}

std::shared_ptr<AgressiveNPC> AgressiveNPCBuilder::GetResult()
{
    return npc_;
}


void PegasusBuilder::Reset()
{
    npc_ = std::make_shared<Pegasus>();
}


void KnightBuilder::Reset()
{
    npc_ = std::make_shared<Knight>();
}

void SquirrelBuilder::Reset()
{
    npc_ = std::make_shared<Squirrel>();
}
