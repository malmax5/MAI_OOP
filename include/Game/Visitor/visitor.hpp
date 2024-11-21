#pragma once

#include <iostream>
#include <memory>

class Knight;
class Pegasus;
class Squirrel;

class Visitor
{
public:
    virtual void Visit(Knight* knight) = 0;
    virtual void Visit(Pegasus* pegasus) = 0;
    virtual void Visit(Squirrel* knight) = 0;
};
