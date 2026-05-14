#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "meter.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using ResponseList = std::vector<std::vector<std::string>>;
using Response = std::vector<std::string>;
class MeterClient
{
public:
    MeterClient(std::shared_ptr<grpc::Channel> channel);

    auto AddMeter(const std::string &meter_id) -> Response;
    auto ListAllCreatedMeters() -> ResponseList;
    auto ListAllAvailableMeters() -> ResponseList;
    auto GetMeasurements(const std::string &meter_id) -> Response;
    auto ListLines() -> Response;
    auto ListCreatedMeters(const std::string &line_name) -> ResponseList;
    auto ListAvailableMeters(const std::string &line_name) -> ResponseList;
    auto RemoveMeter(const std::string &meter_id) -> std::string;

private:
    std::unique_ptr<meter::v1::MeterService::Stub> stub_;
};
