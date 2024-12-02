#include "../../../../../include/Equipment/Material/Derived/no_material.hpp"

NoMaterial::NoMaterial()
{
    LogCreate();
    SetArmorMultiple(ArmorMultiple::NoMaterialMultiple);
}

NoMaterial::~NoMaterial()
{}
