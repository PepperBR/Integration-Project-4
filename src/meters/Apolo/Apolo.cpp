#include "meters/Apolo/Apolo.h"

Apolo::Apolo(int id, std::string model)
    : Meter(id, "Apolo" , model)
{
};

Apolo::Apolo(const Apolo& other, int new_id) 
    : Meter(other, new_id) 
{
};

Apolo::~Apolo()
{
};
