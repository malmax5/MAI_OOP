#include "../../../../include/NPC/Derived/pegasus.hpp"

Pegasus::Pegasus()
{
    SetTypeId(PegasusId);
}

void Pegasus::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(this);
}
