#include "core/CatalogControler.h"

Status CatalogControler::handleAddMeter(const os::AddMeterRequest* request, os::AddMeterResponse* response, Catalog* catalog) {
    try {
        auto new_meter = catalog->addNewModel(std::stoi(request->model_id()));
        if (new_meter) {
            handleCatalogToProto(new_meter, response->mutable_meter_created());

            return Status::OK;
        }
        return Status(StatusCode::INTERNAL, "Escolhas um ID correto");
    } catch (...) {
        return Status(StatusCode::INVALID_ARGUMENT, "ID de modelo inválido");
    }
}

Status CatalogControler::handleListMeters(const os::ListMetersRequest* request, os::ListMetersResponse* response, Catalog* catalog) {
    auto line_meters_available = catalog->getLineModelsAvailable(request->id_line());

    for (const auto & models : line_meters_available)
    {
        handleCatalogToProto(models, response->add_meters());
    }
    return Status::OK;
}

Status CatalogControler::handleListLines(const google::protobuf::Empty* request, os::ListLinesResponse* response, Catalog* catalog) {
    auto lines = catalog->getLines();

    for (const auto & line : lines)
    {
        response->add_lines(line);
    }
    return Status::OK;
}

Status CatalogControler::handleRemoveMeter(const os::RemoveMeterRequest* request, os::RemoveMeterResponse* response, Catalog* catalog) {
    auto removed = catalog->removeModel(std::stoi(request->id_model()));
    response->set_result(removed ? "Removed" : "Not Removed");
    return Status::OK;
}

Status CatalogControler::handleListAllMeters(const google::protobuf::Empty* request, os::ListAllMetersResponse* response, Catalog* catalog) {
    try {
        auto available_meters = catalog->getAllMeters();
        
        std::string previous_line;
        os::Line* current_group = nullptr;

        for (const auto & meter : available_meters)
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
    } catch (const std::bad_alloc& e) {
        return Status(StatusCode::INTERNAL, e.what());
    }
}

Status CatalogControler::handleGetMeasurementsPhases(const os::GetMeasurementsPhasesRequest* request, os::GetMeasurementsPhasesResponse* response, Catalog* catalog) {
    try{
        auto phases = catalog->getMeasurementsPhases(std::stoi(request->id()));
    
        for(auto const &value : phases)
        {
            response->add_values(std::to_string(value));
        }
        return Status::OK;
    } catch (...){
        return Status(StatusCode::INVALID_ARGUMENT, "ID de modelo inválido");
    }
}

void CatalogControler::handleCatalogToProto (std::shared_ptr<Meter> meter, os::Meter* proto_meter)
{
    proto_meter->set_id(std::to_string(meter->getID()));
    proto_meter->set_is_template(std::to_string(meter->getIsTemplate()));
    proto_meter->set_name_line(meter->getNameLine());
    proto_meter->set_name_model(meter->getNameModel());
}