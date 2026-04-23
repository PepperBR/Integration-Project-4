#include "service/meter_service.hpp"

Status MeterService::AddMeter(ServerContext* context, const os::AddMeterRequest* request, os::AddMeterResponse* response) {
    try {
        int model_id = std::stoi(request->model_id());
        this->catalog.addNewModel(model_id);
        
        id_counter++; 
        
        auto new_meter = catalog.getMeterByID(id_counter);
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
    auto line_meters = this->catalog.getLineModels(request->id_line());

    for (const auto& models : line_meters)
    {
        if (!std::get<2>(models))
        {
            CatalogToProto(this->catalog.getMeterByID(std::get<0>(models)), response->add_meters());
        }
    }
    return Status::OK;
}

Status MeterService::ListLines(ServerContext* context, const google::protobuf::Empty* request, os::ListLinesResponse* response) {
    auto lines = this->catalog.getLines();

    for (const auto &line : lines)
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
        auto lines = this->catalog.getLines();
        
        for (const auto& line_name : lines) {
            auto models = this->catalog.getLineModels(line_name);

            bool has_real_meters = false;
            os::Line* proto_line = nullptr;

            for (const auto& m_attr : models) {
                int id = std::get<0>(m_attr);
                bool is_template = std::get<2>(m_attr);

                if (!is_template) {
                    if (!has_real_meters) {
                        proto_line = response->add_line_meters();
                        proto_line->set_name(line_name);
                        has_real_meters = true;
                    }

                    auto meter_ptr = this->catalog.getMeterByID(id);
                    if (meter_ptr) {
                        CatalogToProto(meter_ptr, proto_line->add_meters());
                    }
                }
            }
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
    } catch (const std::exception& e){
        return Status(grpc::StatusCode::NOT_FOUND, e.what());
    }
}

void MeterService::CatalogToProto (std::shared_ptr<Meter> meter, os::Meter* proto_meter)
{
    proto_meter->set_id(std::to_string(meter->getID()));
    proto_meter->set_is_template(std::to_string(meter->getIsTemplate()));
    proto_meter->set_name_line(meter->getNameLine());
    proto_meter->set_name_model(meter->getNameModel());
}