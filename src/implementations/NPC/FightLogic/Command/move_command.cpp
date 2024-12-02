#include "../../../../../include/NPC/FightLogic/Command/move_command.hpp"
#include "../../../../../include/NPC/FightLogic/Command/attack_command.hpp"

// MoveCommand::MoveCommand(std::shared_ptr<NPC> npc, double xDirection, double yDirection)
//     : xDirection_(xDirection), yDirection_(yDirection), npc_(npc)
// {}

MoveCommand::MoveCommand(std::shared_ptr<NPC> npc, std::shared_ptr<NPC> target)
    : npc_(npc), target_(target)
{}

void MoveCommand::execute(std::function<void(const std::string&)> Notify)
{
    if (npc_)
        npc_->Move(target_->GetXCord() - npc_->GetXCord(), target_->GetYCord() - npc_->GetYCord());
}

bool MoveCommand::CanMove(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2)
{
    return npc2->GetHp() > 0 && npc1->GetHp() > 0;
}
