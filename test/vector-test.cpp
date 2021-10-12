#include <catch2/catch.hpp>
#include <datos++/vector.hpp>

TEST_CASE("Operaciones Vector primitivos", "[datospp::Vector]") {

	SECTION("Se puede generar un vector vacio") {
		Vector<int> vec;
		REQUIRE(vec.empty());
	}
	SECTION("Se puede agregar un elemento al vector") {
		Vector<int> vec;
		vec.push_back(2);
		REQUIRE(!vec.empty());
		REQUIRE(vec.size() == 1);
		REQUIRE(vec.at(0) == 2);
		REQUIRE(vec[0] == 2);
	}

	SECTION("Se puede generar un vector con lista de inicializacion") {
		Vector<int> vec{1, 2, 3, 4, 5};
		REQUIRE(vec.size() == 5);
		for (size_t i = 0; i < vec.size(); i++) {
			REQUIRE(vec[i] == i + 1);
		}
	}
}