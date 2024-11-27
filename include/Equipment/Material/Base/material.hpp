#pragma once

#include <string>
#include <memory>

#include "../../../Game/game_settings.hpp"

using GameSettings::ArmorMultiple;

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
