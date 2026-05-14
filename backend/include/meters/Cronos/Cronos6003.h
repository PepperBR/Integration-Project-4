#pragma once
#include "meters/Cronos/Cronos.h"

// Concret class
class Cronos6003 : public Cronos
{
public:
    Cronos6003();
    ~Cronos6003() override;
    Cronos6003(const Cronos6003 &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
