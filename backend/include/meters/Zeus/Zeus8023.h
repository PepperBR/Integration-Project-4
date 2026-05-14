#pragma once
#include "meters/Zeus/Zeus.h"

// Concret class
class Zeus8023 : public Zeus
{
public:
    Zeus8023();
    ~Zeus8023() override;
    Zeus8023(const Zeus8023 &other, const int &new_id);

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
