#pragma once

#include <memory>

#include "../../Material/enums.hpp"
#include "../Base/equip.hpp"
#include "../Builder/Equip_Builder/equip_builder.hpp" 
#include "../../Material/material_settings.hpp"

class IEquipmentFactory {
public:
    virtual std::shared_ptr<Equip> CreateEquip(WhatMaterial id) = 0;
};