#include "../../../../include/NPC/Base/npc.hpp"

NPCId NPC::GetTypeId()
{
    return typeId_;
}

std::string NPC::GetName()
{
    return name_;
}

unsigned int NPC::GetCurrentId()
{
    return currentId_;
}

double NPC::GetHp()
{
    return hp_;
}

double NPC::GetArmor()
{
    return totalArmor_;
}

double NPC::GetSpeed()
{
    return speed_;
}

double NPC::GetAttackDamage()
{
    return 0;
}

double NPC::GetAttackDistance()
{
    return 0;
}

void NPC::SetTypeId(NPCId typeId)
{
    typeId_ = typeId;
}

void NPC::SetName(std::string name)
{
    name_ = name;
}

void NPC::SetCurrentId(unsigned int currentId)
{
    currentId_ = currentId;
}

void NPC::SetHp(double hp)
{
    hp_ = hp;
}

void NPC::SetBaseArmor(double armor)
{
    armor_ = armor;
    totalArmor_ += armor;
}

void NPC::SetEquip(std::shared_ptr<MyEquip> equip)
{
    equip_ = equip;
    totalArmor_ += equip_->TotalArmor();
}

void NPC::SetSpeed(double speed)
{
    speed_ = speed;
}

void NPC::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    
}
