#include "core/Catalog.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Testing Catalog Functions", "[catalog]")
{
    SECTION("Add New Meter")
    {
        Catalog catalog;

        auto new_meter_attempt_1 = catalog.addNewModel(1);

        REQUIRE(new_meter_attempt_1 != nullptr);
        REQUIRE(new_meter_attempt_1->getID() == 18);
        REQUIRE(new_meter_attempt_1->getFullName() == "Apolo 6031");
        REQUIRE_FALSE(new_meter_attempt_1->getIsTemplate());

        auto new_meter_attempt_2 = catalog.addNewModel(36);
        REQUIRE(new_meter_attempt_2 == nullptr);

        auto new_meter_attempt_3 = catalog.addNewModel(-1);
        REQUIRE(new_meter_attempt_3 == nullptr);
    }
    SECTION("Remove Model")
    {
        Catalog catalog;

        auto remove_meter_attempt_1 = catalog.removeModel(1);
        REQUIRE_FALSE(remove_meter_attempt_1);

        auto new_meter_attempt_1 = catalog.addNewModel(1);
        REQUIRE(new_meter_attempt_1 != nullptr);

        auto remove_meter_attempt_2 = catalog.removeModel(18);
        REQUIRE(remove_meter_attempt_2);
    }
    SECTION("Get Mesuarements Phases")
    {
        Catalog catalog;
        auto get_mesuarements_phases_attempt_1 = catalog.getMeasurementsPhases(1);
        REQUIRE(get_mesuarements_phases_attempt_1[0] == 0);
        REQUIRE(get_mesuarements_phases_attempt_1[1] == 0);
        REQUIRE(get_mesuarements_phases_attempt_1[2] == 0);

        auto new_meter_apolo = catalog.addNewModel(1);
        auto get_mesuarements_phases_attempt_2 = catalog.getMeasurementsPhases(18);
        REQUIRE(get_mesuarements_phases_attempt_2[0] < 220);
        REQUIRE(get_mesuarements_phases_attempt_2[0] > 0);
        REQUIRE(get_mesuarements_phases_attempt_2[1] < 220);
        REQUIRE(get_mesuarements_phases_attempt_2[1] > 0);
        REQUIRE(get_mesuarements_phases_attempt_2[2] < 220);
        REQUIRE(get_mesuarements_phases_attempt_2[2] > 0);

        auto new_meter_zeus = catalog.addNewModel(2);
        auto get_mesuarements_phases_attempt_3 = catalog.getMeasurementsPhases(19);
        REQUIRE(get_mesuarements_phases_attempt_3[0] < 220);
        REQUIRE(get_mesuarements_phases_attempt_3[0] > 0);
        REQUIRE(get_mesuarements_phases_attempt_3[1] == 0);
        REQUIRE(get_mesuarements_phases_attempt_3[2] == 0);
    }
    SECTION("Get Lines")
    {
        Catalog catalog;
        auto lines_available = catalog.getLines();
        REQUIRE(lines_available.size() > 0);
        REQUIRE(lines_available.size() == 4);
    }
    SECTION("Get Line Models Created")
    {
        Catalog catalog;
        auto get_lines_models_created_attempt_1 = catalog.getLineModelsCreated("Pimenta");
        REQUIRE(get_lines_models_created_attempt_1.empty());

        auto get_lines_models_created_attempt_2 = catalog.getLineModelsCreated("Apolo");
        REQUIRE(get_lines_models_created_attempt_2.empty());

        auto new_meter = catalog.addNewModel(1);
        auto get_lines_models_created_attempt_3 = catalog.getLineModelsCreated("Apolo");
        REQUIRE(get_lines_models_created_attempt_3.size() == 1);
    }
    SECTION("Get Line Models Template")
    {
        Catalog catalog;
        auto get_lines_models_template_attempt_1 = catalog.getLineModelsTemplate("Pimenta");
        REQUIRE(get_lines_models_template_attempt_1.empty());

        auto get_lines_models_template_attempt_2 = catalog.getLineModelsTemplate("Apolo");
        REQUIRE(get_lines_models_template_attempt_2.size() == 1);

        auto get_lines_models_template_attempt_3 = catalog.getLineModelsTemplate("Zeus");
        REQUIRE(get_lines_models_template_attempt_3.size() == 3);
    }
    SECTION("Get Meter By ID")
    {
        Catalog catalog;
        auto get_meter_by_id_attempt_1 = catalog.getMeterByID(1);
        REQUIRE(get_meter_by_id_attempt_1 == nullptr);

        auto get_meter_by_id_attempt_2 = catalog.getMeterByID(-9);
        REQUIRE(get_meter_by_id_attempt_2 == nullptr);

        auto new_meter = catalog.addNewModel(1);
        auto get_meter_by_id_attempt_3 = catalog.getMeterByID(18);
        REQUIRE(get_meter_by_id_attempt_3 != nullptr);
        REQUIRE(get_meter_by_id_attempt_3->getID() == 18);
        REQUIRE(get_meter_by_id_attempt_3->getFullName() == "Apolo 6031");
    }
    SECTION("Get All Template Meters")
    {
        Catalog catalog;
        auto get_all_template_meters = catalog.getAllTemplateMeters();
        REQUIRE(get_all_template_meters.size() == 17);
    }
    SECTION("Get All Created Meters")
    {
        Catalog catalog;
        auto get_all_created_meters_attempt_1 = catalog.getAllCreatedMeters();
        REQUIRE(get_all_created_meters_attempt_1.empty());

        auto new_meter_1 = catalog.addNewModel(1);
        auto new_meter_2 = catalog.addNewModel(2);
        auto new_meter_3 = catalog.addNewModel(3);
        auto new_meter_4 = catalog.addNewModel(4);
        auto new_meter_5 = catalog.addNewModel(5);
        auto new_meter_6 = catalog.addNewModel(6);

        auto get_all_created_meters_attempt_2 = catalog.getAllCreatedMeters();
        REQUIRE(get_all_created_meters_attempt_2.size() == 6);
    }
}