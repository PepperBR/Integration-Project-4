#include <catch2/catch_test_macros.hpp>
#include "client/client.h"
#include <grpcpp/grpcpp.h>

MeterClient GetTestClient() {
    auto channel = grpc::CreateChannel("127.0.0.1:50055", grpc::InsecureChannelCredentials());
    return MeterClient(channel);
}

TEST_CASE("Métodos do Client")
{
    SECTION("List Created Meters Before Adding") 
    {
        auto client = GetTestClient();
        
        auto list_created_meters_Apolo = client.ListCreatedMeters("Apolo");
        REQUIRE(list_created_meters_Apolo.empty());

        auto list_created_meters_Zeus = client.ListCreatedMeters("Zeus");
        REQUIRE(list_created_meters_Zeus.empty());

        auto list_created_meters_Ares = client.ListCreatedMeters("Ares");
        REQUIRE(list_created_meters_Ares.empty());

        auto list_created_meters_Cronos = client.ListCreatedMeters("Cronos");
        REQUIRE(list_created_meters_Cronos.empty());
    }

    SECTION("List Lines") 
    {
        auto client = GetTestClient();
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
        auto client = GetTestClient();

        auto available_meters_Pimenta = client.ListAvailableMeters("Pimenta");
        REQUIRE_FALSE(available_meters_Pimenta.size() > 0);

        auto available_meters_Apolo = client.ListAvailableMeters("Apolo");

        REQUIRE(available_meters_Apolo.size() > 0);
        REQUIRE(available_meters_Apolo.size() == 1);
        REQUIRE(available_meters_Apolo[0][1] + ' ' + available_meters_Apolo[0][2] == "Apolo 6031");

        auto available_meters_Ares = client.ListAvailableMeters("Ares");

        REQUIRE(available_meters_Ares.size() > 0);
        REQUIRE(available_meters_Ares.size() == 6);

        REQUIRE(available_meters_Ares[0][1] + ' ' + available_meters_Ares[0][2] == "Ares 7021");   
        REQUIRE(available_meters_Ares[1][1] + ' ' + available_meters_Ares[1][2] == "Ares 8023");    
        REQUIRE(available_meters_Ares[2][1] + ' ' + available_meters_Ares[2][2] == "Ares 7023");    
        REQUIRE(available_meters_Ares[3][1] + ' ' + available_meters_Ares[3][2] == "Ares 7031");    
        REQUIRE(available_meters_Ares[4][1] + ' ' + available_meters_Ares[4][2] == "Ares 8023 15");   
        REQUIRE(available_meters_Ares[5][1] + ' ' + available_meters_Ares[5][2] == "Ares 8023 200");  
        
        auto available_meters_Cronos = client.ListAvailableMeters("Cronos");

        REQUIRE(available_meters_Cronos.size() > 0);
        REQUIRE(available_meters_Cronos.size() == 7);

        REQUIRE(available_meters_Cronos[0][1] + ' ' + available_meters_Cronos[0][2] == "Cronos 7023");  
        REQUIRE(available_meters_Cronos[1][1] + ' ' + available_meters_Cronos[1][2] == "Cronos 7023 L");   
        REQUIRE(available_meters_Cronos[2][1] + ' ' + available_meters_Cronos[2][2] == "Cronos 7023 2.5");    
        REQUIRE(available_meters_Cronos[3][1] + ' ' + available_meters_Cronos[3][2] == "Cronos 6021 L");    
        REQUIRE(available_meters_Cronos[4][1] + ' ' + available_meters_Cronos[4][2] == "Cronos 6021 A");    
        REQUIRE(available_meters_Cronos[5][1] + ' ' + available_meters_Cronos[5][2] == "Cronos 6003");   
        REQUIRE(available_meters_Cronos[6][1] + ' ' + available_meters_Cronos[6][2] == "Cronos 6001 A"); 

        auto available_meters_Zeus = client.ListAvailableMeters("Zeus");

        REQUIRE(available_meters_Zeus.size() > 0);
        REQUIRE(available_meters_Zeus.size() == 3);

        REQUIRE(available_meters_Zeus[0][1] + ' ' + available_meters_Zeus[0][2] == "Zeus 8021");    
        REQUIRE(available_meters_Zeus[1][1] + ' ' + available_meters_Zeus[1][2] == "Zeus 8023");    
        REQUIRE(available_meters_Zeus[2][1] + ' ' + available_meters_Zeus[2][2] == "Zeus 8031"); 
    }

    SECTION("List All Available Meters") 
    {
        auto client = GetTestClient();

        auto all_available_meters = client.ListAllAvailableMeters();

        REQUIRE(all_available_meters.size() > 0);
        REQUIRE(all_available_meters.size() == 17);

        REQUIRE(all_available_meters[0][1] + ' ' + all_available_meters[0][2] == "Apolo 6031");

        REQUIRE(all_available_meters[1][1] + ' ' + all_available_meters[1][2] == "Ares 7021");   
        REQUIRE(all_available_meters[2][1] + ' ' + all_available_meters[2][2] == "Ares 8023");    
        REQUIRE(all_available_meters[3][1] + ' ' + all_available_meters[3][2] == "Ares 7023");    
        REQUIRE(all_available_meters[4][1] + ' ' + all_available_meters[4][2] == "Ares 7031");    
        REQUIRE(all_available_meters[5][1] + ' ' + all_available_meters[5][2] == "Ares 8023 15");   
        REQUIRE(all_available_meters[6][1] + ' ' + all_available_meters[6][2] == "Ares 8023 200");  
        
        REQUIRE(all_available_meters[7][1] + ' ' + all_available_meters[7][2] == "Cronos 7023");  
        REQUIRE(all_available_meters[8][1] + ' ' + all_available_meters[8][2] == "Cronos 7023 L");   
        REQUIRE(all_available_meters[9][1] + ' ' + all_available_meters[9][2] == "Cronos 7023 2.5");    
        REQUIRE(all_available_meters[10][1] + ' ' + all_available_meters[10][2] == "Cronos 6021 L");    
        REQUIRE(all_available_meters[11][1] + ' ' + all_available_meters[11][2] == "Cronos 6021 A");    
        REQUIRE(all_available_meters[12][1] + ' ' + all_available_meters[12][2] == "Cronos 6003");   
        REQUIRE(all_available_meters[13][1] + ' ' + all_available_meters[13][2] == "Cronos 6001 A"); 

        REQUIRE(all_available_meters[14][1] + ' ' + all_available_meters[14][2] == "Zeus 8021");    
        REQUIRE(all_available_meters[15][1] + ' ' + all_available_meters[15][2] == "Zeus 8023");    
        REQUIRE(all_available_meters[16][1] + ' ' + all_available_meters[16][2] == "Zeus 8031"); 
    }

    SECTION("Add New Meter") 
    {
        auto client = GetTestClient();

        auto new_meter_added_ID_18 = client.AddMeter("18");
        REQUIRE(new_meter_added_ID_18.empty());

        auto new_meter_added_ID_1 = client.AddMeter("1");

        REQUIRE(new_meter_added_ID_1.size() > 0);
        REQUIRE(new_meter_added_ID_1.size() == 3);

        REQUIRE(new_meter_added_ID_1[0] == "18");
        REQUIRE(new_meter_added_ID_1[1] == "Apolo");
        REQUIRE(new_meter_added_ID_1[2] == "6031");

        auto new_meter_added_ID_2 = client.AddMeter("2");

        REQUIRE(new_meter_added_ID_2.size() > 0);
        REQUIRE(new_meter_added_ID_2.size() == 3);

        REQUIRE(new_meter_added_ID_2[0] == "19");
        REQUIRE(new_meter_added_ID_2[1] == "Zeus");
        REQUIRE(new_meter_added_ID_2[2] == "8021");
    }

    SECTION("List Created Meters After Adding") 
    {
        auto client = GetTestClient();
        
        auto new_meter_added_ID_2 = client.AddMeter("2");
        auto list_created_meters_Apolo = client.ListCreatedMeters("Apolo");
        REQUIRE(list_created_meters_Apolo.size() == 1);

        auto list_created_meters_Zeus = client.ListCreatedMeters("Zeus");
        REQUIRE(list_created_meters_Zeus.size() == 2);

        auto list_created_meters_Ares = client.ListCreatedMeters("Ares");
        REQUIRE(list_created_meters_Ares.empty());

        auto list_created_meters_Cronos = client.ListCreatedMeters("Cronos");
        REQUIRE(list_created_meters_Cronos.empty());
    }

    SECTION("List All Created Meters")
    {
        auto client = GetTestClient();

        auto list_all_created_meters = client.ListAllCreatedMeters();

        REQUIRE(list_all_created_meters.size() > 0);
        REQUIRE(list_all_created_meters.size() == 3);
        REQUIRE(list_all_created_meters[0][1] + ' ' + list_all_created_meters[0][2] == "Apolo 6031");
        REQUIRE(list_all_created_meters[1][1] + ' ' + list_all_created_meters[1][2] == "Zeus 8021");
        REQUIRE(list_all_created_meters[2][1] + ' ' + list_all_created_meters[2][2] == "Zeus 8021");
    }

    SECTION("Get Measuarements")
    {
        auto client = GetTestClient();

        auto values_mesuarements_ID_18 = client.GetMeasurements("18");
        REQUIRE(values_mesuarements_ID_18.size() > 0);
        REQUIRE(values_mesuarements_ID_18.size() == 3);

        auto values_mesuarements_ID_1 = client.GetMeasurements("1");
        REQUIRE(values_mesuarements_ID_1.empty());

        auto values_mesuarements_ID_19 = client.GetMeasurements("19");
        REQUIRE(values_mesuarements_ID_19.size() > 0);
        REQUIRE(values_mesuarements_ID_19.size() == 1);
    }

    SECTION("Remove Meter")
    {
        auto client = GetTestClient();
        auto result_remove_ID_18 = client.RemoveMeter("18");

        REQUIRE(result_remove_ID_18.length() != 0);
        REQUIRE(result_remove_ID_18 == "removed");

        auto list_remainig_created_meters_Apolo = client.ListCreatedMeters("Apolo");
        REQUIRE(list_remainig_created_meters_Apolo.empty());

        auto result_remove_ID_1 = client.RemoveMeter("1");

        REQUIRE(result_remove_ID_1.length() != 0);
        REQUIRE(result_remove_ID_1 == "not removed");
    }
}