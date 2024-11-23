#include "../../../../../../include/Equipment/Equip/Builder/Equip_Builder/equip_builder_main.hpp"


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

//     myEquipBuilder->Reset();
//     myEquipBuilder->SetHelmet(helmet);
//     myEquipBuilder->SetChestplate(chestplate);
//     myEquipBuilder->SetBoots(boots);

//     equip = myEquipBuilder->GetResult();

//     return equip;
// }

std::shared_ptr<Equip> MyEquipBuilderMain::BuildHelmetByMaterial(WhatMaterial helmetMaterial, std::shared_ptr<EquipBuilder> equipBuilder)
{
    equipBuilder->Reset();
    equipBuilder->SetEquip(std::make_shared<Helmet>());
    equipBuilder->SetMaterial(MaterialByMask(helmetMaterial));

    return std::shared_ptr<Equip>(equipBuilder->GetResult());
}

std::shared_ptr<Equip> MyEquipBuilderMain::BuildChestplateByMaterial(WhatMaterial chestplateMaterial, std::shared_ptr<EquipBuilder> equipBuilder)
{
    equipBuilder->Reset();
    equipBuilder->SetEquip(std::make_shared<Chestplate>());
    equipBuilder->SetMaterial(MaterialByMask(chestplateMaterial));

    return std::shared_ptr<Equip>(equipBuilder->GetResult());
}

std::shared_ptr<Equip> MyEquipBuilderMain::BuildBootsByMaterial(WhatMaterial bootsMaterial, std::shared_ptr<EquipBuilder> equipBuilder)
{
    equipBuilder->Reset();
    equipBuilder->SetEquip(std::make_shared<Boots>());
    equipBuilder->SetMaterial(MaterialByMask(bootsMaterial));

    return std::shared_ptr<Equip>(equipBuilder->GetResult());
}
