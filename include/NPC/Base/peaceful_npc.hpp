#pragma once

#include "npc.hpp"

class PeacefulNPC : public NPC 
{
    friend class PeacefulNPCBuilder;
public:
    virtual void AcceptVisitor(std::shared_ptr<Visitor> visitor);

    double GetAttackDistance() override;
    double GetAttackDamage() override;
    bool ReadyToAttack() override;
    void Reload() override;
};