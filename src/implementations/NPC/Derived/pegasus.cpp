#include "../../../../include/NPC/Derived/pegasus.hpp"

Pegasus::Pegasus()
{
    LogCreate();
    SetTypeId(NPCId::PegasusId);
}

Pegasus::~Pegasus()
{
    
}

void Pegasus::AcceptVisitor(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(this);
}

std::string Pegasus::GetClassName()
{
    return demangle(typeid(*this).name());
}
