#pragma once

#include <memory>

#include "npc.hpp"
#include "attackable_interface.hpp"
#include "../../Weapon/Base/weapon.hpp"

class AgressiveNPC : public NPC, public IAttackable
{
    friend class AgressiveNPCBuilder;

public:
    virtual void AcceptVisitor(std::shared_ptr<Visitor> visitor) override = 0;
    virtual void Attack(std::shared_ptr<NPC> target) override = 0;

    double GetAttackDistance() const override;
    double GetAttackDamage() const override;
    bool ReadyToAttack() const override;
    void Reload() override;
    GameSettings::WeaponId GetWeaponId();

protected:
    void SetWeapon(std::shared_ptr<Weapon> weapon);

protected:
    std::shared_ptr<Weapon> weapon_;
    double attackDamage_;
    double attackDistance_;
    std::chrono::system_clock::time_point reloadedTime = std::chrono::system_clock::now();
};