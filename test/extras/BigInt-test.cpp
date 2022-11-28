#include <catch2/catch.hpp>
#include <datos++/big_int.hpp>

using datospp::BigInt;

TEST_CASE("Operaciones BigInt", "[datospp::BigInt]") {
    SECTION("Se puede crear un BigInt"){
        BigInt a;
        REQUIRE(a == 0);
        BigInt b{1};
        REQUIRE(b == 1);
        BigInt c{0};
        REQUIRE(c == 0);
        BigInt d{-1};
        REQUIRE(d == -1);
        BigInt e{"123456789"};
        REQUIRE(e == 123456789);
        BigInt f{"-123456789"};
        REQUIRE(f == -123456789);
    }
}