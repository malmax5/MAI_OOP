#pragma once

#include <memory>
#include "enums.hpp"
#include "Base/material.hpp"
#include "Derived/no_material.hpp"
#include "Derived/decorative.hpp"
#include "Derived/iron.hpp"
#include "Derived/gold.hpp"
#include "Derived/dimond.hpp"

std::shared_ptr<Material> MaterialByMask(WhatMaterial materialId);
