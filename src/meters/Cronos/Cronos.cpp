#include "meters/Cronos/Cronos.h"

Cronos::Cronos(int id, std::string model)
    : Meter(id, "Cronos", model)
{
};

Cronos::Cronos(const Cronos& other, int new_id) 
    : Meter(other, new_id) 
{
};


Cronos::~Cronos()
{
};

