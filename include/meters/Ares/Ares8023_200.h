#pragma once
#include "meters/Ares/Ares.h"
#include "meters/Phase/TwoPhaseMeter.h"
//Concret class
class Ares8023_200 : public Ares, TwoPhaseMeter
{        
public:
    Ares8023_200();
    Ares8023_200(const Ares8023_200& other, int new_id);
    ~Ares8023_200() override;
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

