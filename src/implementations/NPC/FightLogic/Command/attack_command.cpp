#include "../../../../../include/NPC/FightLogic/Command/attack_command.hpp"

AttackCommand::AttackCommand(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)
    : attacker_(attacker), target_(target)
{}

void AttackCommand::execute(std::function<void(const std::string&)> Notify)
{
    target_->SetHp(target_->GetHp() - attacker_->GetAttackDamage() * (1 - (target_->GetArmor() / 240)));
    std::stringstream ss;
    ss << attacker_->GetCurrentId() << " attacked a " << target_->GetCurrentId();
    Notify(ss.str());
}

bool AttackCommand::CanAttack(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)
{
    double dist =  NPCPositionFuncs::DistanceBetNPC(attacker, target);
    return target->GetHp() > 0 && (attacker->GetAttackDistance() - dist) >= 0;
}
