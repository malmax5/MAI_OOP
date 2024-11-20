#pragma once

#include <cmath>
#include "command_interface.hpp"
#include "../../Base/npc.hpp"

class AttackCommand : public ICommand
{
public:
    AttackCommand(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target);
    void execute() final;

public:
    static bool CanAttack(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2);

private:
    std::shared_ptr<NPC> attacker_;
    std::shared_ptr<NPC> target_;
};