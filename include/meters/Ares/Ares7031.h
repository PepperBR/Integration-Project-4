#pragma once
#include "meters/Ares/Ares.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Ares7031 : public Ares, ThreePhaseMeter
{        
public:
    Ares7031();
    Ares7031(const Ares7031& other, int new_id);
    ~Ares7031() override;
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

