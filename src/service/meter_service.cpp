#include "service/meter_service.hpp"

Status MeterService::AddMeter(ServerContext* context, const os::AddMeterRequest* request, os::AddMeterResponse* response) {
    try {
        auto new_meter = this->catalog.addNewModel(std::stoi(request->model_id()));
        if (new_meter) {
            CatalogToProto(new_meter, response->mutable_meter_created());

            return Status::OK;
        }
        return Status(grpc::StatusCode::INTERNAL, "Escolhas um ID correto");
    } catch (...) {
        return Status(grpc::StatusCode::INVALID_ARGUMENT, "ID de modelo inválido");
    }
}

Status MeterService::ListMeters(ServerContext* context, const os::ListMetersRequest* request, os::ListMetersResponse* response) {
    auto line_meters_available = this->catalog.getLineModelsAvailable(request->id_line());

    for (const auto & models : line_meters_available)
    {
        CatalogToProto(models, response->add_meters());
    }
    return Status::OK;
}

Status MeterService::ListLines(ServerContext* context, const google::protobuf::Empty* request, os::ListLinesResponse* response) {
    auto lines = this->catalog.getLines();

    for (const auto & line : lines)
    {
        response->add_lines(line);
    }
    return Status::OK;
}

Status MeterService::RemoveMeter(ServerContext* context, const os::RemoveMeterRequest* request, os::RemoveMeterResponse* response) {
    auto removed = this->catalog.removeModel(std::stoi(request->id_model()));
    response->set_result(removed ? "Removed" : "Not Removed");
    
    return Status::OK;
}

Status MeterService::ListAllMeters(ServerContext* context, const google::protobuf::Empty* request, os::ListAllMetersResponse* response) {
    try {
        auto available_meters = this->catalog.getAllMeters();
        
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
            
            CatalogToProto(meter, current_group->add_meters());
        }
        return Status::OK;
    } catch (const std::bad_alloc& e) {
        return Status(grpc::StatusCode::INTERNAL, e.what());
    }
}

Status MeterService::GetMeasurementsPhases(ServerContext* context, const os::GetMeasurementsPhasesRequest* request, os::GetMeasurementsPhasesResponse* response) {
    try{
        auto phases = this->catalog.getMeasurementsPhases(std::stoi(request->id()));
    
        for(auto const &value : phases)
        {
            response->add_values(std::to_string(value));
        }
        return Status::OK;
    } catch (...){
        return Status(grpc::StatusCode::INVALID_ARGUMENT, "ID de modelo inválido");
    }
}

void MeterService::CatalogToProto (std::shared_ptr<Meter> meter, os::Meter* proto_meter)
{
    proto_meter->set_id(std::to_string(meter->getID()));
    proto_meter->set_is_template(std::to_string(meter->getIsTemplate()));
    proto_meter->set_name_line(meter->getNameLine());
    proto_meter->set_name_model(meter->getNameModel());
}