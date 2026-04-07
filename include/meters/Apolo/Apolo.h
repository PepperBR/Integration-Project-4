#pragma once

#include "meters/Meter.h"

//Abstract Class
class Apolo : public Meter
{
public:
    ~Apolo() override;
    Apolo(const Apolo& other, int new_id);
    Apolo(int id, std::string model);
};

