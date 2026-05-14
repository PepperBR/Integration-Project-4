#pragma once
#include "meters/Ares/Ares.h"

// Concret class
class Ares8023_200 : public Ares
{
public:
    Ares8023_200();
    Ares8023_200(const Ares8023_200 &other, const int &new_id);
    ~Ares8023_200() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
