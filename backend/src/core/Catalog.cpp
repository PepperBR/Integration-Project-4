#include "core/Catalog.h"
#include "meters/Apolo/Apolo6031.h"
#include "meters/Ares/Ares7021.h"
#include "meters/Ares/Ares7023.h"
#include "meters/Ares/Ares7031.h"
#include "meters/Ares/Ares8023.h"
#include "meters/Ares/Ares8023_15.h"
#include "meters/Ares/Ares8023_200.h"
#include "meters/Cronos/Cronos6001_A.h"
#include "meters/Cronos/Cronos6003.h"
#include "meters/Cronos/Cronos6021_A.h"
#include "meters/Cronos/Cronos6021_L.h"
#include "meters/Cronos/Cronos7023.h"
#include "meters/Cronos/Cronos7023_2_5.h"
#include "meters/Cronos/Cronos7023_L.h"
#include "meters/Zeus/Zeus8021.h"
#include "meters/Zeus/Zeus8023.h"
#include "meters/Zeus/Zeus8031.h"

Catalog::Catalog()
{
    meter_list.emplace_back(std::make_unique<Apolo6031>());

    meter_list.emplace_back(std::make_unique<Zeus8021>());
    meter_list.emplace_back(std::make_unique<Zeus8023>());
    meter_list.emplace_back(std::make_unique<Zeus8031>());

    meter_list.emplace_back(std::make_unique<Cronos7023>());
    meter_list.emplace_back(std::make_unique<Cronos7023_L>());
    meter_list.emplace_back(std::make_unique<Cronos7023_2_5>());
    meter_list.emplace_back(std::make_unique<Cronos6021_L>());
    meter_list.emplace_back(std::make_unique<Cronos6021_A>());
    meter_list.emplace_back(std::make_unique<Cronos6003>());
    meter_list.emplace_back(std::make_unique<Cronos6001_A>());

    meter_list.emplace_back(std::make_unique<Ares7021>());
    meter_list.emplace_back(std::make_unique<Ares8023>());
    meter_list.emplace_back(std::make_unique<Ares7023>());
    meter_list.emplace_back(std::make_unique<Ares7031>());
    meter_list.emplace_back(std::make_unique<Ares8023_15>());
    meter_list.emplace_back(std::make_unique<Ares8023_200>());

    this->instance_id_counter = int(meter_list.size());
};

const std::shared_ptr<Meter> Catalog::addNewModel(const int &ID_template)
{
    auto model = factoryMeter(ID_template);

    if (model == nullptr)
    {
        return nullptr;
    }

    meter_list.push_back(model);
    sortList();
    return model;
};

bool Catalog::removeModel(const int ID)
{
    bool result = false;
    meter_list.remove_if([ID, &result](std::shared_ptr<Meter> &meter_list) {
        if (meter_list->getID() == ID && !meter_list->getIsTemplate())
        {
            result = true;
            return result;
        };
        result = false;
        return result;
    });
    return result;
};

std::array<double, 3> Catalog::getMeasurementsPhases(const int ID)
{
    for (auto &meter : meter_list)
    {
        if (meter->getID() == ID && !meter->getIsTemplate())
        {
            return meter->getPhaseValues(meter->getNumberOfPhases());
        }
    }
    return {0.0, 0.0, 0.0};
}

void Catalog::sortList()
{
    meter_list.sort([](const std::shared_ptr<Meter> &a, const std::shared_ptr<Meter> &b) {
        if (a->getIsTemplate() != b->getIsTemplate())
        {
            return a->getIsTemplate() > b->getIsTemplate();
        }
        return a->getFullName() < b->getFullName();
    });
}

std::shared_ptr<Meter> Catalog::factoryMeter(const int &ID_template)
{
    for (const auto &meter_template : meter_list)
    {
        if (meter_template->getID() == ID_template && meter_template->getIsTemplate())
        {
            auto unique_id = ++this->instance_id_counter;
            return meter_template->cloneMeter(unique_id);
        }
    }
    return nullptr;
}

LineList Catalog::getLines() const
{
    std::set<std::string> lines;

    for (const auto &meter : meter_list)
    {
        lines.insert(meter->getNameLine());
    }

    return lines;
}

MetersList Catalog::getLineModelsCreated(const std::string &name_line)
{
    MetersList list;

    for (auto &model : meter_list)
    {
        if (!model->getIsTemplate())
        {
            if (model->getFullName().find(name_line) != std::string::npos)
            {
                list.push_back(model);
            }
        }
    }

    return list;
}

MetersList Catalog::getLineModelsTemplate(const std::string &name_line)
{
    MetersList list;

    for (auto &model : meter_list)
    {
        if (model->getIsTemplate())
        {
            if (model->getFullName().find(name_line) != std::string::npos)
            {
                list.push_back(model);
            }
        }
    }

    return list;
}

std::shared_ptr<Meter> Catalog::getMeterByID(const int id) const
{
    for (const auto &meter : meter_list)
    {
        if (meter->getID() == id && !meter->getIsTemplate())
        {
            return meter;
        }
    }
    return nullptr;
}

MetersList Catalog::getAllTemplateMeters()
{
    MetersList available_meters;

    auto linhas = getLines();
    for (const auto &linha : linhas)
    {
        MetersList models = getLineModelsTemplate(linha);

        available_meters.splice(available_meters.end(), models);
    }
    return available_meters;
}

MetersList Catalog::getAllCreatedMeters()
{
    MetersList created_meters;

    auto linhas = getLines();
    for (const auto &linha : linhas)
    {
        MetersList models = getLineModelsCreated(linha);

        created_meters.splice(created_meters.end(), models);
    }
    return created_meters;
}
