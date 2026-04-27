#include <iostream>
#include <string>
#include <memory>

#include <grpcpp/grpcpp.h>
#include "meter.grpc.pb.h" 

#include "client/client.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);
    std::string target_address = "127.0.0.1:50055"; 

    auto channel = grpc::CreateChannel(target_address, grpc::InsecureChannelCredentials());
    MeterClient client(channel);

    std::cout << "Conectado ao servidor em " << target_address << std::endl;

    
    try 
    {
        std::cout << "\nBuscando todos os medidores disponíveis..." << std::endl;
        client.ListAllAvailableMeters();

        std::cout << "\nTentando adicionar um medidor (ID de template 6)..." << std::endl;
        client.AddMeter("6");
        
        std::cout << "\nTentando adicionar um medidor (ID de template 1)..." << std::endl;
        client.AddMeter("1");

        std::cout << "\nTentando listar as medições das fases de um medidor (ID 18)..." << std::endl;
        client.GetMeasurements("18");
        
        std::cout << "\nTentando listar as medições das fases de um medidor (ID 19)..." << std::endl;
        client.GetMeasurements("19");
        
        client.ListAllCreatedMeters();
    }
    catch (const std::exception& e) {
        std::cerr << "Erro fatal: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}