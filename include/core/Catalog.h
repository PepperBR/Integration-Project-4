#pragma once

#include <list>
#include <memory>
#include <string>
#include <meters/Meter.h>
#include <set>
#include <tuple>

using LineList = std::set<std::string>;
using MetersList = std::list<std::unique_ptr<Meter>>;
using MeterAttributes = std::vector<std::tuple<int, std::string, bool>>;

class Catalog          
{
private:
    MetersList meter_list;
    std::unique_ptr<Meter> Catalog::factoryMeter(const int & ID_template); 
    void sortList();                         
    
public:
    void addNewModel (const int & ID_template); 
    bool removeModel (const int ID); 
    std::vector<double> & getMeasurementsPhases(const int ID); 
    
    LineList getLines () const; 
    MeterAttributes getLineModels(const std::string & line_name);    
    const std::unique_ptr<Meter> & getMeterByID(const int id) const;
    const std::unique_ptr<Meter> & getTemplateByID(const int id) const;
    Catalog();
};

