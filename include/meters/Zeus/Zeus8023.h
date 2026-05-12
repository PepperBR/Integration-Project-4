#pragma once
#include "meters/Phase/TwoPhaseMeter.h"
#include "meters/Zeus/Zeus.h"
// Concret class
class Zeus8023 : public Zeus, TwoPhaseMeter
{
public:
    Zeus8023();
    ~Zeus8023() override;
    Zeus8023(const Zeus8023 &other, int new_id);
    std::vector<double> &getPhaseValues() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
