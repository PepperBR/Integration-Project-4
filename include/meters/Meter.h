#pragma once

#include <string>
#include <vector>
#include <memory>

//Abstract Class
class Meter
{
protected:

    int const ID;
    bool is_template;
    std::string name_line;
    std::string name_model;

public:

    Meter(int id, std::string line, std::string model, bool is_template = true);
    Meter(const Meter &other, int new_id);
    Meter(const Meter &other) = default;
    Meter(Meter &&meter) = default;
    virtual ~Meter();

    virtual std::vector<double> & getPhaseValues() = 0;
    std::string getFullName() const;
    bool getIsTemplate () const;
    int getID() const;
    std::string getNameLine () const;
    std::string getNameModel () const;
    
    virtual std::unique_ptr<Meter> cloneMeter() const = 0;

};
