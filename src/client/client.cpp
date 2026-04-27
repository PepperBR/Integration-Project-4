#include "client/client.h"


MeterClient::MeterClient(std::shared_ptr<grpc::Channel> channel)
    : stub_(meter::v1::MeterService::NewStub(channel)) 
{}

void MeterClient::AddMeter(const std::string& model_id)
{
    meter::v1::AddMeterRequest request;
    request.set_meter_id(model_id);

    meter::v1::AddMeterResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->AddMeter(&context, request, &response);

    if (status.ok()) {
        std::cout << "--- Medidor criado com sucesso ---" << std::endl;
        std::cout << "ID: " << response.meter_id().id() << std::endl;
        std::cout << "Modelo: " << response.meter_id().model_name() << std::endl;
    } else {
        std::cout << "Erro gRPC (" << status.error_code() << "): " << status.error_message() << std::endl;
    }
}

void MeterClient::ListCreatedMeters()
{
    google::protobuf::Empty request;
    meter::v1::ListAllCreatedMetersResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->ListAllCreatedMeters(&context, request, &response);

    if (status.ok()) {
        std::cout << "--- Lista de todos os medidores por Linha ---" << std::endl;
        for (const auto& line : response.line_meters()) {
            std::cout << "\nLinha: " << line.name() << std::endl;
            for (const auto& m : line.meters()) {
                std::cout << "  [ID: " << m.id() << "] Modelo: " << m.model_name() << std::endl;
            }
        }
    } else {
        std::cout << "Falha ao listar: " << status.error_message() << std::endl;
    }
}

void MeterClient::GetMeasurements(const std::string& model_id)
{
    grpc::ClientContext contex;
    meter::v1::GetMeasurementsPhasesRequest request;
    request.set_meter_id(model_id);

    meter::v1::GetMeasurementsPhasesResponse response;

    grpc::Status status = stub_->GetMeasurementsPhases(&contex, request, &response);
    if (status.ok()){
        std::cout << "--- Lista com as medições das fases do medidor ---" << std::endl;
        int cont = 0;
        for (const auto& valores : response.measurements_values()) {
            ++cont;
            std::cout << "Valor da " << cont << "º fase = " << valores << std::endl;
        }
    } else {
        std::cout << "Falha em encontrar as medições: " << status.error_message() << std::endl;
    }
}

