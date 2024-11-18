#pragma once

#include <string>

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
    NoMaterial = 0,
    DecorativeMaterial = 1,
    IronMaterial = 2,
    GoldMaterial = 3,
    DimondMaterial = 4
};

struct Material
{
public:
    std::string GetName();
    double GetArmorMultiple();

protected:
    void SetName(std::string name);
    void SetArmorMultiple(double armorMultiple);

private:
    std::string name_;
    double armorMultiple_;
};
