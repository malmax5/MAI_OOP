#pragma once

#include <cstdlib>
#include <ctime>
#include <memory>

#include "../Base/weapon.hpp"
#include "../weapon_settings.hpp"
#include "../../Game/game_settings.hpp"

using GameSettings::WeaponId;

class WeaponFactory
{
public:
    virtual std::shared_ptr<Weapon> CreateWeapon() const = 0;
};

class StandartWeaponFactoryRandom : public WeaponFactory
{
public:
    std::shared_ptr<Weapon> CreateWeapon() const override
    {
        int start = 0;
        int end = 6;
        int rand = std::rand() % (end - start + 1) + start;
        
        WeaponId weaponId = static_cast<WeaponId>(rand);

        std::shared_ptr<Weapon> weapon = WeaponByMask(weaponId);

        return weapon;
    }
};
