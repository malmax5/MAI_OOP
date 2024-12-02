#pragma once

#include <string>
#include <memory>

#include "../../../CRTP/creating_logger.hpp"

#include "../../../Game/game_settings.hpp"

using GameSettings::ArmorMultiple;

struct Material
{
public:
    Material() = default;
    virtual ~Material();

    double GetArmorMultiple();

protected:
    void SetArmorMultiple(double armorMultiple);

private:
    double armorMultiple_;
};
