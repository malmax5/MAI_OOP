#pragma once

#include "../../../Positionable/position_funcs.hpp"

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

