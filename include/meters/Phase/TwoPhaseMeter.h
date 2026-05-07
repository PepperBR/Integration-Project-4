#pragma once
#include <random>
#include <vector>

class TwoPhaseMeter
{
private:
    std::vector<double> phaseValues;

public:
    virtual ~TwoPhaseMeter() = default;
    virtual std::vector<double> &getPhaseValues();
};
