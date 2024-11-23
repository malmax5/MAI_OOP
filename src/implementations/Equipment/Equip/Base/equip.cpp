#include "../../../../../include/Equipment/Equip/Base/equip.hpp"

double Equip::GetArmor()
{
    return armor_;
}

std::shared_ptr<Material> Equip::GetMaterial()
{
    return material_;
}

void Equip::SetArmor(double armor)
{
    armor_ = armor;
}

void Equip::SetMaterial(std::shared_ptr<Material> material)
{
    material_ = material;
}
