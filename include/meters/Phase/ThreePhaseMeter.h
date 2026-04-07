#pragma once
#include <vector>
#include <random>

class ThreePhaseMeter
{
private:
    std::vector<double> phaseValues;
public:
    virtual ~ThreePhaseMeter() = default;
    virtual std::vector<double> & getPhaseValues();
};
