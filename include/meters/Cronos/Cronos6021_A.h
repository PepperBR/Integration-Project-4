#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/SinglePhaseMeter.h"
//Concret class
class Cronos6021_A : public Cronos, SinglePhaseMeter
{        
public:
    Cronos6021_A();
    ~Cronos6021_A() override;
    Cronos6021_A(const Cronos6021_A& other, int new_id);
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

