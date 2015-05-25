#include "utils.hpp"
#include "catch.hpp"

TEST_CASE("Use stdin if no input file", "[cat]") {
    REQUIRE(call("echo a | ./cat", NULL) == "a\n");
}
