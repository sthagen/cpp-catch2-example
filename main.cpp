#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <tribonacci.hpp>

TEST_CASE("tribonacci recursive values below 1000") {
    // 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, … (sequence A000073 in the OEIS)
    CHECK(tribonacci(0) == 0);
    CHECK(tribonacci(1) == 0);
    CHECK(tribonacci(2) == 1);
    CHECK(tribonacci(3) == 1);
    CHECK(tribonacci(4) == 2);
    CHECK(tribonacci(5) == 4);
    CHECK(tribonacci(6) == 7);
    CHECK(tribonacci(7) == 13);
    CHECK(tribonacci(8) == 24);
    CHECK(tribonacci(9) == 44);
    CHECK(tribonacci(10) == 81);
    CHECK(tribonacci(11) == 149);
    CHECK(tribonacci(12) == 274);
    REQUIRE(tribonacci(13) == 504);
    REQUIRE(tribonacci(14) == 927);
}

TEST_CASE("tribonacci iterative equals recursive implementation for values below 1000") {
    for (unsigned i=0; i<15; ++i) {
        INFO("The argument is " << i);
        CHECK(tribonacci(i) == tribonacci_iter(i));
    }
}
