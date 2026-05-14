#pragma once
#include "meters/Cronos/Cronos.h"

// Concret class
class Cronos6001_A : public Cronos
{
public:
    Cronos6001_A();
    ~Cronos6001_A() override;
    Cronos6001_A(const Cronos6001_A &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
