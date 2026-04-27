#pragma once

#include <unordered_map>
#include <vector>
#include <mutex>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <time.h>

#include "grpcpp/grpcpp.h"
#include "grpcpp/server_context.h"
#include "grpcpp/support/status.h"
#include "google/protobuf/map.h"

#include "meter.grpc.pb.h"
#include "meter.pb.h"
#include "core/Catalog.h"
#include "core/GlobalID.h"
#include "meters/Meter.h"
#include "core/CatalogControler.h"

namespace os = meter::v1;

using grpc::Status;
using grpc::ServerContext;
using grpc::ServerWriter;

class MeterService final : public os::MeterService::Service
{
public:
    grpc::Status AddMeter (grpc::ServerContext* context, const os::AddMeterRequest* request, os::AddMeterResponse* response) override;
    grpc::Status ListAvailableMeters (grpc::ServerContext* context, const os::ListAvailableMetersRequest* request, os::ListAvailableMetersResponse* response) override;
    grpc::Status ListCreatedMeters (grpc::ServerContext* context, const os::ListCreatedMetersRequest* request, os::ListCreatedMetersResponse* response) override;
    grpc::Status ListLines (grpc::ServerContext* context, const google::protobuf::Empty* request, os::ListLinesResponse* response) override;
    grpc::Status RemoveMeter (grpc::ServerContext* context, const os::RemoveMeterRequest* request, os::RemoveMeterResponse* response) override;
    grpc::Status ListAllCreatedMeters (grpc::ServerContext* context, const google::protobuf::Empty* request, os::ListAllCreatedMetersResponse* response) override;
    grpc::Status ListAllAvailableMeters (grpc::ServerContext* context, const google::protobuf::Empty* request, os::ListAllAvailableMetersResponse* response) override;
    grpc::Status GetMeasurementsPhases (grpc::ServerContext* context, const os::GetMeasurementsPhasesRequest* request, os::GetMeasurementsPhasesResponse* response) override;

    void CatalogToProto (std::shared_ptr<Meter> meter, os::Meter* proto_meter);
private:
    Catalog catalog;
    CatalogControler controler;
}; 