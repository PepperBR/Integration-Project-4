#include "meters/Phase/PhasesMeter.h"

#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Testing Phase Meter Functions", "[phaseMeter]")
{
    PhasesMeter phaseMeter;

    SECTION("Get Phase Values")
    {
        auto phaseAValues = phaseMeter.getPhaseValues(Phase::PhaseA);
        REQUIRE(phaseAValues[0] < 220);
        REQUIRE(phaseAValues[0] > 0);
        REQUIRE(phaseAValues[1] == 0);
        REQUIRE(phaseAValues[2] == 0);

        auto phaseBValues = phaseMeter.getPhaseValues(Phase::PhaseB);
        REQUIRE(phaseBValues[0] < 220);
        REQUIRE(phaseBValues[0] > 0);
        REQUIRE(phaseBValues[1] < 220);
        REQUIRE(phaseBValues[1] > 0);
        REQUIRE(phaseBValues[2] == 0);

        auto phaseCValues = phaseMeter.getPhaseValues(Phase::PhaseC);
        REQUIRE(phaseCValues[0] < 220);
        REQUIRE(phaseCValues[0] > 0);
        REQUIRE(phaseCValues[1] < 220);
        REQUIRE(phaseCValues[1] > 0);
        REQUIRE(phaseCValues[2] < 220);
        REQUIRE(phaseCValues[2] > 0);
    }
}