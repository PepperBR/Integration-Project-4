#include "meters/Ares/Ares.h"

Ares::Ares(int id, std::string model)
    : Meter(id, "Ares", model)
{
};

Ares::Ares(const Ares& other, int new_id) 
    : Meter(other, new_id) 
{
};

Ares::~Ares()
{
};
