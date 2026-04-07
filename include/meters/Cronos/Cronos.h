#pragma once

#include "meters/Meter.h"

//Abstract Class
class Cronos : public Meter
{
public:
    Cronos(const Cronos& other, int new_id);
    ~Cronos() override;
    Cronos(int id, std::string model);
};
