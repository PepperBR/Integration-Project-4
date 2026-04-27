#include <catch2/catch_test_macros.hpp>
#include "client/client.h"
#include <grpcpp/grpcpp.h>

MeterClient GetTestClient() {
    auto channel = grpc::CreateChannel("127.0.0.1:50055", grpc::InsecureChannelCredentials());
    return MeterClient(channel);
}

TEST_CASE("Verificando conexão com o servidor", "[grpc]") {
    auto client = GetTestClient();

    SECTION("List Lines") 
    {
        auto lines = client.ListLines();
        REQUIRE_FALSE(lines.empty());
        
        REQUIRE(lines.size() == 4);
        REQUIRE(lines[0] == "Apolo");
        REQUIRE(lines[1] == "Ares");
        REQUIRE(lines[2] == "Cronos");
        REQUIRE(lines[3] == "Zeus");
    }

    SECTION("List Available Meters") 
    {

        auto available_meters_Apolo = client.ListAvailableMeters("Apolo");

        REQUIRE(available_meters_Apolo.size() > 0);
        REQUIRE(available_meters_Apolo.size() == 1);

        REQUIRE(available_meters_Apolo[0][1] == "Apolo");
        REQUIRE(available_meters_Apolo[0][2] == "6031");

        auto available_meters_Zeus = client.ListAvailableMeters("Zeus");

        REQUIRE(available_meters_Zeus.size() > 0);
        REQUIRE(available_meters_Zeus.size() == 3);

        REQUIRE(available_meters_Zeus[0][1] == "Zeus");
        REQUIRE(available_meters_Zeus[1][1] == "Zeus");
        REQUIRE(available_meters_Zeus[2][1] == "Zeus");

        REQUIRE(available_meters_Zeus[0][2] == "8021");
        REQUIRE(available_meters_Zeus[1][2] == "8023");
        REQUIRE(available_meters_Zeus[2][2] == "8031");

        auto available_meters_Ares = client.ListAvailableMeters("Ares");

        REQUIRE(available_meters_Ares.size() > 0);
        REQUIRE(available_meters_Ares.size() == 6);

        CHECK(available_meters_Ares[0][1] == "Ares");
        CHECK(available_meters_Ares[1][1] == "Ares");
        CHECK(available_meters_Ares[2][1] == "Ares");
        CHECK(available_meters_Ares[3][1] == "Ares");
        CHECK(available_meters_Ares[4][1] == "Ares");
        CHECK(available_meters_Ares[5][1] == "Ares");

        CHECK(available_meters_Ares[0][2] == "7021");
        CHECK(available_meters_Ares[1][2] == "8023"); 
        CHECK(available_meters_Ares[2][2] == "7023"); 
        CHECK(available_meters_Ares[3][2] == "7031"); 
        CHECK(available_meters_Ares[4][2] == "8023 15");
        CHECK(available_meters_Ares[5][2] == "8023 200");

        auto available_meters_Cronos = client.ListAvailableMeters("Cronos");

        REQUIRE(available_meters_Cronos.size() > 0);
        REQUIRE(available_meters_Cronos.size() == 7);

        CHECK(available_meters_Cronos[0][1] == "Cronos");
        CHECK(available_meters_Cronos[1][1] == "Cronos");
        CHECK(available_meters_Cronos[2][1] == "Cronos");
        CHECK(available_meters_Cronos[3][1] == "Cronos");
        CHECK(available_meters_Cronos[4][1] == "Cronos");
        CHECK(available_meters_Cronos[5][1] == "Cronos");
        CHECK(available_meters_Cronos[6][1] == "Cronos");

        CHECK(available_meters_Cronos[0][2] == "7023"); 
        CHECK(available_meters_Cronos[1][2] == "7023 L");  
        CHECK(available_meters_Cronos[2][2] == "7023 2.5");
        CHECK(available_meters_Cronos[3][2] == "6021 L"); 
        CHECK(available_meters_Cronos[4][2] == "6021 A"); 
        CHECK(available_meters_Cronos[5][2] == "6003"); 
        CHECK(available_meters_Cronos[6][2] == "6001 A");
    }

}