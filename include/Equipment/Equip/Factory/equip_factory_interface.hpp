#pragma once

#include <memory>

#include "../Base/equip.hpp"
#include "../Builder/Equip_Builder/equip_builder.hpp" 
#include "../../../Game/game_settings.hpp"
#include "../../Material/material_settings.hpp"

class IEquipmentFactory {
public:
    virtual std::shared_ptr<Equip> CreateEquip(GameSettings::MaterialId id) = 0;
};