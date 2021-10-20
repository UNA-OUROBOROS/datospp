#include <algorithm>
#include <catch2/catch.hpp>
#include <datos++/vector.hpp>

using datospp::Vector;

TEST_CASE("Operaciones Vector primitivos", "[datospp::Vector]") {

	SECTION("Se puede generar un vector") {
		SECTION("Vector vacío") {
			Vector<int> vec;
			REQUIRE(vec.empty());
			REQUIRE(vec.size() == 0);
		}
		SECTION("Se puede generar un vector con lista de inicializacion") {
			Vector<int> vec{1, 2, 3, 4, 5};
			SECTION("no es un vector vacio y su tamaño es el correcto") {
				REQUIRE(!vec.empty());
				REQUIRE(vec.size() == 5);
			}
			SECTION("Sus elementos concuerdan") {
				for (size_t i = 0; i < vec.size(); i++) {
					REQUIRE(vec[i] == i + 1);
				}
			}
			SECTION("Se puede mover un vector") {
				Vector<int> v1{1, 2, 3, 4, 5};
				Vector<int> vec{std::move(v1)};
				SECTION("el primer vector queda vacío") {
					REQUIRE(v1.size() == 0);
					REQUIRE(v1.empty());
				}
				SECTION("no es un vector vacio y su tamaño es el correcto") {
					REQUIRE(!vec.empty());
					REQUIRE(vec.size() == 5);
				}
				SECTION("Sus elementos concuerdan") {
					for (size_t i = 0; i < vec.size(); i++) {
						REQUIRE(vec[i] == i + 1);
					}
				}
			}
		}
		SECTION("Se puede mover un vector") {
			Vector<int> v1{1, 2, 3, 4, 5};
			Vector<int> vec{std::move(v1)};
			SECTION("el primer vector queda vacío") {
				REQUIRE(v1.size() == 0);
				REQUIRE(v1.empty());
			}
			SECTION("no es un vector vacio y su tamaño es el correcto") {
				REQUIRE(!vec.empty());
				REQUIRE(vec.size() == 5);
			}
			SECTION("Sus elementos concuerdan") {
				for (size_t i = 0; i < vec.size(); i++) {
					REQUIRE(vec[i] == i + 1);
				}
			}
		}
	}
	SECTION("agregar elementos a un vector") {
		Vector<int> vec;
		SECTION("Se puede insertar un elemento al vector") {
			size_t size = vec.size();
			vec.push_back(2);
			size_t newSize = vec.size();
			SECTION("Reporta la longitud correcta") {
				REQUIRE(!vec.empty());
				REQUIRE(size + 1 == newSize);
			}
			SECTION("Puede acceder a los elementos") {
				REQUIRE(vec.at(newSize - 1) == 2);
				REQUIRE(vec[newSize - 1] == 2);
			}
		}
		SECTION("Se puede mover un elemento al vector") {
			size_t size = vec.size();
			vec.push_back(std::move(2));
			size_t newSize = vec.size();
			SECTION("Reporta la longitud correcta") {
				REQUIRE(!vec.empty());
				REQUIRE(size + 1 == newSize);
			}
			SECTION("Puede acceder a los elementos") {
				REQUIRE(vec.at(newSize - 1) == 2);
				REQUIRE(vec[newSize - 1] == 2);
			}
		}
		SECTION("Se puede generar un elemento en el vector") {
			size_t size = vec.size();
			vec.emplace_back(2);
			size_t newSize = vec.size();
			SECTION("Reporta la longitud correcta") {
				REQUIRE(!vec.empty());
				REQUIRE(size + 1 == newSize);
			}
			SECTION("Puede acceder a los elementos") {
				REQUIRE(vec.at(newSize - 1) == 2);
				REQUIRE(vec[newSize - 1] == 2);
			}
		}
	}

	SECTION("Se pueden remover elementos a un vector") {
		SECTION("Se puede eliminar un elemento del vector vector") {
			Vector<int> vec;
			vec.push_back(2);
			size_t size = vec.size();
			vec.pop_back();
			size_t newSize = vec.size();
			SECTION("Reporta la longitud correcta") {
				REQUIRE(vec.empty());
				REQUIRE(size == newSize + 1);
			}
		}
		SECTION("Se puede vaciar un vector") {
			Vector<int> vec{1, 2, 3, 4, 5};
			vec.clear();
			SECTION("Reporta la longitud correcta") {
				REQUIRE(vec.empty());
				REQUIRE(vec.size() == 0);
			}
		}
	}
}