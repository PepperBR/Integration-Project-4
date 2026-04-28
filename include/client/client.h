#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <grpcpp/grpcpp.h>
#include "meter.grpc.pb.h" 

using ResponseList = std::vector<std::vector<std::string>>;
using Response = std::vector<std::string>;
class MeterClient {
public:
    MeterClient(std::shared_ptr<grpc::Channel> channel);

    Response AddMeter(const std::string& meter_id); 
    ResponseList ListAllCreatedMeters(); 
    ResponseList ListAllAvailableMeters(); 
    Response GetMeasurements(const std::string& meter_id); 
    Response ListLines(); 
    ResponseList ListCreatedMeters(const std::string& line_name); 
    ResponseList ListAvailableMeters(const std::string& line_name); 
    std::string RemoveMeter(const std::string& meter_id); 
private:
    std::unique_ptr<meter::v1::MeterService::Stub> stub_;
};
