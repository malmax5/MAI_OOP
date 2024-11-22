#pragma once

#include "npc.hpp"

class AgressiveNPC : public NPC 
{
    friend class AgressiveNPCBuilder;
    friend class VisitorAddTarget;

public:
    virtual void AcceptVisitor(std::shared_ptr<Visitor> visitor);

    double GetAttackDistance() override;
    double GetAttackDamage() override;

protected:
    void SetAttackDamage(double attackDamage);
    void SetAttackDistance(double attackDistance);

private:
    double attackDamage_;
    double attackDistance_;
};