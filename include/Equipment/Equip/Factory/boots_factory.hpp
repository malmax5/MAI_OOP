#pragma once

#include "equip_factory_interface.hpp"

#include "../Derived/boots.hpp"

class BootsFactory : public IEquipmentFactory {
public:
    std::shared_ptr<Equip> CreateEquip(WhatMaterial id) override;

private:
    std::shared_ptr<EquipBuilder> builder = std::make_shared<EquipBuilder>();
};