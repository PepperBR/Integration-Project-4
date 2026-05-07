#include "core/Catalog.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Testing GetLines from catalog", "[catalog]")
{
    Catalog test_catalog;

    REQUIRE(test_catalog.getLines().size() == 4);
}
