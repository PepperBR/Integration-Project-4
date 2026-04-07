#include "meters/Phase/SinglePhaseMeter.h"

std::vector<double> & SinglePhaseMeter::getPhaseValues()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1, 220);

    phaseValues.clear();
    phaseValues.push_back(dist(gen));

    return phaseValues;
};