#include "../../../../../include/Equipment/Equip/Factory/helmet_factory.hpp"

std::shared_ptr<Equip> HelmetFactory::CreateEquip(WhatMaterial id)
{
    std::shared_ptr<EquipBuilder> builder = std::make_shared<EquipBuilder>();
    builder->Reset();
    builder->SetEquip(std::make_shared<Helmet>());
    builder->SetMaterial(MaterialByMask(id));
    return builder->GetResult();
}
