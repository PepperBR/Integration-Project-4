#include "meters/Zeus/Zeus.h"

Zeus::Zeus(const int &id, const std::string &model, const Phase &PhasesMeter)
    : Meter(id, "Zeus", model, PhasesMeter){};

Zeus::Zeus(const Zeus &other, const int &new_id)
    : Meter(other, new_id){};

std::array<double, 3> Zeus::getPhaseValues(const Phase number_of_phases) const
{
    return PhasesMeter::getPhaseValues(number_of_phases);
}

Zeus::~Zeus(){};