#pragma once

#include <list>
#include <memory>
#include <string>
#include <meters/Meter.h>
#include <set>
#include <tuple>

using LineList = std::set<std::string>;
using MetersList = std::list<std::shared_ptr<Meter>>;

class Catalog          
{
private:
    MetersList meter_list;
    std::shared_ptr<Meter> Catalog::factoryMeter(const int & ID_template); 
    void sortList();
    int number_of_meters;                      
    
public:
    const std::shared_ptr<Meter> addNewModel (const int & ID_template); 
    bool removeModel (const int ID); 
    std::vector<double> & getMeasurementsPhases(const int ID); 
    
    LineList getLines () const; 
    MetersList getLineModelsCreated(const std::string & line_name);
    MetersList getLineModelsTemplate(const std::string & line_name);    
    std::shared_ptr<Meter> getMeterByID(const int id) const;

    MetersList getAllTemplateMeters ();
    MetersList getAllCreatedMeters ();
    const int & getNumberOfMeters ();
    Catalog();
};

