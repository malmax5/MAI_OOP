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
    virtual std::string GetClassName() override = 0;
    virtual void Attack(std::shared_ptr<NPC> target) override = 0;

    std::string GetWeaponName();
    WeaponId GetWeaponId();
    double GetAttackDistance() const override;
    double GetAttackDamage() const override;
    bool ReadyToAttack() const override;
    void Reload() override;
    void SwitchReadyToAttackInFalse() override;

protected:
    void SetWeapon(std::shared_ptr<Weapon> weapon);

protected:
    std::shared_ptr<Weapon> weapon_;
    double attackDamage_;
    double attackDistance_;
    std::chrono::system_clock::time_point reloadedTime = std::chrono::system_clock::now();
    bool readyToAttack_ = true;

    struct ReloadingAwaitable {
        float reloadingTime;
        bool await_ready() const noexcept { return false; }
        void await_suspend(std::coroutine_handle<> h) const {
            std::thread([this, h]() {
                std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(reloadingTime)));
                h.resume();
            }).detach();
        }
        void await_resume() const noexcept {}
    };

    struct ReloadingCoroutine {
        struct promise_type {
            ReloadingCoroutine get_return_object() { return {}; }
            std::suspend_never initial_suspend() { return {}; }
            std::suspend_never final_suspend() noexcept { return {}; }
            void return_void() {}
            void unhandled_exception() {}
        };
    };

    ReloadingCoroutine ReloadingCoroutine() {
        readyToAttack_ = false;
        co_await ReloadingAwaitable{weapon_->GetReloadingTime()};
        readyToAttack_ = true;
    }
};