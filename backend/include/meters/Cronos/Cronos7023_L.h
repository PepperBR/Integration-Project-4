#pragma once
#include "meters/Cronos/Cronos.h"

// Concret class
class Cronos7023_L : public Cronos
{
public:
    Cronos7023_L();
    ~Cronos7023_L() override;
    Cronos7023_L(const Cronos7023_L &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
