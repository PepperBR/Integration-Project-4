#pragma once

#include <random>
#include <vector>
// Interface

class SinglePhaseMeter
{
private:
    std::vector<double> phaseValues;

public:
    virtual ~SinglePhaseMeter() = default;
    virtual std::vector<double> &getPhaseValues();
};
