#pragma once

#include "../../Game/game_settings.hpp"
#include "../../CRTP/creating_logger.hpp"

using namespace GameSettings;

class Weapon
{
public:
    virtual double GetAttackDamage();
    virtual double GetAttackDistance();
    virtual double GetReloadingTime();
protected:
    virtual void SetAttackDamage(double attackDamage);
    virtual void SetAttackDistance(double attackDistance);
    virtual void SetReloadingTime(double reloadingTime);
private:
    double attackDamage_;
    double attackDistance_;
    double reloadingTime_;
};
