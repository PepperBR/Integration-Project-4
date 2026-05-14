#include "service/meter_service.h"

Status MeterService::AddMeter(ServerContext *context, const os::AddMeterRequest *request, os::AddMeterResponse *response)
{
    return this->controler.handleAddMeter(request, response, &this->catalog);
}

Status MeterService::ListAvailableMeters(ServerContext *context, const os::ListAvailableMetersRequest *request,
                                         os::ListAvailableMetersResponse *response)
{
    return this->controler.handleListAvailableMeters(request, response, &this->catalog);
}

Status MeterService::ListCreatedMeters(ServerContext *context, const os::ListCreatedMetersRequest *request, os::ListCreatedMetersResponse *response)
{
    return this->controler.handleListCreatedMeters(request, response, &this->catalog);
}

Status MeterService::ListLines(ServerContext *context, const google::protobuf::Empty *request, os::ListLinesResponse *response)
{
    return this->controler.handleListLines(request, response, &this->catalog);
}

Status MeterService::RemoveMeter(ServerContext *context, const os::RemoveMeterRequest *request, os::RemoveMeterResponse *response)
{
    return this->controler.handleRemoveMeter(request, response, &this->catalog);
}

Status MeterService::ListAllCreatedMeters(ServerContext *context, const google::protobuf::Empty *request, os::ListAllCreatedMetersResponse *response)
{
    return this->controler.handleListAllCreatedMeters(request, response, &this->catalog);
}

Status MeterService::ListAllAvailableMeters(ServerContext *context, const google::protobuf::Empty *request,
                                            os::ListAllAvailableMetersResponse *response)
{
    return this->controler.handleListAllAvailableMeters(request, response, &this->catalog);
}

Status MeterService::GetMeasurementsPhases(ServerContext *context, const os::GetMeasurementsPhasesRequest *request,
                                           os::GetMeasurementsPhasesResponse *response)
{
    return this->controler.handleGetMeasurementsPhases(request, response, &this->catalog);
}