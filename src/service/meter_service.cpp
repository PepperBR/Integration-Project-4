#include "service/meter_service.hpp"

Status MeterService::AddMeter(ServerContext* context, const os::AddMeterRequest* request, os::AddMeterResponse* response) {
    return this->controler.handleAddMeter(request, response, &this->catalog);
}

Status MeterService::ListMeters(ServerContext* context, const os::ListMetersRequest* request, os::ListMetersResponse* response) {
    return this->controler.handleListMeters(request, response, &this->catalog);
}

Status MeterService::ListLines(ServerContext* context, const google::protobuf::Empty* request, os::ListLinesResponse* response) {
    return this->controler.handleListLines(request, response, &this->catalog);
}

Status MeterService::RemoveMeter(ServerContext* context, const os::RemoveMeterRequest* request, os::RemoveMeterResponse* response) {
    return this->controler.handleRemoveMeter(request, response, &this->catalog);
}

Status MeterService::ListAllMeters(ServerContext* context, const google::protobuf::Empty* request, os::ListAllMetersResponse* response) {
    return this->controler.handleListAllMeters(request, response, &this->catalog);
}

Status MeterService::GetMeasurementsPhases(ServerContext* context, const os::GetMeasurementsPhasesRequest* request, os::GetMeasurementsPhasesResponse* response) {
    return this->controler.handleGetMeasurementsPhases(request, response, &this->catalog);
}