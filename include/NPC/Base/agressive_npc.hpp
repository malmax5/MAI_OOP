#pragma once

#include "npc.hpp"
#include "../Enums/reloading.hpp"

class AgressiveNPC : public NPC 
{
    friend class AgressiveNPCBuilder;
    friend class VisitorAddTarget;

public:
    virtual void AcceptVisitor(std::shared_ptr<Visitor> visitor);

    double GetAttackDistance() override;
    double GetAttackDamage() override;
    bool ReadyToAttack() override;
    void Reload() override;

protected:
    void SetAttackDamage(double attackDamage);
    void SetAttackDistance(double attackDistance);

protected:
    double attackDamage_;
    double attackDistance_;
    std::chrono::system_clock::time_point reloadedTime = std::chrono::system_clock::now();
};