#include "core/CatalogControler.h"

Status CatalogControler::handleAddMeter(const os::AddMeterRequest *request, os::AddMeterResponse *response, Catalog *catalog)
{
    try
    {
        auto new_meter = catalog->addNewModel(std::stoi(request->meter_id()));
        if (new_meter)
        {
            handleCatalogToProto(new_meter, response->mutable_meter_id());

            return Status::OK;
        }
        return Status(StatusCode::NOT_FOUND, "Escolha um ID correto");
    }
    catch (...)
    {
        return Status(StatusCode::INVALID_ARGUMENT, "ID de modelo inválido");
    }
}

Status CatalogControler::handleListAvailableMeters(const os::ListAvailableMetersRequest *request, os::ListAvailableMetersResponse *response,
                                                   Catalog *catalog)
{
    auto line_meters_available = catalog->getLineModelsTemplate(request->line_name());

    for (const auto &models : line_meters_available)
    {
        handleCatalogToProto(models, response->add_meters());
    }
    return Status::OK;
}

Status CatalogControler::handleListCreatedMeters(const os::ListCreatedMetersRequest *request, os::ListCreatedMetersResponse *response,
                                                 Catalog *catalog)
{
    auto line_created_meters = catalog->getLineModelsCreated(request->line_name());

    for (const auto &models : line_created_meters)
    {
        handleCatalogToProto(models, response->add_meters());
    }
    return Status::OK;
}

Status CatalogControler::handleListLines(const google::protobuf::Empty *request, os::ListLinesResponse *response, Catalog *catalog)
{
    auto lines = catalog->getLines();

    for (const auto &line : lines)
    {
        response->add_lines(line);
    }
    return Status::OK;
}

Status CatalogControler::handleRemoveMeter(const os::RemoveMeterRequest *request, os::RemoveMeterResponse *response, Catalog *catalog)
{
    try
    {
        auto removed = catalog->removeModel(std::stoi(request->meter_id()));
        response->set_result(removed ? "removed" : "not removed");
        return Status::OK;
    }
    catch (...)
    {
        return Status(StatusCode::INVALID_ARGUMENT, "ID de modelo inválido");
    }
}
Status CatalogControler::handleListAllCreatedMeters(const google::protobuf::Empty *request, os::ListAllCreatedMetersResponse *response,
                                                    Catalog *catalog)
{
    try
    {
        auto available_meters = catalog->getAllCreatedMeters();

        std::string previous_line;
        os::Line *current_group = nullptr;

        for (const auto &meter : available_meters)
        {
            std::string current_line_name = meter->getNameLine();

            if (current_line_name != previous_line || current_group == nullptr)
            {
                current_group = response->add_line_meters();
                current_group->set_name(current_line_name);
                previous_line = current_line_name;
            }

            handleCatalogToProto(meter, current_group->add_meters());
        }
        return Status::OK;
    }
    catch (const std::bad_alloc &e)
    {
        return Status(StatusCode::INTERNAL, e.what());
    }
}

Status CatalogControler::handleListAllAvailableMeters(const google::protobuf::Empty *request, os::ListAllAvailableMetersResponse *response,
                                                      Catalog *catalog)
{
    try
    {
        auto available_meters = catalog->getAllTemplateMeters();

        std::string previous_line;
        os::Line *current_group = nullptr;

        for (const auto &meter : available_meters)
        {
            std::string current_line_name = meter->getNameLine();

            if (current_line_name != previous_line || current_group == nullptr)
            {
                current_group = response->add_line_meters();
                current_group->set_name(current_line_name);
                previous_line = current_line_name;
            }

            handleCatalogToProto(meter, current_group->add_meters());
        }
        return Status::OK;
    }
    catch (const std::bad_alloc &e)
    {
        return Status(StatusCode::INTERNAL, e.what());
    }
}

Status CatalogControler::handleGetMeasurementsPhases(const os::GetMeasurementsPhasesRequest *request, os::GetMeasurementsPhasesResponse *response,
                                                     Catalog *catalog)
{
    try
    {
        auto phases = catalog->getMeasurementsPhases(std::stoi(request->meter_id()));

        for (auto const &value : phases)
        {
            response->add_measurements_values(std::to_string(value));
        }
        return Status::OK;
    }
    catch (...)
    {
        return Status(StatusCode::INVALID_ARGUMENT, "ID de modelo inválido");
    }
}

void CatalogControler::handleCatalogToProto(std::shared_ptr<Meter> meter, os::Meter *proto_meter)
{
    proto_meter->set_id(std::to_string(meter->getID()));
    proto_meter->set_line_name(meter->getNameLine());
    proto_meter->set_model_name(meter->getNameModel());
}