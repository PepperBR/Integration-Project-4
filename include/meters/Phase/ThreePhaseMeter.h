#pragma once
#include <random>
#include <vector>

class ThreePhaseMeter
{
private:
    std::vector<double> phaseValues;

public:
    virtual ~ThreePhaseMeter() = default;
    virtual std::vector<double> &getPhaseValues();
};
