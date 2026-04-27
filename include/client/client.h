#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <grpcpp/grpcpp.h>
#include "meter.grpc.pb.h" 

class MeterClient {
public:
    MeterClient(std::shared_ptr<grpc::Channel> channel);

    void AddMeter(const std::string& model_id);
    void ListCreatedMeters();
    void GetMeasurements(const std::string& model_id);
    
private:
    std::unique_ptr<meter::v1::MeterService::Stub> stub_;
};
