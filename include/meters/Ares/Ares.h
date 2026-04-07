#pragma once

#include "meters/Meter.h"

//Abstract Class
class Ares : public Meter
{
public:
    ~Ares() override;
    Ares(const Ares& other, int new_id);
    Ares(int id, std::string model);
};
