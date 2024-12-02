#include "../../../../../include/Equipment/Material/Base/material.hpp"

Material::~Material()
{}

double Material::GetArmorMultiple()
{
    return armorMultiple_;
}

void Material::SetArmorMultiple(double armorMultiple)
{
    armorMultiple_ = armorMultiple;
}
