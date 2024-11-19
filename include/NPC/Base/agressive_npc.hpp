#pragma once

#include "npc.hpp"

class AgressiveNPC : public NPC 
{
public:
    double GetAttackDamage();
    double GetAttackDistance();
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