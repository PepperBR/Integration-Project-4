#include "meters/Meter.h"

Meter::Meter(const int &id, const std::string &line, const std::string &model, const Phase &number_of_phases)
    : ID(id)
    , name_line(std::move(line))
    , name_model(std::move(model))
    , is_template(true)
    , number_of_phases(number_of_phases)
{
}

Meter::Meter(const Meter &other, const int &new_id)
    : ID(new_id)
    , is_template(false)
    , name_line(other.name_line)
    , name_model(other.name_model)
    , number_of_phases(other.number_of_phases)
{
}

std::string Meter::getFullName() const
{
    return name_line + " " + name_model;
}

bool Meter::getIsTemplate() const
{
    return is_template;
}

int Meter::getID() const
{
    return ID;
}

std::string Meter::getNameLine() const
{
    return name_line;
}

std::string Meter::getNameModel() const
{
    return name_model;
}

Phase Meter::getNumberOfPhases() const
{
    return number_of_phases;
}

Meter::~Meter()
{
}