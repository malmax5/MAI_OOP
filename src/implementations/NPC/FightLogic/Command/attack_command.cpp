#include "../../../../../include/NPC/FightLogic/Command/attack_command.hpp"

AttackCommand::AttackCommand(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)
    : attacker_(attacker), target_(target)
{}

void AttackCommand::execute()
{

    target_->SetHp(target_->GetHp() - attacker_->GetAttackDamage());
}

bool AttackCommand::CanAttack(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)
{
    double dist =  NPCPositionFuncs::DistanceBetNPC(attacker, target);
    return target->GetHp() > 0 && (attacker->GetAttackDistance() - dist) >= 0;
}
