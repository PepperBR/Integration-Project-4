#pragma once

#include "meters/Phase/Phase.h"
#include <random>
#include <vector>

// Interface Class
class PhasesMeter
{
public:
    auto getPhaseValues(const Phase number_of_phases) const -> std::array<double, 3>;
};
