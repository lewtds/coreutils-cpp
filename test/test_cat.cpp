#include "catch.hpp"
#include "utils.hpp"

TEST_CASE("Use stdin if no input file", "[cat]") {
    REQUIRE(call("echo a | ./cat", NULL) == "a\n");
}

TEST_CASE("Empty input gives empty output", "[cat]") {
    REQUIRE(call("echo -n | ./cat", NULL) == "");
}
