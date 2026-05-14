#pragma once
#include "meters/Zeus/Zeus.h"

// Concret class
class Zeus8031 : public Zeus
{
public:
    Zeus8031();
    ~Zeus8031() override;
    Zeus8031(const Zeus8031 &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
