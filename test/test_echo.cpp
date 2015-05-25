#include <iostream>
#include "catch.hpp"
#include "utils.hpp"


TEST_CASE("Echo prints out the input with a newline", "[echo]") {
    REQUIRE(call("./echo", NULL) == "\n");
    REQUIRE(call("./echo cool", NULL) == "cool\n");
    REQUIRE(call("./echo cool yeah", NULL) == "cool yeah\n");
    REQUIRE(call("./echo cool    yeah", NULL) == "cool yeah\n");
}

TEST_CASE("Echo has a help page", "[echo]") {
    REQUIRE(call("./echo -h", NULL) != "-h\n");
}

TEST_CASE("Echo -n doesn't print newline", "[echo]") {
    REQUIRE(call("./echo -n", NULL) == "");
    REQUIRE(call("./echo -n cool", NULL) == "cool");
}

TEST_CASE("-s, Do not separate arguments with spaces", "[echo]") {
    REQUIRE(call("./echo -s a b", NULL) == "ab\n");
}

TEST_CASE("-e, Enable interpretation of backslash escapes", "[echo]") {
    SECTION("\\\\ backslash") {
        REQUIRE(call("./echo -e '\\\\'", NULL) == "\\\n");
    }
    
    SECTION("\\a alert") {
        REQUIRE(call("./echo -e '\\a'", NULL) == "\a\n");
    }
    
    SECTION("\\b backspace") {
        REQUIRE(call("./echo -e '\\b'", NULL) == "\b\n");
    }
    
    SECTION("\\c produce no further output") {
        REQUIRE(call("./echo -e 'a\\cnthatenhatne'", NULL) == "a");
    }
}
