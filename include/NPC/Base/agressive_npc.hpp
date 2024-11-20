#pragma once

#include "npc.hpp"

class AgressiveNPC : public NPC 
{
    friend class AgressiveNPCBuilder;
    friend class VisitorAddTarget;

public:
    double GetAttackDamage() override;
    double GetAttackDistance() override;
    NPC* GetTarget();

protected:
    void SetAttackDamage(double attackDamage);
    void SetAttackDistance(double attackDistance);
    void SetTarget(NPC* target);

private:
    double attackDamage_;
    double attackDistance_;
    NPC* target_;
};