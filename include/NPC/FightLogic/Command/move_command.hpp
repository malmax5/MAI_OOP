#pragma once

#include "command_interface.hpp"
#include "../../Base/npc.hpp"

#include <cmath>

class MoveCommand : public ICommand
{
public:
    MoveCommand(NPC* npc, double xDirection, double yDirection);
    MoveCommand(NPC* npc, NPC* target);
    void execute() final;

private:
    NPC* npc_;
    double xDirection_;
    double yDirection_;
};