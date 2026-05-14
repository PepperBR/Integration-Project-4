#pragma once
#include "meters/Ares/Ares.h"

// Concret class
class Ares7031 : public Ares
{
public:
    Ares7031();
    Ares7031(const Ares7031 &other, const int &new_id);
    ~Ares7031() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
