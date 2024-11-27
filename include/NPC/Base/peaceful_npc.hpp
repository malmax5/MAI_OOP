#pragma once

#include "npc.hpp"

class PeacefulNPC : public NPC 
{
public:
    virtual void AcceptVisitor(std::shared_ptr<Visitor> visitor) override = 0;

    // double GetAttackDistance() override;
    // double GetAttackDamage() override;
    // bool ReadyToAttack() override;
    // void Reload() override;
};