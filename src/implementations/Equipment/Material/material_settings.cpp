#include "../../../../include/Equipment/Material/material_settings.hpp"

std::shared_ptr<Material> MaterialByMask(WhatMaterial materialId)
{
    std::shared_ptr<Material> material;
    
    switch (materialId)
    {
    case NoMaterialMaterial:
        material = std::make_shared<NoMaterial>();
        break;
    case DecorativeMaterial:
        material = std::make_shared<Decorative>();
        break;
    case IronMaterial:
        material = std::make_shared<Iron>();
        break;
    case GoldMaterial:
        material = std::make_shared<Gold>();
        break;
    case DimondMaterial:
        material = std::make_shared<Dimond>();
        break;
    
    default:
        break;
    }

    return material;
}