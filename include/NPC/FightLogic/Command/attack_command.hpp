#pragma once

#include <cmath>
#include "command_interface.hpp"
#include "../../Base/npc.hpp"

class AttackCommand : public ICommand
{
public:
    AttackCommand(NPC* attacker, NPC* target);
    void execute() final;

public:
    static bool CanAttack(NPC* npc1, NPC* npc2);

private:
    NPC* attacker_;
    NPC* target_;
};