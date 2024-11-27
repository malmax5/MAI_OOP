#include "../../../../include/NPC/Derived/squirrel.hpp"

Squirrel::Squirrel()
{
    SetTypeId(NPCId::SquirrelId);
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

void Squirrel::Reload()
{
    reloadedTime = Time::GetLastIterTime() + std::chrono::seconds(SquirrelStat.attackReloading);
}
