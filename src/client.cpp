#include <iostream>
#include <string>
#include <memory>

#include <grpcpp/grpcpp.h>
#include "meter.grpc.pb.h" 

class MeterClient {
public:
    MeterClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(meter::v1::MeterService::NewStub(channel)) {}

    void AddMeter(const std::string& model_id) {
        meter::v1::AddMeterRequest request;
        request.set_model_id(model_id);

        meter::v1::AddMeterResponse response;
        grpc::ClientContext context;

        grpc::Status status = stub_->AddMeter(&context, request, &response);

        if (status.ok()) {
            std::cout << ">>> Medidor criado com sucesso!" << std::endl;
            std::cout << "ID: " << response.meter_created().id() << std::endl;
            std::cout << "Modelo: " << response.meter_created().name_model() << std::endl;
        } else {
            std::cout << "Erro gRPC (" << status.error_code() << "): " << status.error_message() << std::endl;
        }
    }

    void ListAll() {
        google::protobuf::Empty request;
        meter::v1::ListAllMetersResponse response;
        grpc::ClientContext context;

        grpc::Status status = stub_->ListAllMeters(&context, request, &response);

        if (status.ok()) {
            std::cout << "--- LISTA DE TODOS OS MEDIDORES POR LINHA ---" << std::endl;
            for (const auto& line : response.line_meters()) {
                std::cout << "\nLinha: " << line.name() << std::endl;
                for (const auto& m : line.meters()) {
                    std::cout << "  [ID: " << m.id() << "] Modelo: " << m.name_model() 
                              << " | Template: " << m.is_template() << std::endl;
                }
            }
        } else {
            std::cout << "Falha ao listar: " << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<meter::v1::MeterService::Stub> stub_;
};

int main() {
    std::string target_address = "127.0.0.1:50055"; 

    auto channel = grpc::CreateChannel(target_address, grpc::InsecureChannelCredentials());
    MeterClient client(channel);

    std::cout << "Conectado ao servidor em " << target_address << std::endl;

    
    try 
    {
        std::cout << "\nBuscando todos os medidores registrados..." << std::endl;
        client.ListAll();

        std::cout << "\nTentando adicionar um medidor (ID de template 6)..." << std::endl;
        client.AddMeter("6");

        std::cout << "\nTentando adicionar um medidor (ID de template 1)..." << std::endl;
        client.AddMeter("1");

        std::cout << "\nBuscando todos os medidores registrados..." << std::endl;
        client.ListAll();
    }
    catch (const std::exception& e) {
        std::cerr << "Erro fatal: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}