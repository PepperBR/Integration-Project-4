#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Cronos6021_L : public Cronos, ThreePhaseMeter
{        
public:
    Cronos6021_L();
    ~Cronos6021_L() override;
    Cronos6021_L(const Cronos6021_L& other, int new_id);
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

