#pragma once
#include "meters/Cronos/Cronos.h"

// Concret class
class Cronos7023_2_5 : public Cronos
{
public:
    Cronos7023_2_5();
    ~Cronos7023_2_5() override;
    Cronos7023_2_5(const Cronos7023_2_5 &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
