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
    std::string GetWeaponName();
protected:
    void SetAttackDamage(double attackDamage);
    void SetAttackDistance(double attackDistance);
    void SetReloadingTime(float reloadingTime);
    void SetWeaponId(WeaponId id);
    void SetWeaponName(std::string name);
private:
    double attackDamage_;
    double attackDistance_;
    float reloadingTime_;
    WeaponId id_;
    std::string name_;
};
