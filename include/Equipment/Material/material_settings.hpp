#pragma once

#include <memory>
#include "../../Game/game_settings.hpp"
#include "Base/material.hpp"
#include "Derived/no_material.hpp"
#include "Derived/decorative.hpp"
#include "Derived/iron.hpp"
#include "Derived/gold.hpp"
#include "Derived/dimond.hpp"

using GameSettings::MaterialId;

std::shared_ptr<Material> MaterialByMask(MaterialId materialId);
