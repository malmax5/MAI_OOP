#pragma once

#include "equip_factory_interface.hpp"

#include "../Derived/helmet.hpp"

class HelmetFactory : public IEquipmentFactory {
public:
    std::shared_ptr<Equip> CreateEquip(GameSettings::MaterialId id) override;

private:
    std::shared_ptr<EquipBuilder> builder = std::make_shared<EquipBuilder>();
};