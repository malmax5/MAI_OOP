#pragma once

#include "../../Game/game_settings.hpp"
#include "../../CRTP/creating_logger.hpp"

using namespace GameSettings;

class Weapon
{
public:
    double GetAttackDamage();
    double GetAttackDistance();
    double GetReloadingTime();
    WeaponId GetWeaponId();
protected:
    void SetAttackDamage(double attackDamage);
    void SetAttackDistance(double attackDistance);
    void SetReloadingTime(double reloadingTime);
    void SetWeaponId(WeaponId id);
private:
    double attackDamage_;
    double attackDistance_;
    double reloadingTime_;

    WeaponId id_;
};
