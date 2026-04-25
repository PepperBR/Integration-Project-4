#pragma once

#include "grpcpp/grpcpp.h"
#include "grpcpp/server_context.h"
#include "grpcpp/support/status.h"
#include "google/protobuf/map.h"

#include "core/Catalog.h"
#include "meter.pb.h"

namespace os = meter::v1;

using grpc::Status;
using grpc::StatusCode;

class CatalogControler
{
    public:
        grpc::Status handleAddMeter(const os::AddMeterRequest* request, os::AddMeterResponse* response, Catalog* catalog);
        grpc::Status handleListMeters(const os::ListMetersRequest* request, os::ListMetersResponse* response, Catalog* catalog);
        grpc::Status handleListLines(const google::protobuf::Empty* request, os::ListLinesResponse* response, Catalog* catalog);
        grpc::Status handleRemoveMeter(const os::RemoveMeterRequest* request, os::RemoveMeterResponse* response, Catalog* catalog);
        grpc::Status handleListAllMeters(const google::protobuf::Empty* request, os::ListAllMetersResponse* response, Catalog* catalog);
        grpc::Status handleGetMeasurementsPhases(const os::GetMeasurementsPhasesRequest* request, os::GetMeasurementsPhasesResponse* response, Catalog* catalog);

        void handleCatalogToProto (std::shared_ptr<Meter> meter, os::Meter* proto_meter);
    private:
};