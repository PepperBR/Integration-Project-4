#pragma once
#include "meters/Ares/Ares.h"
#include "meters/Phase/TwoPhaseMeter.h"
// Concret class
class Ares7023 : public Ares, TwoPhaseMeter
{
public:
    Ares7023();
    Ares7023(const Ares7023 &other, int new_id);
    ~Ares7023() override;
    std::vector<double> &getPhaseValues() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
