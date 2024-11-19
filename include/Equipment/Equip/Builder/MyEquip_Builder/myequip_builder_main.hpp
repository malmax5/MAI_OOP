#pragma once

#include "myequip_builder.hpp"

#include "../../../Builder/equip_material_builder_main.hpp"

#include "../Equip_Builder/equip_builder.hpp"
#include "../../../Material/Base/material.hpp"

#include "../../Derived/helmet.hpp"
#include "../../Derived/chestplate.hpp"
#include "../../Derived/boots.hpp"

class MyEquipBuilderMain
{
public:
//     MyEquip* BuildSetByMask(WhatMaterial helmetMaterial, WhatMaterial chestplateMaterial, WhatMaterial bootsMaterial);

// private:
    Helmet* BuildHelmetByMaterial(WhatMaterial helmetMaterial, EquipWithMaterialBuilder& equipWithMaterialBuilder, EquipBuilder& equipBuilder);
    Chestplate* BuildChestplateByMaterial(WhatMaterial chestplateMaterial, EquipWithMaterialBuilder& equipWithMaterialBuilder, EquipBuilder& equipBuilder);
    Boots* BuildBootsByMaterial(WhatMaterial bootsMaterial, EquipWithMaterialBuilder& equipWithMaterialBuilder, EquipBuilder& equipBuilder);
};