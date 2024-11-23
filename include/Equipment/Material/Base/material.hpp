#pragma once

#include <string>
#include <memory>

#include "../enums.hpp"

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
