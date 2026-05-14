#pragma once

#include "meters/Meter.h"
#include "meters/Phase/PhasesMeter.h"

// Abstract Class
class Cronos : public Meter, public PhasesMeter
{
public:
    ~Cronos() override;
    Cronos(const Cronos &other, const int &new_id);
    Cronos(const int &id, const std::string &model, const Phase &PhasesMeter);
    std::array<double, 3> getPhaseValues(const Phase number_of_phases) const override;
};
