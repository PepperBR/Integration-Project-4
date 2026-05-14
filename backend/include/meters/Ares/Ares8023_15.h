#pragma once
#include "meters/Ares/Ares.h"

// Concret class
class Ares8023_15 : public Ares
{
public:
    Ares8023_15();
    Ares8023_15(const Ares8023_15 &other, const int &new_id);
    ~Ares8023_15() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
