#pragma once

#include "npc.hpp"

class IAttackable
{
public:
    virtual double GetAttackDistance() const = 0;
    virtual double GetAttackDamage() const = 0;
    virtual bool ReadyToAttack() const = 0;
    virtual void Reload() = 0;
    virtual void Attack(std::shared_ptr<NPC> target) = 0;
    virtual void SwitchReadyToAttackInFalse() = 0;
};
