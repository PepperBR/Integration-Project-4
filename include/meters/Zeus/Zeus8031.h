#pragma once
#include "meters/Zeus/Zeus.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Zeus8031 : public Zeus, ThreePhaseMeter
{        
public:
    Zeus8031();
    ~Zeus8031() override;
    Zeus8031(const Zeus8031& other, int new_id);
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> cloneMeter() const override;
};

