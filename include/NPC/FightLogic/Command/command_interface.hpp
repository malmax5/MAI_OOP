#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <functional>
#include "../../../Positionable/position_funcs.hpp"

class ICommand
{
public:
    virtual ~ICommand() {}
    virtual void execute(std::function<void(const std::string&)> Notify) {}
};

