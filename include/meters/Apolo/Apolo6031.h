#pragma once
#include "meters/Apolo/Apolo.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Apolo6031 : public Apolo, ThreePhaseMeter
{        
public:
    Apolo6031();
    Apolo6031(const Apolo6031& other, int new_id);
    ~Apolo6031() override;
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

