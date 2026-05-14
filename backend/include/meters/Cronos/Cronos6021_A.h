#pragma once
#include "meters/Cronos/Cronos.h"

// Concret class
class Cronos6021_A : public Cronos
{
public:
    Cronos6021_A();
    ~Cronos6021_A() override;
    Cronos6021_A(const Cronos6021_A &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
