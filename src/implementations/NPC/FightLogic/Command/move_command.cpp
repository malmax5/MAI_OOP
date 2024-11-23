#include "../../../../../include/NPC/FightLogic/Command/move_command.hpp"

MoveCommand::MoveCommand(std::shared_ptr<NPC> npc, double xDirection, double yDirection)
    : xDirection_(xDirection), yDirection_(yDirection), npc_(npc)
{}

MoveCommand::MoveCommand(std::shared_ptr<NPC> npc, std::shared_ptr<NPC> target)
    : xDirection_(target->GetXCord() - npc->GetXCord()), yDirection_(target->GetYCord() - npc->GetYCord()), npc_(npc)
{}

void MoveCommand::execute(std::function<void(const std::string&)> Notify)
{
    std::stringstream ss;
    ss << npc_->GetCurrentId() << " moved from (" << npc_->GetXCord() << ", " << npc_->GetYCord() << ") to ";
    npc_->Move(xDirection_, yDirection_);
    ss << "(" << npc_->GetXCord() << ", " << npc_->GetYCord() << ")";
    // Notify(ss.str());
}

bool MoveCommand::CanMove(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2)
{
    return npc2->GetHp() > 0 && npc1->GetHp() > 0;
}
