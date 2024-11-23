#pragma once

#include "../Equip_Builder/equip_builder.hpp"

#include "../../../Material/material_settings.hpp"

#include "../../Derived/helmet.hpp"
#include "../../Derived/chestplate.hpp"
#include "../../Derived/boots.hpp"

class MyEquipBuilderMain
{
public:
    std::shared_ptr<Equip> BuildHelmetByMaterial(WhatMaterial helmetMaterial, std::shared_ptr<EquipBuilder> equipBuilder);
    std::shared_ptr<Equip> BuildChestplateByMaterial(WhatMaterial chestplateMaterial, std::shared_ptr<EquipBuilder> equipBuilder);
    std::shared_ptr<Equip> BuildBootsByMaterial(WhatMaterial bootsMaterial, std::shared_ptr<EquipBuilder> equipBuilder);
};