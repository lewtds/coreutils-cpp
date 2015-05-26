#include <cstdlib>
#include "catch.hpp"
#include "utils.hpp"

TEST_CASE("Use stdin if no input file", "[cat]") {
    REQUIRE(call("echo a | ./cat", NULL) == "a\n");
}

TEST_CASE("Empty input gives empty output", "[cat]") {
    REQUIRE(call("echo -n | ./cat", NULL) == "");
}

TEST_CASE("Cat shows file content", "[cat]") {
    system("echo -n this > this.txt");
    system("echo -n is > is.txt");
    system("echo -n cool > cool.txt");

    SECTION("One file") {
        REQUIRE(call("./cat cool.txt", NULL) == "cool");
    }
    
    SECTION("Multiple files") {
        REQUIRE(call("./cat this.txt is.txt cool.txt", NULL) == "thisiscool");
    }
    
    system("rm -rf this.txt is.txt cool.txt");
}

TEST_CASE("Panic if file cannot be accessed", "[cat]") {
    int result;
    call("./cat definitely_nonexistant.txt", &result);
    REQUIRE(result != 0);   // FIXME Should be 1
}
