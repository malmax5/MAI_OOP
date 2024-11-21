#pragma once

#include "npc.hpp"

class AgressiveNPC : public NPC 
{
    friend class AgressiveNPCBuilder;
    friend class VisitorAddTarget;

public:
    double GetAttackDamage() override;
    double GetAttackDistance() override;
    std::shared_ptr<NPC> GetTarget();

    void AcceptVisitor(std::shared_ptr<Visitor> visitor);

protected:
    void SetAttackDamage(double attackDamage);
    void SetAttackDistance(double attackDistance);
    void SetTarget(std::shared_ptr<NPC> target);

private:
    double attackDamage_;
    double attackDistance_;
    std::shared_ptr<NPC> target_;
};