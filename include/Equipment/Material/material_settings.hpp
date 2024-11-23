#pragma once

#include <memory>
#include "Base/material.hpp"
#include "Derived/no_material.hpp"
#include "Derived/decorative.hpp"
#include "Derived/iron.hpp"
#include "Derived/gold.hpp"
#include "Derived/dimond.hpp"

enum ArmorMultiple
{
    NoMaterialMultiple = 0,
    DecorativeMultiple = 1,
    IronMultiple = 2,
    GoldMultiple = 3,
    DimondMultiple = 4
};

enum WhatMaterial
{
    NoMaterialMaterial = 0,
    DecorativeMaterial = 1,
    IronMaterial = 2,
    GoldMaterial = 3,
    DimondMaterial = 4
};

std::shared_ptr<Material> MaterialByMask(WhatMaterial materialId)
{
    Material* material;
    
    switch (materialId)
    {
    case NoMaterialMaterial:
        material = new NoMaterial;
        break;
    case DecorativeMaterial:
        material = new Decorative;
        break;
    case IronMaterial:
        material = new Iron;
        break;
    case GoldMaterial:
        material = new Gold;
        break;
    case DimondMaterial:
        break;
    
    default:
        break;
    }

    return std::shared_ptr<Material>(material);
}
