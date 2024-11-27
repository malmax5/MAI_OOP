#include "../../../../../include/Equipment/Equip/Factory/boots_factory.hpp"

std::shared_ptr<Equip> BootsFactory::CreateEquip(WhatMaterial id)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Boots>());
    builder->SetMaterial(MaterialByMask(id));
    return builder->GetResult();
}
