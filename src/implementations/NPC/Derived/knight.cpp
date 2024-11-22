#include "../../../../include/NPC/Derived/knight.hpp"

Knight::Knight()
{
    SetTypeId(KnightId);
}

void Knight::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(this);
}
