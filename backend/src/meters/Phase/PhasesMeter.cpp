#include "meters/Phase/PhasesMeter.h"

auto PhasesMeter::getPhaseValues(const Phase number_of_phases) const -> std::array<double, 3>
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1, 220);
    std::array<double, 3> phaseValues = {0, 0, 0};

    switch (number_of_phases)
    {
    case Phase::PhaseA:
        phaseValues[0] = dist(gen);
        break;
    case Phase::PhaseB:
        phaseValues[0] = dist(gen);
        phaseValues[1] = dist(gen);
        break;

    case Phase::PhaseC:
        phaseValues[0] = dist(gen);
        phaseValues[1] = dist(gen);
        phaseValues[2] = dist(gen);
        break;
    }
    return phaseValues;
};