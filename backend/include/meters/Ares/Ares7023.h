#pragma once
#include "meters/Ares/Ares.h"

// Concret class
class Ares7023 : public Ares
{
public:
    Ares7023();
    Ares7023(const Ares7023 &other, const int &new_id);
    ~Ares7023() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
