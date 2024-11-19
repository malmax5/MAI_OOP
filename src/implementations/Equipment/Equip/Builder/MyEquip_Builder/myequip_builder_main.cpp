#include "../../../../../../include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_main.hpp"


// MyEquip* MyEquipBuilderMain::BuildSetByMask(WhatMaterial helmetMaterial, WhatMaterial chestplateMaterial, WhatMaterial bootsMaterial)
// {
//     Helmet* helmet;
//     Chestplate* chestplate;
//     Boots* boots;
//     MyEquip* equip;

//     MyEquipBuilder myEquipBuilder;
//     EquipWithMaterialBuilder equipWithMaterialBuilder;
//     EquipBuilder equipBuilder;

//     helmet = BuildHelmetByMaterial(helmetMaterial, equipWithMaterialBuilder, equipBuilder);
//     chestplate = BuildChestplateByMaterial(chestplateMaterial, equipWithMaterialBuilder, equipBuilder);
//     boots = BuildBootsByMaterial(bootsMaterial, equipWithMaterialBuilder, equipBuilder);

//     myEquipBuilder.Reset();
//     myEquipBuilder.SetHelmet(helmet);
//     myEquipBuilder.SetChestplate(chestplate);
//     myEquipBuilder.SetBoots(boots);

//     equip = myEquipBuilder.GetResult();

//     return equip;
// }

Helmet* MyEquipBuilderMain::BuildHelmetByMaterial(WhatMaterial helmetMaterial, EquipWithMaterialBuilder& equipWithMaterialBuilder, EquipBuilder& equipBuilder)
{
    switch (helmetMaterial)
    {
    case NoMaterialMaterial:
        equipWithMaterialBuilder.BuildNoMaterialHelmet(&equipBuilder);
        break;
    case DecorativeMaterial:
        equipWithMaterialBuilder.BuildDecorativeHelmet(&equipBuilder);
        break;
    case IronMaterial:
        equipWithMaterialBuilder.BuildIronHelmet(&equipBuilder);
        break;
    case GoldMaterial:
        equipWithMaterialBuilder.BuildGoldHelmet(&equipBuilder);
        break;
    case DimondMaterial:
        equipWithMaterialBuilder.BuildDimondHelmet(&equipBuilder);
        break;
    
    default:
        break;
    }
    return reinterpret_cast<Helmet*>(equipBuilder.GetResult());
}

Chestplate* MyEquipBuilderMain::BuildChestplateByMaterial(WhatMaterial chestplateMaterial, EquipWithMaterialBuilder& equipWithMaterialBuilder, EquipBuilder& equipBuilder)
{
    switch (chestplateMaterial)
    {
    case NoMaterialMaterial:
        equipWithMaterialBuilder.BuildNoMaterialChestplate(&equipBuilder);
        break;
    case DecorativeMaterial:
        equipWithMaterialBuilder.BuildDecorativeChestplate(&equipBuilder);
        break;
    case IronMaterial:
        equipWithMaterialBuilder.BuildIronChestplate(&equipBuilder);
        break;
    case GoldMaterial:
        equipWithMaterialBuilder.BuildGoldChestplate(&equipBuilder);
        break;
    case DimondMaterial:
        equipWithMaterialBuilder.BuildDimondChestplate(&equipBuilder);
        break;
    
    default:
        break;
    }
    return reinterpret_cast<Chestplate*>(equipBuilder.GetResult());
}

Boots* MyEquipBuilderMain::BuildBootsByMaterial(WhatMaterial bootsMaterial, EquipWithMaterialBuilder& equipWithMaterialBuilder, EquipBuilder& equipBuilder)
{
    switch (bootsMaterial)
    {
    case NoMaterialMaterial:
        equipWithMaterialBuilder.BuildNoMaterialBoots(&equipBuilder);
        break;
    case DecorativeMaterial:
        equipWithMaterialBuilder.BuildDecorativeBoots(&equipBuilder);
        break;
    case IronMaterial:
        equipWithMaterialBuilder.BuildIronBoots(&equipBuilder);
        break;
    case GoldMaterial:
        equipWithMaterialBuilder.BuildGoldBoots(&equipBuilder);
        break;
    case DimondMaterial:
        equipWithMaterialBuilder.BuildDimondBoots(&equipBuilder);
        break;
    
    default:
        break;
    }
    return reinterpret_cast<Boots*>(equipBuilder.GetResult());
}
