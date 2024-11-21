#include "../../../../include/NPC/Derived/squirrel.hpp"

Squirrel::Squirrel()
{
    SetTypeId(SquirrelId);
    SetName("Squirrel");
}

void Squirrel::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(this);
}
