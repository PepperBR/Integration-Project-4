#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Cronos6001_A : public Cronos, ThreePhaseMeter
{        
public:
    Cronos6001_A();
    ~Cronos6001_A() override;
    Cronos6001_A(const Cronos6001_A& other, int new_id);
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

