#pragma once

#include "equip_factory_interface.hpp"

#include "../Derived/helmet.hpp"

class HelmetFactory : public IEquipmentFactory {
public:
    std::shared_ptr<Equip> CreateEquip(WhatMaterial id) override;
};