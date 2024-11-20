#pragma once

#include<string>
#include <memory>

#include "../../Material/Base/material.hpp"

enum EquipArmor
{
    HelmetArmor = 10,
    ChestplateArmor = 20,
    BootsArmor = 5
};

struct Equip
{
    friend class EquipBuilder;

public:
    double GetArmor();
    std::shared_ptr<Material> GetMaterial();
    std::string GetName();

protected:
    void SetArmor(double armor);
    void SetMaterial(std::shared_ptr<Material> material);
    void SetName(std::string name);

private:
    double armor_;
    std::shared_ptr<Material> material_;
    std::string name_;
};
