#pragma once
#include "meters/Ares/Ares.h"

// Concret class
class Ares8023 : public Ares
{
public:
    Ares8023();
    Ares8023(const Ares8023 &other, const int &new_id);
    ~Ares8023() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
