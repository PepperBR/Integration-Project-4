#pragma once

#include "meters/Meter.h"

//Abstract Class
class Zeus : public Meter
{
public:
    Zeus(const Zeus& other, int new_id);
    ~Zeus() override;
    Zeus(int id, std::string model);
};
