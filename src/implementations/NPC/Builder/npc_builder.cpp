#include "../../../../include/NPC/Builder/npc_builder.hpp"

void NPCBuilder::Reset()
{
    npc = new NPC;
}

void NPCBuilder::SetCurrentId(unsigned int currentId)
{
    npc->SetCurrentId(currentId);
}

void NPCBuilder::SetHp(double hp)
{
    npc->SetHp(hp);
}

void NPCBuilder::SetBaseArmor(double armor)
{
    npc->SetBaseArmor(armor);
}

void NPCBuilder::SetEquip(MyEquip* equip)
{
    npc->SetEquip(equip);
}

void NPCBuilder::SetSpeed(double speed)
{
    npc->SetSpeed(speed);
}

NPC* NPCBuilder::GetResult()
{
    return npc;
}
