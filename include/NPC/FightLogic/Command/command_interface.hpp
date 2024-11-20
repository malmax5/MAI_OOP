#pragma once

#include <memory>
#include "../../../Positionable/position_funcs.hpp"

class ICommand
{
public:
    virtual ~ICommand() {}
    virtual void execute() {}
};

