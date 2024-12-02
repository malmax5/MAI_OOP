#pragma once

#include<string>
#include <memory>

#include "../../../CRTP/creating_logger.hpp"

#include "../../Material/Base/material.hpp"
#include "../../../Game/game_settings.hpp"

using GameSettings::EquipArmor;

struct Equip
{
    friend class EquipBuilder;

public:
    double GetArmor();
    std::shared_ptr<Material> GetMaterial();

protected:
    void SetArmor(double armor);
    void SetMaterial(std::shared_ptr<Material> material);

private:
    double armor_;
    std::shared_ptr<Material> material_;
};
