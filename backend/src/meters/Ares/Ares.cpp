#include "meters/Ares/Ares.h"

Ares::Ares(const int &id, const std::string &model, const Phase &PhasesMeter)
    : Meter(id, "Ares", model, PhasesMeter){};

Ares::Ares(const Ares &other, const int &new_id)
    : Meter(other, new_id){};

std::array<double, 3> Ares::getPhaseValues(const Phase number_of_phases) const
{
    return PhasesMeter::getPhaseValues(number_of_phases);
}

Ares::~Ares(){};
