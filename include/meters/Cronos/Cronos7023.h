#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Cronos7023 : public Cronos, ThreePhaseMeter
{        
public:
    Cronos7023();
    ~Cronos7023() override;
    Cronos7023(const Cronos7023& other, int new_id);
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override; 
};

