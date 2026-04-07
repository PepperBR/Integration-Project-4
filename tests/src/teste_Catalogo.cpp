#include "core/Catalog.h"
#include "catch.hpp"
#include <string>
#include <list>
#include <tuple>
#include <vector>

namespace jmcp
{


TEST_CASE("Testing Methods")
{
    SECTION("getLines()")
    {
        Catalog catalog;
        std::string expected_lines[] = {"Apolo", "Ares", "Cronos", "Zeus"};
    
        int index = 0;
        auto lines = catalog.getLines();
    
        REQUIRE(lines.size() == 4);
    
        for (const auto &line : lines)
        {
            REQUIRE(line == expected_lines[index++]);
        }
    };

    SECTION("getLineModels()")
    {
        Catalog catalog;
        std::string expected_models_Apolo[] = {"Apolo 6031"};
        std::string expected_models_Zeus[] = {"Zeus 8021","Zeus 8023","Zeus 8031"};
        std::string expected_models_Cronos[] = {"Cronos 7023","Cronos 7023 L","Cronos 7023 2.5","Cronos 6021 L","Cronos 6021 A","Cronos 6003","Cronos 6001 A"};
        std::string expected_models_Ares[] = {"Ares 7021","Ares 8023","Ares 7023","Ares 7031","Ares 8023 15","Ares 8023 200"};

        int index = 0;
        auto models_apolo = catalog.getLineModels("Apolo");
        auto models_zeus = catalog.getLineModels("Zeus");
        auto models_cronos = catalog.getLineModels("Cronos");
        auto models_ares = catalog.getLineModels("Ares");

        for (const auto &model : models_apolo)
        {
            REQUIRE(std::get<1>(model) == expected_models_Apolo[index++]);
        }

        index = 0;
        for (const auto &model : models_zeus)
        {
            REQUIRE(std::get<1>(model) == expected_models_Zeus[index++]);
        }

        index = 0;
        for (const auto &model : models_cronos)
        {
            REQUIRE(std::get<1>(model) == expected_models_Cronos[index++]);
        }

        index = 0;
        for (const auto &model : models_ares)
        {
            REQUIRE(std::get<1>(model) == expected_models_Ares[index++]);
        }
    };

    SECTION("getLines()")
    {
        Catalog catalog;
        std::string expected_lines[] = {"Apolo", "Ares", "Cronos", "Zeus"};
    
        int index = 0;
        auto lines = catalog.getLines();
    
        REQUIRE(lines.size() == 4);
    
        for (const auto &line : lines)
        {
            REQUIRE(line == expected_lines[index++]);
        }
    };
}

TEST_CASE("Testing if new model is being added to meter_list")
{
    SECTION("Add new Model")
    {
        Catalog catalog;
        REQUIRE(catalog.getLineModels("Apolo").size() == 1);
        catalog.addNewModel(1);
        REQUIRE(catalog.getLineModels("Apolo").size() == 2);
    }
}

TEST_CASE("Testing if is possible to remove a new model")
{
    SECTION("Remove new Model")
    {
        Catalog catalog;
        catalog.addNewModel(1); // ID = 18
        REQUIRE(catalog.getLineModels("Apolo").size() == 2);
        
        catalog.removeModel(18);
        REQUIRE(catalog.getLineModels("Apolo").size() == 1);

    }
    SECTION("Remove Template")
    {
        Catalog catalog;

        catalog.removeModel(2); // removing Template Zeus 8021
        REQUIRE(catalog.getLineModels("Zeus").size( ) == 3);
    }
}

TEST_CASE("Test if sortList() is working")
{
    SECTION("Sorting list")
    {
        Catalog catalog;

        catalog.addNewModel(4);     // Zeus 8031
        catalog.addNewModel(16);    // Ares 8023 15
        catalog.addNewModel(8);     // Cronos 6021 A
        catalog.addNewModel(1);     // Apolo 6031
        catalog.addNewModel(12);    // Ares 7021
        
        

        std::string expected_name_models[] = {
            "Apolo 6031", "Apolo 6031", "Zeus 8021","Zeus 8023","Zeus 8031","Zeus 8031","Cronos 6001 A",
            "Cronos 6003","Cronos 6021 A","Cronos 6021 L","Cronos 6021 L","Cronos 7023","Cronos 7023 2.5",
            "Cronos 7023 L","Ares 7021","Ares 7021","Ares 7023","Ares 7031","Ares 8023",
            "Ares 8023 15","Ares 8023 15","Ares 8023 200"
        };

        std::string lines_models[] = {"Apolo","Zeus","Cronos","Ares"};
        int index_name_models = 0;

        for (int index = 0; index < 4; index++)
        {
            for (const auto & meter : catalog.getLineModels(lines_models[index]))
            {
                CHECK(std::get<1>(meter) == expected_name_models[index_name_models]);
                index_name_models ++;
            }
        }
    }
}

TEST_CASE("Testing if getMeasurementsPhases() is working")
{
    SECTION("Get Measurements Phases")
    {
        Catalog catalog;

        catalog.addNewModel(4);     
        catalog.addNewModel(2);
        catalog.addNewModel(3);
        
        auto measurements = catalog.getMeasurementsPhases(18);
        REQUIRE(measurements.size() == 3);

        measurements = catalog.getMeasurementsPhases(19);
        REQUIRE(measurements.size() == 1);

        measurements = catalog.getMeasurementsPhases(20);
        REQUIRE(measurements.size() == 2);
        
    }
}
}