#include "../../../../include/NPC/Derived/squirrel.hpp"

Squirrel::Squirrel()
{
    LogCreate();
    SetTypeId(NPCId::SquirrelId);
}

Squirrel::~Squirrel()
{

}

void Squirrel::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(this);
}

void Squirrel::Attack(std::shared_ptr<NPC> target)
{
    target->GetDamage(GetAttackDamage());
    Reload();
}

std::string Squirrel::GetClassName()
{
    return demangle(typeid(*this).name());
}

// void Squirrel::Reload()
// {
//     reloadedTime = Time::GetLastIterTime() + std::chrono::seconds(SquirrelStat.attackReloading);
// }
