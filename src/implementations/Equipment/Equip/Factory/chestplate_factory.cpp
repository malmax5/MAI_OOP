#include "../../../../../include/Equipment/Equip/Factory/chestplate_factory.hpp"

std::shared_ptr<Equip> ChestplateFactory::CreateEquip(WhatMaterial id)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Chestplate>());
    builder->SetMaterial(MaterialByMask(id));
    return builder->GetResult();
}
