#pragma once

#include "meters/Meter.h"
#include "meters/Phase/PhasesMeter.h"

// Abstract Class
class Zeus : public Meter, public PhasesMeter
{
public:
    ~Zeus() override;
    Zeus(const Zeus &other, const int &new_id);
    Zeus(const int &id, const std::string &model, const Phase &PhasesMeter);
    std::array<double, 3> getPhaseValues(const Phase number_of_phases) const override;
};
