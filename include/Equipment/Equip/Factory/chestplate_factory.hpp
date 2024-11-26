#pragma once

#include "equip_factory_interface.hpp"

#include "../Derived/chestplate.hpp"

class ChestplateFactory : public IEquipmentFactory {
public:
    std::shared_ptr<Equip> CreateEquip(WhatMaterial id) override;
};