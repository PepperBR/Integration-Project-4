#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <grpcpp/grpcpp.h>
#include "meter.grpc.pb.h" 

class MeterClient {
public:
    MeterClient(std::shared_ptr<grpc::Channel> channel);

    void AddMeter(const std::string& meter_id);
    void ListAllCreatedMeters();
    void ListAllAvailableMeters();
    void GetMeasurements(const std::string& meter_id);
    std::vector<std::string> ListLines();
    void ListCreatedMeters(const std::string& line_name);
    std::vector<std::vector<std::string>> ListAvailableMeters(const std::string& line_name);
    void RemoveMeter(const std::string& meter_id);
private:
    std::unique_ptr<meter::v1::MeterService::Stub> stub_;
};
