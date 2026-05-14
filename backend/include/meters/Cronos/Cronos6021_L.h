#pragma once
#include "meters/Cronos/Cronos.h"

// Concret class
class Cronos6021_L : public Cronos
{
public:
    Cronos6021_L();
    ~Cronos6021_L() override;
    Cronos6021_L(const Cronos6021_L &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
