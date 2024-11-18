#include "../../../../../include/Equipment/Material/Base/material.hpp"

std::string Material::GetName()
{
    return name_;
}

double Material::GetArmorMultiple()
{
    return armorMultiple_;
}

void Material::SetName(std::string name)
{
    name_ = name;
}

void Material::SetArmorMultiple(double armorMultiple)
{
    armorMultiple_ = armorMultiple;
}
