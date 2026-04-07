#pragma once
#include <vector>
#include <random>

class TwoPhaseMeter
{
private:
    std::vector<double> phaseValues;
public:
    virtual ~TwoPhaseMeter() = default;
    virtual std::vector<double> & getPhaseValues();
};

