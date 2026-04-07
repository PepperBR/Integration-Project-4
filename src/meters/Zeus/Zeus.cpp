#include "meters/Zeus/Zeus.h"

Zeus::Zeus(int id, std::string model)
    : Meter(id, "Zeus" , model)
{
};

Zeus::Zeus(const Zeus& other, int new_id) 
    : Meter(other, new_id) 
{
};


Zeus::~Zeus()
{
};