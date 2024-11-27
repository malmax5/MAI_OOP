#include "../../../../include/NPC/Derived/knight.hpp"

Knight::Knight()
{
    SetTypeId(NPCId::KnightId);
}

void Knight::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(this);
}

void Knight::Attack(std::shared_ptr<NPC> target)
{
    target->GetDamage(GetAttackDamage());
    Reload();
}

void Knight::Reload()
{
    reloadedTime = Time::GetLastIterTime() + std::chrono::seconds(KnightStat.attackReloading);
}
