#pragma once
#include "meters/Ares/Ares.h"

// Concret class
class Ares7021 : public Ares
{
public:
    Ares7021();
    Ares7021(const Ares7021 &other, const int &new_id);
    ~Ares7021() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
