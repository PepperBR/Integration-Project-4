#pragma once

#include <list>
#include <memory>
#include <meters/Meter.h>
#include <set>
#include <string>
#include <tuple>

using LineList = std::set<std::string>;
using MetersList = std::list<std::shared_ptr<Meter>>;

class Catalog
{
private:
    MetersList meter_list;
    std::shared_ptr<Meter> Catalog::factoryMeter(const int &ID_template);
    int instance_id_counter;
    void sortList();

public:
    auto addNewModel(const int &ID_template) -> const std::shared_ptr<Meter>;
    bool removeModel(const int ID);
    auto getMeasurementsPhases(const int ID) -> std::array<double, 3>;

    auto getLines() const -> LineList;
    auto getLineModelsCreated(const std::string &line_name) -> MetersList;
    auto getLineModelsTemplate(const std::string &line_name) -> MetersList;
    auto getMeterByID(const int id) const -> std::shared_ptr<Meter>;

    auto getAllTemplateMeters() -> MetersList;
    auto getAllCreatedMeters() -> MetersList;

    Catalog();
};
