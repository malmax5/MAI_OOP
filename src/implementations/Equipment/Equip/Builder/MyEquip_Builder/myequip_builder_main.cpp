#include "../../../../../../include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_main.hpp"


MyEquip* MyEquipBuilderMain::BuildSetByMask(int helmetMaterial, int chestplateMaterial, int bootsMaterial)
{
    Helmet* helmet;
    Chestplate* chestplate;
    Boots* boots;
    MyEquip* equip;

    MyEquipBuilder builder0;
    EquipWithMaterialBuilder builder1;
    EquipBuilder builder2;

    switch (helmetMaterial)
    {
    case NoMaterial:
        break;
    case DecorativeMaterial:
        break;
    case IronMaterial:
        builder1.BuildIronHelmet(&builder2);
        break;
    case GoldMaterial:
        builder1.BuildGoldHelmet(&builder2);
        break;
    case DimondMaterial:
        builder1.BuildDimondHelmet(&builder2);
        break;
    
    default:
        break;
    }
    helmet = reinterpret_cast<Helmet*>(builder2.GetResult());

    switch (chestplateMaterial)
    {
    case NoMaterial:
        break;
    case DecorativeMaterial:
        break;
    case IronMaterial:
        builder1.BuildIronChestplate(&builder2);
        break;
    case GoldMaterial:
        builder1.BuildGoldChestplate(&builder2);
        break;
    case DimondMaterial:
        builder1.BuildDimondChestplate(&builder2);
        break;
    
    default:
        break;
    }
    chestplate = reinterpret_cast<Chestplate*>(builder2.GetResult());

    switch (bootsMaterial)
    {
    case NoMaterial:
        break;
    case DecorativeMaterial:
        break;
    case IronMaterial:
        builder1.BuildIronBoots(&builder2);
        break;
    case GoldMaterial:
        builder1.BuildGoldBoots(&builder2);
        break;
    case DimondMaterial:
        builder1.BuildDimondBoots(&builder2);
        break;
    
    default:
        break;
    }
    boots = reinterpret_cast<Boots*>(builder2.GetResult());

    builder0.Reset();
    builder0.SetHelmet(helmet);
    builder0.SetChestplate(chestplate);
    builder0.SetBoots(boots);

    equip = builder0.GetResult();

    return equip;
}