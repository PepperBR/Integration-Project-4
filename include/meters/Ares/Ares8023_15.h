#pragma once
#include "meters/Ares/Ares.h"
#include "meters/Phase/SinglePhaseMeter.h"
//Concret class
class Ares8023_15 : public Ares, SinglePhaseMeter
{        
public:
    Ares8023_15();
    Ares8023_15(const Ares8023_15& other, int new_id);
    ~Ares8023_15() override;
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

