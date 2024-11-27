#include "../../../../include/Equipment/Material/material_settings.hpp"

std::shared_ptr<Material> MaterialByMask(MaterialId materialId)
{
    std::shared_ptr<Material> material;
    
    switch (materialId)
    {
    case MaterialId::NoMaterialMaterial:
        material = std::make_shared<NoMaterial>();
        break;
    case MaterialId::DecorativeMaterial:
        material = std::make_shared<Decorative>();
        break;
    case MaterialId::IronMaterial:
        material = std::make_shared<Iron>();
        break;
    case MaterialId::GoldMaterial:
        material = std::make_shared<Gold>();
        break;
    case MaterialId::DiamondMaterial:
        material = std::make_shared<Diamond>();
        break;
    
    default:
        break;
    }

    return material;
}