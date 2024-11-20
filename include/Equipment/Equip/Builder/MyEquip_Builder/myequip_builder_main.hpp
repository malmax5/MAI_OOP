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
    std::shared_ptr<Equip> BuildHelmetByMaterial(WhatMaterial helmetMaterial, std::shared_ptr<EquipWithMaterialBuilder> equipWithMaterialBuilder, std::shared_ptr<EquipBuilder> equipBuilder);
    std::shared_ptr<Equip> BuildChestplateByMaterial(WhatMaterial chestplateMaterial, std::shared_ptr<EquipWithMaterialBuilder> equipWithMaterialBuilder, std::shared_ptr<EquipBuilder> equipBuilder);
    std::shared_ptr<Equip> BuildBootsByMaterial(WhatMaterial bootsMaterial, std::shared_ptr<EquipWithMaterialBuilder> equipWithMaterialBuilder, std::shared_ptr<EquipBuilder> equipBuilder);
};