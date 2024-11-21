#pragma once

#include "visitor.hpp"

class GetInfoVisitor : public Visitor
{
public:
    void Visit(Knight* knight) final;
    void Visit(Pegasus* pegasus) final;
    void Visit(Squirrel* squirrel) final;
};
