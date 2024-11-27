#pragma once

#include "npc.hpp"
#include "../Enums/reloading.hpp"
#include "attackable_interface.hpp"

class AgressiveNPC : public NPC, public IAttackable
{
    friend class AgressiveNPCBuilder;

public:
    virtual void AcceptVisitor(std::shared_ptr<Visitor> visitor) override = 0;

    double GetAttackDistance() const override;
    double GetAttackDamage() const override;
    bool ReadyToAttack() const override;
    void Reload() override;

protected:
    void SetAttackDamage(double attackDamage) override;
    void SetAttackDistance(double attackDistance) override;

protected:
    double attackDamage_;
    double attackDistance_;
    std::chrono::system_clock::time_point reloadedTime = std::chrono::system_clock::now();
};