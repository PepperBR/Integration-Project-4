#pragma once
#include "meters/Ares/Ares.h"
#include "meters/Phase/SinglePhaseMeter.h"
//Concret class
class Ares7021 : public Ares, SinglePhaseMeter
{        
public:
    Ares7021();
    Ares7021(const Ares7021& other, int new_id);
    ~Ares7021() override;

    std::vector<double> & getPhaseValues() override;
    std::unique_ptr<Meter> cloneMeter() const override; 
};

