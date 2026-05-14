#include "meters/Cronos/Cronos.h"

Cronos::Cronos(const int &id, const std::string &model, const Phase &PhasesMeter)
    : Meter(id, "Cronos", model, PhasesMeter){};

Cronos::Cronos(const Cronos &other, const int &new_id)
    : Meter(other, new_id){};

std::array<double, 3> Cronos::getPhaseValues(const Phase number_of_phases) const
{
    return PhasesMeter::getPhaseValues(number_of_phases);
}

Cronos::~Cronos(){};
