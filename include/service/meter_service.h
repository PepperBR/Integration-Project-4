#pragma once

#include <chrono>
#include <mutex>
#include <random>
#include <string>
#include <thread>
#include <time.h>
#include <unordered_map>
#include <vector>

#include "google/protobuf/map.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/server_context.h"
#include "grpcpp/support/status.h"

#include "core/Catalog.h"
#include "core/CatalogControler.h"
#include "meter.grpc.pb.h"
#include "meter.pb.h"
#include "meters/Meter.h"

namespace os = meter::v1;

using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::Status;

class MeterService final : public os::MeterService::Service
{
public:
    grpc::Status AddMeter(grpc::ServerContext *context, const os::AddMeterRequest *request, os::AddMeterResponse *response) override;
    grpc::Status ListAvailableMeters(grpc::ServerContext *context, const os::ListAvailableMetersRequest *request,
                                     os::ListAvailableMetersResponse *response) override;
    grpc::Status ListCreatedMeters(grpc::ServerContext *context, const os::ListCreatedMetersRequest *request,
                                   os::ListCreatedMetersResponse *response) override;
    grpc::Status ListLines(grpc::ServerContext *context, const google::protobuf::Empty *request, os::ListLinesResponse *response) override;
    grpc::Status RemoveMeter(grpc::ServerContext *context, const os::RemoveMeterRequest *request, os::RemoveMeterResponse *response) override;
    grpc::Status ListAllCreatedMeters(grpc::ServerContext *context, const google::protobuf::Empty *request,
                                      os::ListAllCreatedMetersResponse *response) override;
    grpc::Status ListAllAvailableMeters(grpc::ServerContext *context, const google::protobuf::Empty *request,
                                        os::ListAllAvailableMetersResponse *response) override;
    grpc::Status GetMeasurementsPhases(grpc::ServerContext *context, const os::GetMeasurementsPhasesRequest *request,
                                       os::GetMeasurementsPhasesResponse *response) override;

    void CatalogToProto(std::shared_ptr<Meter> meter, os::Meter *proto_meter);

private:
    Catalog catalog;
    CatalogControler controler;
};