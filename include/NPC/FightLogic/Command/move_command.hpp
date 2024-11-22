#pragma once

#include "command_interface.hpp"
#include "../../Base/npc.hpp"

#include <cmath>

class MoveCommand : public ICommand
{
public:
    MoveCommand(std::shared_ptr<NPC> npc, double xDirection, double yDirection);
    MoveCommand(std::shared_ptr<NPC> npc, std::shared_ptr<NPC> target);
    void execute(std::function<void(const std::string&)> Notify) final;

private:
    std::shared_ptr<NPC> npc_;
    double xDirection_;
    double yDirection_;
};