#pragma once

#include "meters/Meter.h"
#include "meters/Phase/PhasesMeter.h"

// Abstract Class
class Apolo : public Meter, public PhasesMeter
{
public:
    ~Apolo() override;
    Apolo(const Apolo &other, const int &new_id);
    Apolo(const int &id, const std::string &model, const Phase &PhasesMeter);
    std::array<double, 3> getPhaseValues(const Phase number_of_phases) const override;
};
