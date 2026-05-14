#include "client/client.h"

MeterClient::MeterClient(std::shared_ptr<grpc::Channel> channel)
    : stub_(meter::v1::MeterService::NewStub(channel))
{
}

Response MeterClient::AddMeter(const std::string &meter_id)
{
    meter::v1::AddMeterRequest request;
    request.set_meter_id(meter_id);

    meter::v1::AddMeterResponse response;
    grpc::ClientContext context;

    Response new_meter_added;

    grpc::Status status = stub_->AddMeter(&context, request, &response);

    if (status.ok())
    {
        new_meter_added.push_back(response.meter_id().id());
        new_meter_added.push_back(response.meter_id().line_name());
        new_meter_added.push_back(response.meter_id().model_name());
    }
    else
    {
        std::cout << "Erro gRPC (" << status.error_code() << "): " << status.error_message() << std::endl;
    }
    return new_meter_added;
}

ResponseList MeterClient::ListAllCreatedMeters()
{
    google::protobuf::Empty request;
    meter::v1::ListAllCreatedMetersResponse response;
    grpc::ClientContext context;

    ResponseList list_all_created_meters;

    grpc::Status status = stub_->ListAllCreatedMeters(&context, request, &response);

    if (status.ok())
    {
        for (const auto &line : response.line_meters())
        {
            for (const auto &meters_created : line.meters())
            {
                std::vector<std::string> meter;

                meter.push_back(meters_created.id());
                meter.push_back(meters_created.line_name());
                meter.push_back(meters_created.model_name());

                list_all_created_meters.push_back(meter);
            }
        }
    }
    else
    {
        std::cout << "Falha ao listar: " << status.error_message() << std::endl;
    }
    return list_all_created_meters;
}

ResponseList MeterClient::ListAllAvailableMeters()
{
    google::protobuf::Empty request;
    meter::v1::ListAllAvailableMetersResponse response;
    grpc::ClientContext context;

    ResponseList list_all_available_meters;

    grpc::Status status = stub_->ListAllAvailableMeters(&context, request, &response);

    if (status.ok())
    {
        for (const auto &line : response.line_meters())
        {
            for (const auto &meters_available : line.meters())
            {
                std::vector<std::string> meter;

                meter.push_back(meters_available.id());
                meter.push_back(meters_available.line_name());
                meter.push_back(meters_available.model_name());

                list_all_available_meters.push_back(meter);
            }
        }
    }
    else
    {
        std::cout << "Falha ao listar: " << status.error_message() << std::endl;
    }
    return list_all_available_meters;
}

Response MeterClient::ListLines()
{
    google::protobuf::Empty request;
    meter::v1::ListLinesResponse response;
    grpc::ClientContext context;

    Response lines;

    grpc::Status status = stub_->ListLines(&context, request, &response);
    if (status.ok())
    {
        for (const auto &line : response.lines())
        {
            lines.push_back(line);
        }
    }
    else
    {
        std::cout << "Falha ao listar: " << status.error_message() << std::endl;
    }
    return lines;
}

Response MeterClient::GetMeasurements(const std::string &meter_id)
{
    grpc::ClientContext contex;
    meter::v1::GetMeasurementsPhasesRequest request;
    request.set_meter_id(meter_id);

    Response mesuarements_values;

    meter::v1::GetMeasurementsPhasesResponse response;

    grpc::Status status = stub_->GetMeasurementsPhases(&contex, request, &response);
    if (status.ok())
    {
        int cont = 0;
        for (const auto &valores : response.measurements_values())
        {
            mesuarements_values.push_back(valores);
        }
    }
    else
    {
        std::cout << "Falha em encontrar as medições: " << status.error_message() << std::endl;
    }
    return mesuarements_values;
}

ResponseList MeterClient::ListCreatedMeters(const std::string &line_name)
{
    meter::v1::ListCreatedMetersRequest request;
    meter::v1::ListCreatedMetersResponse response;
    grpc::ClientContext context;

    ResponseList list_meters_created;

    request.set_line_name(line_name);

    grpc::Status status = stub_->ListCreatedMeters(&context, request, &response);
    if (status.ok())
    {
        for (const auto &meters_created : response.meters())
        {
            std::vector<std::string> meter;

            meter.push_back(meters_created.id());
            meter.push_back(meters_created.line_name());
            meter.push_back(meters_created.model_name());

            list_meters_created.push_back(meter);
        }
    }
    else
    {
        std::cout << "Falha em listar os medidores criados da linha  " << line_name << " : " << status.error_message() << std::endl;
    }
    return list_meters_created;
}

ResponseList MeterClient::ListAvailableMeters(const std::string &line_name)
{
    meter::v1::ListAvailableMetersRequest request;
    meter::v1::ListAvailableMetersResponse response;
    grpc::ClientContext context;

    ResponseList list_meters_availabe;

    request.set_line_name(line_name);

    grpc::Status status = stub_->ListAvailableMeters(&context, request, &response);
    if (status.ok())
    {
        for (const auto &meters_created : response.meters())
        {
            std::vector<std::string> meter;

            meter.push_back(meters_created.id());
            meter.push_back(meters_created.line_name());
            meter.push_back(meters_created.model_name());

            list_meters_availabe.push_back(meter);
        }
    }
    else
    {
        std::cout << "Falha em listar os medidores criados da linha  " << line_name << " : " << status.error_message() << std::endl;
    }
    return list_meters_availabe;
}

std::string MeterClient::RemoveMeter(const std::string &meter_id)
{
    meter::v1::RemoveMeterRequest request;
    request.set_meter_id(meter_id);

    meter::v1::RemoveMeterResponse response;
    grpc::ClientContext context;

    std::string result;

    grpc::Status status = stub_->RemoveMeter(&context, request, &response);

    if (status.ok())
    {
        result = response.result();
    }
    else
    {
        std::cout << "Erro gRPC (" << status.error_code() << "): " << status.error_message() << std::endl;
    }
    return result;
}
