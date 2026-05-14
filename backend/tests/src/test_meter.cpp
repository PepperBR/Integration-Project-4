#include "meters/Ares/Ares7021.h"
#include "meters/Ares/Ares7023.h"
#include "meters/Ares/Ares7031.h"
#include "meters/Ares/Ares8023.h"
#include "meters/Ares/Ares8023_15.h"
#include "meters/Ares/Ares8023_200.h"

#include "meters/Cronos/Cronos6001_A.h"
#include "meters/Cronos/Cronos6003.h"
#include "meters/Cronos/Cronos6021_A.h"
#include "meters/Cronos/Cronos6021_L.h"
#include "meters/Cronos/Cronos7023_2_5.h"

#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Testing Meter Functions", "[meter]")
{
    Cronos7023_2_5 cronos7023_2_5;
    Cronos6021_L cronos6021_L;
    Cronos6021_A cronos6021_A;
    Cronos6003 cronos6003;
    Cronos6001_A cronos6001_A;

    Ares7021 ares7021;
    Ares7023 ares7023;
    Ares7031 ares7031;
    Ares8023 ares8023;
    Ares8023_15 ares8023_15;
    Ares8023_200 ares8023_200;

    SECTION("Get ID")
    {
        REQUIRE(cronos7023_2_5.getID() == 7);
        REQUIRE(cronos6021_L.getID() == 8);
        REQUIRE(cronos6021_A.getID() == 9);
        REQUIRE(cronos6003.getID() == 10);
        REQUIRE(cronos6001_A.getID() == 11);

        REQUIRE(ares7021.getID() == 12);
        REQUIRE(ares7023.getID() == 14);
        REQUIRE(ares7031.getID() == 15);
        REQUIRE(ares8023.getID() == 13);
        REQUIRE(ares8023_15.getID() == 16);
        REQUIRE(ares8023_200.getID() == 17);
    }
    SECTION("Get Name Line")
    {
        REQUIRE(cronos7023_2_5.getNameLine() == "Cronos");
        REQUIRE(cronos6021_L.getNameLine() == "Cronos");
        REQUIRE(cronos6021_A.getNameLine() == "Cronos");
        REQUIRE(cronos6003.getNameLine() == "Cronos");
        REQUIRE(cronos6001_A.getNameLine() == "Cronos");

        REQUIRE(ares7021.getNameLine() == "Ares");
        REQUIRE(ares7023.getNameLine() == "Ares");
        REQUIRE(ares7031.getNameLine() == "Ares");
        REQUIRE(ares8023.getNameLine() == "Ares");
        REQUIRE(ares8023_15.getNameLine() == "Ares");
        REQUIRE(ares8023_200.getNameLine() == "Ares");
    }
    SECTION("Get Name Model")
    {
        REQUIRE(cronos7023_2_5.getNameModel() == "7023 2.5");
        REQUIRE(cronos6021_L.getNameModel() == "6021 L");
        REQUIRE(cronos6021_A.getNameModel() == "6021 A");
        REQUIRE(cronos6003.getNameModel() == "6003");
        REQUIRE(cronos6001_A.getNameModel() == "6001 A");

        REQUIRE(ares7021.getNameModel() == "7021");
        REQUIRE(ares7023.getNameModel() == "7023");
        REQUIRE(ares7031.getNameModel() == "7031");
        REQUIRE(ares8023.getNameModel() == "8023");
        REQUIRE(ares8023_15.getNameModel() == "8023 15");
        REQUIRE(ares8023_200.getNameModel() == "8023 200");
    }
    SECTION("Get Full Name")
    {
        REQUIRE(cronos7023_2_5.getFullName() == "Cronos 7023 2.5");
        REQUIRE(cronos6021_L.getFullName() == "Cronos 6021 L");
        REQUIRE(cronos6021_A.getFullName() == "Cronos 6021 A");
        REQUIRE(cronos6003.getFullName() == "Cronos 6003");
        REQUIRE(cronos6001_A.getFullName() == "Cronos 6001 A");

        REQUIRE(ares7021.getFullName() == "Ares 7021");
        REQUIRE(ares7023.getFullName() == "Ares 7023");
        REQUIRE(ares7031.getFullName() == "Ares 7031");
        REQUIRE(ares8023.getFullName() == "Ares 8023");
        REQUIRE(ares8023_15.getFullName() == "Ares 8023 15");
        REQUIRE(ares8023_200.getFullName() == "Ares 8023 200");
    }
    SECTION("Get Is Template")
    {
        REQUIRE(cronos7023_2_5.getIsTemplate() == true);
        REQUIRE(cronos6021_L.getIsTemplate() == true);
        REQUIRE(cronos6021_A.getIsTemplate() == true);
        REQUIRE(cronos6003.getIsTemplate() == true);
        REQUIRE(cronos6001_A.getIsTemplate() == true);

        REQUIRE(ares7021.getIsTemplate() == true);
        REQUIRE(ares7023.getIsTemplate() == true);
        REQUIRE(ares7031.getIsTemplate() == true);
        REQUIRE(ares8023.getIsTemplate() == true);
        REQUIRE(ares8023_15.getIsTemplate() == true);
        REQUIRE(ares8023_200.getIsTemplate() == true);
    }
    SECTION("Get Number of Phases")
    {
        REQUIRE(cronos7023_2_5.getNumberOfPhases() == Phase::PhaseB);
        REQUIRE(cronos6021_L.getNumberOfPhases() == Phase::PhaseC);
        REQUIRE(cronos6021_A.getNumberOfPhases() == Phase::PhaseA);
        REQUIRE(cronos6003.getNumberOfPhases() == Phase::PhaseB);
        REQUIRE(cronos6001_A.getNumberOfPhases() == Phase::PhaseC);

        REQUIRE(ares7021.getNumberOfPhases() == Phase::PhaseA);
        REQUIRE(ares7023.getNumberOfPhases() == Phase::PhaseB);
        REQUIRE(ares7031.getNumberOfPhases() == Phase::PhaseC);
        REQUIRE(ares8023.getNumberOfPhases() == Phase::PhaseC);
        REQUIRE(ares8023_15.getNumberOfPhases() == Phase::PhaseA);
        REQUIRE(ares8023_200.getNumberOfPhases() == Phase::PhaseB);
    }

    SECTION("Get Phase Values")
    {
        auto values_cronos7023_2_5 = cronos7023_2_5.getPhaseValues(cronos7023_2_5.getNumberOfPhases());
        REQUIRE(values_cronos7023_2_5[0] < 220);
        REQUIRE(values_cronos7023_2_5[0] > 0);
        REQUIRE(values_cronos7023_2_5[1] < 220);
        REQUIRE(values_cronos7023_2_5[1] > 0);
        REQUIRE(values_cronos7023_2_5[2] == 0);

        auto values_cronos6021_L = cronos6021_L.getPhaseValues(cronos6021_L.getNumberOfPhases());
        REQUIRE(values_cronos6021_L[0] < 220);
        REQUIRE(values_cronos6021_L[0] > 0);
        REQUIRE(values_cronos6021_L[1] < 220);
        REQUIRE(values_cronos6021_L[1] > 0);
        REQUIRE(values_cronos6021_L[2] < 220);
        REQUIRE(values_cronos6021_L[2] > 0);

        auto values_cronos6021_A = cronos6021_A.getPhaseValues(cronos6021_A.getNumberOfPhases());
        REQUIRE(values_cronos6021_A[0] < 220);
        REQUIRE(values_cronos6021_A[0] > 0);
        REQUIRE(values_cronos6021_A[1] == 0);
        REQUIRE(values_cronos6021_A[2] == 0);

        auto values_cronos6003 = cronos6003.getPhaseValues(cronos6003.getNumberOfPhases());
        REQUIRE(values_cronos6003[0] < 220);
        REQUIRE(values_cronos6003[0] > 0);
        REQUIRE(values_cronos6003[1] < 220);
        REQUIRE(values_cronos6003[1] > 0);
        REQUIRE(values_cronos6003[2] == 0);

        auto values_cronos6001_A = cronos6001_A.getPhaseValues(cronos6001_A.getNumberOfPhases());
        REQUIRE(values_cronos6001_A[0] < 220);
        REQUIRE(values_cronos6001_A[0] > 0);
        REQUIRE(values_cronos6001_A[1] < 220);
        REQUIRE(values_cronos6001_A[1] > 0);
        REQUIRE(values_cronos6001_A[2] < 220);
        REQUIRE(values_cronos6001_A[2] > 0);

        auto values_ares7021 = ares7021.getPhaseValues(ares7021.getNumberOfPhases());
        REQUIRE(values_ares7021[0] < 220);
        REQUIRE(values_ares7021[0] > 0);
        REQUIRE(values_ares7021[1] == 0);
        REQUIRE(values_ares7021[2] == 0);

        auto values_ares7023 = ares7023.getPhaseValues(ares7023.getNumberOfPhases());
        REQUIRE(values_ares7023[0] < 220);
        REQUIRE(values_ares7023[0] > 0);
        REQUIRE(values_ares7023[1] < 220);
        REQUIRE(values_ares7023[1] > 0);
        REQUIRE(values_ares7023[2] == 0);

        auto values_ares7031 = ares7031.getPhaseValues(ares7031.getNumberOfPhases());
        REQUIRE(values_ares7031[0] < 220);
        REQUIRE(values_ares7031[0] > 0);
        REQUIRE(values_ares7031[1] < 220);
        REQUIRE(values_ares7031[1] > 0);
        REQUIRE(values_ares7031[2] < 220);
        REQUIRE(values_ares7031[2] > 0);

        auto values_ares8023 = ares8023.getPhaseValues(ares8023.getNumberOfPhases());
        REQUIRE(values_ares8023[0] < 220);
        REQUIRE(values_ares8023[0] > 0);
        REQUIRE(values_ares8023[1] < 220);
        REQUIRE(values_ares8023[1] > 0);
        REQUIRE(values_ares8023[2] < 220);
        REQUIRE(values_ares8023[2] > 0);

        auto values_ares8023_15 = ares8023_15.getPhaseValues(ares8023_15.getNumberOfPhases());
        REQUIRE(values_ares8023_15[0] < 220);
        REQUIRE(values_ares8023_15[0] > 0);
        REQUIRE(values_ares8023_15[1] == 0);
        REQUIRE(values_ares8023_15[2] == 0);

        auto values_ares8023_200 = ares8023_200.getPhaseValues(ares8023_200.getNumberOfPhases());
        REQUIRE(values_ares8023_200[0] < 220);
        REQUIRE(values_ares8023_200[0] > 0);
        REQUIRE(values_ares8023_200[1] < 220);
        REQUIRE(values_ares8023_200[1] > 0);
        REQUIRE(values_ares8023_200[2] == 0);
    }

    SECTION("Get Clone of Meter")
    {
        auto clone_cronos7023_2_5 = cronos7023_2_5.cloneMeter(18);
        REQUIRE(clone_cronos7023_2_5->getID() == 18);
        REQUIRE(clone_cronos7023_2_5->getNameLine() == "Cronos");
        REQUIRE(clone_cronos7023_2_5->getNameModel() == "7023 2.5");
        REQUIRE(clone_cronos7023_2_5->getNumberOfPhases() == Phase::PhaseB);
        REQUIRE(clone_cronos7023_2_5->getIsTemplate() == false);

        auto clone_cronos6021_L = cronos6021_L.cloneMeter(19);
        REQUIRE(clone_cronos6021_L->getID() == 19);
        REQUIRE(clone_cronos6021_L->getNameLine() == "Cronos");
        REQUIRE(clone_cronos6021_L->getNameModel() == "6021 L");
        REQUIRE(clone_cronos6021_L->getNumberOfPhases() == Phase::PhaseC);
        REQUIRE(clone_cronos6021_L->getIsTemplate() == false);

        auto clone_cronos6021_A = cronos6021_A.cloneMeter(20);
        REQUIRE(clone_cronos6021_A->getID() == 20);
        REQUIRE(clone_cronos6021_A->getNameLine() == "Cronos");
        REQUIRE(clone_cronos6021_A->getNameModel() == "6021 A");
        REQUIRE(clone_cronos6021_A->getNumberOfPhases() == Phase::PhaseA);
        REQUIRE(clone_cronos6021_A->getIsTemplate() == false);

        auto clone_cronos6003 = cronos6003.cloneMeter(21);
        REQUIRE(clone_cronos6003->getID() == 21);
        REQUIRE(clone_cronos6003->getNameLine() == "Cronos");
        REQUIRE(clone_cronos6003->getNameModel() == "6003");
        REQUIRE(clone_cronos6003->getNumberOfPhases() == Phase::PhaseB);
        REQUIRE(clone_cronos6003->getIsTemplate() == false);

        auto clone_cronos6001_A = cronos6001_A.cloneMeter(22);
        REQUIRE(clone_cronos6001_A->getID() == 22);
        REQUIRE(clone_cronos6001_A->getNameLine() == "Cronos");
        REQUIRE(clone_cronos6001_A->getNameModel() == "6001 A");
        REQUIRE(clone_cronos6001_A->getNumberOfPhases() == Phase::PhaseC);
        REQUIRE(clone_cronos6001_A->getIsTemplate() == false);

        auto clone_ares7021 = ares7021.cloneMeter(23);
        REQUIRE(clone_ares7021->getID() == 23);
        REQUIRE(clone_ares7021->getNameLine() == "Ares");
        REQUIRE(clone_ares7021->getNameModel() == "7021");
        REQUIRE(clone_ares7021->getNumberOfPhases() == Phase::PhaseA);
        REQUIRE(clone_ares7021->getIsTemplate() == false);

        auto clone_ares7023 = ares7023.cloneMeter(24);
        REQUIRE(clone_ares7023->getID() == 24);
        REQUIRE(clone_ares7023->getNameLine() == "Ares");
        REQUIRE(clone_ares7023->getNameModel() == "7023");
        REQUIRE(clone_ares7023->getNumberOfPhases() == Phase::PhaseB);
        REQUIRE(clone_ares7023->getIsTemplate() == false);

        auto clone_ares7031 = ares7031.cloneMeter(25);
        REQUIRE(clone_ares7031->getID() == 25);
        REQUIRE(clone_ares7031->getNameLine() == "Ares");
        REQUIRE(clone_ares7031->getNameModel() == "7031");
        REQUIRE(clone_ares7031->getNumberOfPhases() == Phase::PhaseC);
        REQUIRE(clone_ares7031->getIsTemplate() == false);

        auto clone_ares8023 = ares8023.cloneMeter(26);
        REQUIRE(clone_ares8023->getID() == 26);
        REQUIRE(clone_ares8023->getNameLine() == "Ares");
        REQUIRE(clone_ares8023->getNameModel() == "8023");
        REQUIRE(clone_ares8023->getNumberOfPhases() == Phase::PhaseC);
        REQUIRE(clone_ares8023->getIsTemplate() == false);

        auto clone_ares8023_15 = ares8023_15.cloneMeter(27);
        REQUIRE(clone_ares8023_15->getID() == 27);
        REQUIRE(clone_ares8023_15->getNameLine() == "Ares");
        REQUIRE(clone_ares8023_15->getNameModel() == "8023 15");
        REQUIRE(clone_ares8023_15->getNumberOfPhases() == Phase::PhaseA);
        REQUIRE(clone_ares8023_15->getIsTemplate() == false);

        auto clone_ares8023_200 = ares8023_200.cloneMeter(28);
        REQUIRE(clone_ares8023_200->getID() == 28);
        REQUIRE(clone_ares8023_200->getNameLine() == "Ares");
        REQUIRE(clone_ares8023_200->getNameModel() == "8023 200");
        REQUIRE(clone_ares8023_200->getNumberOfPhases() == Phase::PhaseB);
        REQUIRE(clone_ares8023_200->getIsTemplate() == false);
    }
}
