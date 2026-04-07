#include "meters/Meter.h"

Meter::Meter(int id, std::string line, std::string model, bool is_template)
    : ID(id), name_line(std::move(line)), 
      name_model(std::move(model)),  
      is_template(is_template) 
{
}

Meter::Meter(const Meter &other, int new_id)
    : ID(new_id),           
      is_template(false),    
      name_line(other.name_line),   
      name_model(other.name_model)  
{
}

std::string Meter::getFullName() const
{
    return name_line + " " + name_model;
}

bool Meter::getIsTemplate () const 
{
    return is_template;
}

int Meter::getID() const 
{
    return ID;
}

std::string Meter::getNameLine () const
{
    return name_line;
}

std::string Meter::getNameModel () const
{
    return name_model;
}

Meter::~Meter()  
{
}