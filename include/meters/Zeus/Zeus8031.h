#pragma once
#include "meters/Phase/ThreePhaseMeter.h"
#include "meters/Zeus/Zeus.h"
// Concret class
class Zeus8031 : public Zeus, ThreePhaseMeter
{
public:
    Zeus8031();
    ~Zeus8031() override;
    Zeus8031(const Zeus8031 &other, int new_id);
    std::vector<double> &getPhaseValues() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
