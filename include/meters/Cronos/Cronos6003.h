#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/TwoPhaseMeter.h"
//Concret class
class Cronos6003 : public Cronos, TwoPhaseMeter
{        
public:
    Cronos6003();
    ~Cronos6003() override;
    Cronos6003(const Cronos6003& other, int new_id);
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

