#pragma once

#include <cmath>
#include <sstream>
#include "command_interface.hpp"
#include "../../Base/npc.hpp"
#include "../../Base/attackable_interface.hpp"

class AttackCommand : public ICommand
{
public:
    AttackCommand(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target);
    void execute(std::function<void(const std::string&)> Notify) final;

public:
    static bool CanAttackNow(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2);
    static bool CanAttack(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2);

private:
    std::shared_ptr<NPC> attacker_;
    std::shared_ptr<NPC> target_;
};