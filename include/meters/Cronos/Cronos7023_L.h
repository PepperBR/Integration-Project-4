#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/SinglePhaseMeter.h"
//Concret class
class Cronos7023_L : public Cronos, SinglePhaseMeter
{        
public:
    Cronos7023_L();
    ~Cronos7023_L() override;
    Cronos7023_L(const Cronos7023_L& other, int new_id);
    std::vector<double> & getPhaseValues() override;
    
    std::unique_ptr<Meter> cloneMeter() const override; 
};

