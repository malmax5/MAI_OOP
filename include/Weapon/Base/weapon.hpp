#pragma once

#include "../../Game/game_settings.hpp"
#include "../../CRTP/creating_logger.hpp"

using namespace GameSettings;

class Weapon
{
public:
    double GetAttackDamage();
    double GetAttackDistance();
    float GetReloadingTime();
    WeaponId GetWeaponId();
protected:
    void SetAttackDamage(double attackDamage);
    void SetAttackDistance(double attackDistance);
    void SetReloadingTime(float reloadingTime);
    void SetWeaponId(WeaponId id);
private:
    double attackDamage_;
    double attackDistance_;
    float reloadingTime_;

    WeaponId id_;
};
