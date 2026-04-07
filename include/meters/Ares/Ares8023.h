#pragma once
#include "meters/Ares/Ares.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Ares8023 : public Ares, ThreePhaseMeter
{        
public:
    Ares8023();
    Ares8023(const Ares8023& other, int new_id);
    ~Ares8023() override;
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

