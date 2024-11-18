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
    MyEquip* BuildSetByMask(int helmetMaterial, int chestplateMaterial, int bootsMaterial);
};