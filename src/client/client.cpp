#include "client/client.h"


MeterClient::MeterClient(std::shared_ptr<grpc::Channel> channel)
    : stub_(meter::v1::MeterService::NewStub(channel)) 
{}

void MeterClient::AddMeter(const std::string& meter_id)
{
    meter::v1::AddMeterRequest request;
    request.set_meter_id(meter_id);

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

void MeterClient::ListAllCreatedMeters()
{
    google::protobuf::Empty request;
    meter::v1::ListAllCreatedMetersResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->ListAllCreatedMeters(&context, request, &response);

    if (status.ok()) {
        std::cout << "--- Lista de todos os medidores criados da Linha ---" << std::endl;
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

void MeterClient::ListAllAvailableMeters()
{
    google::protobuf::Empty request;
    meter::v1::ListAllAvailableMetersResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->ListAllAvailableMeters(&context, request, &response);

    if (status.ok()) {
        std::cout << "--- Lista de todos os medidores disponíveis da Linha ---" << std::endl;
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

void MeterClient::ListLines()
{
    google::protobuf::Empty request;
    meter::v1::ListLinesResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->ListLines(&context, request, &response);
    if (status.ok())
    {
        std::cout << "--- Lista de linhas disponíveis ---" << std::endl;
        for (const auto& line : response.lines())
        {
            std::cout << "\nLinha: " << line << std::endl;
        }
    } else {
        std::cout << "Falha ao listar: " << status.error_message() << std::endl;
    }
}
void MeterClient::GetMeasurements(const std::string& meter_id)
{
    grpc::ClientContext contex;
    meter::v1::GetMeasurementsPhasesRequest request;
    request.set_meter_id(meter_id);

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

void MeterClient::ListCreatedMeters(const std::string& line_name)
{
    meter::v1::ListCreatedMetersRequest request;
    meter::v1::ListCreatedMetersResponse response;
    grpc::ClientContext context;

    request.set_line_name(line_name);

    grpc::Status status = stub_->ListCreatedMeters(&context, request, &response);
    if (status.ok())
    {
        std::cout << "--- Aqui estão a lista de medidores criados da linha " << line_name << " ---" << std::endl;
        for (const auto& meters_created : response.meters())
        {
             std::cout << "  [ID: " << meters_created.id() << "] Modelo: " << meters_created.model_name() << std::endl;
        }
    } else {
        std::cout << "Falha em listar os medidores criados da linha  " << line_name << " : " << status.error_message() << std::endl;
    }
}


void MeterClient::ListAvailableMeters(const std::string& line_name)
{
    meter::v1::ListAvailableMetersRequest request;
    meter::v1::ListAvailableMetersResponse response;
    grpc::ClientContext context;

    request.set_line_name(line_name);

    grpc::Status status = stub_->ListAvailableMeters(&context, request, &response);
    if (status.ok())
    {
        std::cout << "--- Aqui estão a lista de medidores disponíveis da linha " << line_name << " ---" << std::endl;
        for (const auto& meters_created : response.meters())
        {
             std::cout << "  [ID: " << meters_created.id() << "] Modelo: " << meters_created.model_name() << std::endl;
        }
    } else {
        std::cout << "Falha em listar os medidores criados da linha  " << line_name << " : " << status.error_message() << std::endl;
    }
}

void MeterClient::RemoveMeter(const std::string& meter_id)
{
    meter::v1::RemoveMeterRequest request;
    request.set_meter_id(meter_id);

    meter::v1::RemoveMeterResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->RemoveMeter(&context, request, &response);

    if (status.ok()) {
        std::cout << "--- Medidor com ID ["<< meter_id <<"] apagado com sucesso ---" << std::endl;
    } else {
        std::cout << "Erro gRPC (" << status.error_code() << "): " << status.error_message() << std::endl;
    }
}




