#pragma once
#include "meters/Apolo/Apolo.h"

// Concret class
class Apolo6031 : public Apolo
{
public:
    Apolo6031();
    Apolo6031(const Apolo6031 &other, const int &new_id);
    ~Apolo6031() override;

    std::shared_ptr<Meter> cloneMeter(int unique_id) const override;
};
