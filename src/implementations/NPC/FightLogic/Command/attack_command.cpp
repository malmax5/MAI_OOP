#include "../../../../../include/NPC/FightLogic/Command/attack_command.hpp"

AttackCommand::AttackCommand(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)
    : attacker_(attacker), target_(target)
{}

void AttackCommand::execute(std::function<void(const std::string&)> Notify)
{
    if (attacker_ && target_ && attacker_->GetHp() > 0 && target_->GetHp() > 0 && std::dynamic_pointer_cast<IAttackable>(attacker_)->ReadyToAttack())
    {
        std::dynamic_pointer_cast<IAttackable>(attacker_)->Attack(target_);
        std::stringstream ss;
        ss << attacker_->GetCurrentId() << " attacked a " << target_->GetCurrentId();
        Notify(ss.str());
    }
}

bool AttackCommand::CanAttackNow(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)
{
    if(!std::dynamic_pointer_cast<IAttackable>(attacker))
    {
        return false;
    }
    
    double dist =  NPCPositionFuncs::DistanceBetNPC(attacker, target);
    return std::dynamic_pointer_cast<IAttackable>(attacker)->ReadyToAttack() && target->GetHp() > 0 && (std::dynamic_pointer_cast<IAttackable>(attacker)->GetAttackDistance() - dist) >= 0;
}

bool AttackCommand::CanAttack(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)
{
    if(!std::dynamic_pointer_cast<IAttackable>(attacker))
    {
        return false;
    }
    
    double dist =  NPCPositionFuncs::DistanceBetNPC(attacker, target);
    return (std::dynamic_pointer_cast<IAttackable>(attacker)->GetAttackDistance() - dist) >= 0;
}
