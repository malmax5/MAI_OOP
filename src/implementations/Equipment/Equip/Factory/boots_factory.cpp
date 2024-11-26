#include "../../../../../include/Equipment/Equip/Factory/boots_factory.hpp"

std::shared_ptr<Equip> BootsFactory::CreateEquip(WhatMaterial id)
{
    std::shared_ptr<EquipBuilder> builder = std::make_shared<EquipBuilder>();
    builder->Reset();
    builder->SetEquip(std::make_shared<Boots>());
    builder->SetMaterial(MaterialByMask(id));
    return builder->GetResult();
}
