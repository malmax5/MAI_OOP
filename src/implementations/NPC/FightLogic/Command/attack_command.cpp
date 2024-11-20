#include "../../../../../include/NPC/FightLogic/Command/attack_command.hpp"

AttackCommand::AttackCommand(NPC* attacker, NPC* target)
    : attacker_(attacker), target_(target)
{}

void AttackCommand::execute()
{

    target_->SetHp(target_->GetHp() - attacker_->GetAttackDamage());
}

bool AttackCommand::CanAttack(NPC* attacker, NPC* target)
{
    double dist =  NPCPositionFuncs::DistanceBetNPC(attacker, target);
    return target->GetHp() > 0 && (attacker->GetAttackDistance() - dist) >= 0;
}
