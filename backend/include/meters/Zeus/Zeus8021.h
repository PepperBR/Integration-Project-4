#pragma once
#include "meters/Zeus/Zeus.h"

// Concret class
class Zeus8021 : public Zeus
{
public:
    Zeus8021();
    Zeus8021(const Zeus8021 &other, const int &new_id);
    ~Zeus8021() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
