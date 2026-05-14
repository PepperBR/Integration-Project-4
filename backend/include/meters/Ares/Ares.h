#pragma once

#include "meters/Meter.h"
#include "meters/Phase/PhasesMeter.h"

// Abstract Class
class Ares : public Meter, public PhasesMeter
{
public:
    ~Ares() override;
    Ares(const Ares &other, const int &new_id);
    Ares(const int &id, const std::string &model, const Phase &PhasesMeter);
    std::array<double, 3> getPhaseValues(const Phase number_of_phases) const override;
};
