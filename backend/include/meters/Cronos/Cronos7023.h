#pragma once
#include "meters/Cronos/Cronos.h"

// Concret class
class Cronos7023 : public Cronos
{
public:
    Cronos7023();
    ~Cronos7023() override;
    Cronos7023(const Cronos7023 &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
