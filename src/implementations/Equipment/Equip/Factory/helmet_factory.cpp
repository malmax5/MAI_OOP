#include "../../../../../include/Equipment/Equip/Factory/helmet_factory.hpp"

std::shared_ptr<Equip> HelmetFactory::CreateEquip(GameSettings::MaterialId id)
{
    builder->Reset();
    builder->SetEquip(std::make_shared<Helmet>());
    builder->SetMaterial(MaterialByMask(id));
    return builder->GetResult();
}
