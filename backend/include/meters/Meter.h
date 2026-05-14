#pragma once

#include "Phase/Phase.h"
#include <array>
#include <memory>
#include <string>
#include <vector>

// Abstract Class
class Meter
{
protected:
    int const ID;
    bool is_template;
    std::string name_line;
    std::string name_model;
    Phase number_of_phases;

public:
    Meter(const int &id, const std::string &line, const std::string &model, const Phase &number_of_phases);
    Meter(const Meter &other, const int &new_id);
    Meter(const Meter &other) = default;
    Meter(Meter &&meter) = default;
    virtual ~Meter();

    std::string getFullName() const;
    bool getIsTemplate() const;
    int getID() const;
    std::string getNameLine() const;
    std::string getNameModel() const;
    Phase getNumberOfPhases() const;

    virtual std::array<double, 3> getPhaseValues(const Phase number_of_phases) const = 0;

    virtual std::shared_ptr<Meter> cloneMeter(int unique_id) const = 0;
};
