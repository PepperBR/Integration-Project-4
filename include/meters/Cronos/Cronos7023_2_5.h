#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/TwoPhaseMeter.h"
//Concret class
class Cronos7023_2_5 : public Cronos, TwoPhaseMeter
{        
public:
    Cronos7023_2_5();
    ~Cronos7023_2_5() override;
    Cronos7023_2_5(const Cronos7023_2_5& other, int new_id);
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

