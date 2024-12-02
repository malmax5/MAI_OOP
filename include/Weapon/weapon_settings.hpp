#pragma once

#include <memory>
#include "../Game/game_settings.hpp"
#include "Base/weapon.hpp"
#include "Derived/automatic_rifle.hpp"
#include "Derived/katana.hpp"
#include "Derived/knife.hpp"
#include "Derived/machine_gun.hpp"
#include "Derived/pistol.hpp"
#include "Derived/sniper_rifle.hpp"

using GameSettings::WeaponId;

std::shared_ptr<Weapon> WeaponByMask(WeaponId weaponId);
