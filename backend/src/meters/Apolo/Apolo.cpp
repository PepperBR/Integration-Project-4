#include "meters/Apolo/Apolo.h"

Apolo::Apolo(const int &id, const std::string &model, const Phase &PhasesMeter)
    : Meter(id, "Apolo", model, PhasesMeter)
{
}

Apolo::Apolo(const Apolo &other, const int &new_id)
    : Meter(other, new_id)
{
}

std::array<double, 3> Apolo::getPhaseValues(const Phase number_of_phases) const
{
    return PhasesMeter::getPhaseValues(number_of_phases);
}

Apolo::~Apolo(){};
