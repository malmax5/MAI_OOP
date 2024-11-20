#include "../../../../../include/NPC/FightLogic/Command/move_command.hpp"

#include <iostream>

MoveCommand::MoveCommand(NPC* npc, double xDirection, double yDirection)
    : xDirection_(xDirection), yDirection_(yDirection), npc_(npc)
{}

MoveCommand::MoveCommand(NPC* npc, NPC* target)
    : xDirection_(target->GetXCord() - npc->GetXCord()), yDirection_(target->GetYCord() - npc->GetYCord()), npc_(npc)
{}

void MoveCommand::execute()
{
    double speed = npc_->GetSpeed();
    double kNorm = sqrt(pow(xDirection_, 2) + pow(yDirection_, 2));
    double newX = npc_->GetXCord() + xDirection_ / kNorm;
    double newY = npc_->GetYCord() + yDirection_ / kNorm;
    npc_->SetPosition(newX, newY);
}
