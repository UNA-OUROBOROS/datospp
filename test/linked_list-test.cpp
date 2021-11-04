#include <catch2/catch.hpp>
#include <datos++/linked_list.hpp>
#include <vcruntime.h>

using datospp::LinkedList;

TEST_CASE("Operaciones Lista Enlazada primitivos", "[datospp::LinkedList") {
	SECTION("se puede generar una lista") {
		SECTION("Se puede generar una lista vacía") {
			LinkedList<int> lista;
			REQUIRE(lista.empty());
			REQUIRE(lista.size() == 0);
		}
		SECTION("Se puede generar una lista con lista de inicializacion") {
			LinkedList<int> lista{1, 2, 3, 4, 5};
			SECTION("no es una lista vacia y su tamaño es el correcto") {
				REQUIRE_FALSE(lista.empty());
				REQUIRE(lista.size() == 5);
			}
			SECTION("Sus elementos concuerdan") {
				REQUIRE(lista.front() == 1);
				REQUIRE(lista.back() == 5);
				// recorrer la lista
				for (size_t i = 0; i < 5; i++) {
					REQUIRE(lista[i] == i + 1);
				}
			}
			SECTION("Se puede mover una lista a otra lista") {
				LinkedList<int> lista2;
				lista2 = lista;
				SECTION("la primera lista esta vacía") {
					REQUIRE(lista.size() == 0);
					REQUIRE(lista.empty());
				}
				SECTION("no es una lista vacia y su tamaño es el correcto") {
					REQUIRE(!lista2.empty());
					REQUIRE(lista2.size() == 5);
				}
				SECTION("Sus elementos concuerdan") {
					for (size_t i = 0; i < lista.size(); i++) {
						REQUIRE(lista2[i] == i + 1);
					}
				}
			}
		}
		SECTION("se puede copiar una lista") {
			LinkedList<int> lista{1, 2, 3, 4, 5};
			LinkedList<int> lista2{lista};
			SECTION("no es una lista vacia y su tamaño es el correcto") {
				REQUIRE(!lista2.empty());
				REQUIRE(lista2.size() == 5);
			}
		}
	}
	SECTION("agregar elementos a una lista") {
		LinkedList<int> lista;
		SECTION("se puede insertar un elemento a la lista") {
			size_t size = lista.size();
			lista.push_back(2);
			size_t newSize = lista.size();
			SECTION("reporta la longitud correcta") {
				REQUIRE(!lista.empty());
				REQUIRE(newSize == size + 1);
			}
			SECTION("Puede acceder a los elementos") {
				REQUIRE(lista.at(newSize - 1) == 2);
				REQUIRE(lista[newSize - 1] == 2);
			}
		}
		SECTION("Se puede mover un elemento a la lista") {
			size_t size = lista.size();
			lista.push_front(std::move(2));
			size_t newSize = lista.size();
			SECTION("reporta la longitud correcta") {
				REQUIRE(!lista.empty());
				REQUIRE(newSize == size + 1);
			}
			SECTION("Puede acceder a los elementos") {
				REQUIRE(lista.at(newSize - 1) == 2);
				REQUIRE(lista[newSize - 1] == 2);
			}
		}
        SECTION("Se puede generar un elemento en la lista"){
            size_t size = lista.size();
            lista.emplace_back(2);
            size_t newSize = lista.size();
            SECTION("reporta la longitud correcta") {
                REQUIRE(!lista.empty());
                REQUIRE(newSize == size + 1);
            }
            SECTION("Puede acceder a los elementos") {
                REQUIRE(lista.at(newSize - 1) == 2);
                REQUIRE(lista[newSize - 1] == 2);
            }
        }
	}
    SECTION("Se pueden remover elementos de una lista"){
        SECTION("Se puede remover un elemento de la lista"){
            LinkedList<int> lista{1, 2, 3, 4, 5};
            size_t size = lista.size();
            SECTION("se pueden eliminar elementos del final"){
                lista.pop_back();
                size_t newSize = lista.size();
                SECTION("reporta la longitud correcta") {
                    REQUIRE(!lista.empty());
                    REQUIRE(newSize == size - 1);
                }
                SECTION("Puede acceder a los elementos") {
                    REQUIRE(lista.at(newSize - 1) == 4);
                    REQUIRE(lista[newSize - 1] == 4);
                }
            }
            SECTION("se pueden eliminar elementos del inicio"){
                lista.pop_front();
                size_t newSize = lista.size();
                SECTION("reporta la longitud correcta") {
                    REQUIRE(!lista.empty());
                    REQUIRE(newSize == size - 1);
                }
                SECTION("Puede acceder a los elementos") {
                    REQUIRE(lista.at(newSize - 1) == 2);
                    REQUIRE(lista[newSize - 1] == 2);
                }
            }
            SECTION("se pueden eliminar elementos de una posicion"){
                lista.erase(2);
                size_t newSize = lista.size();
                SECTION("reporta la longitud correcta") {
                    REQUIRE(!lista.empty());
                    REQUIRE(newSize == size - 1);
                }
                SECTION("Puede acceder a los elementos") {
                    REQUIRE(lista.at(newSize - 1) == 4);
                    REQUIRE(lista[newSize - 1] == 4);
                }
            }
            SECTION("se puede vaciar una lista"){
                lista.clear();
                size_t newSize = lista.size();
                SECTION("reporta la longitud correcta") {
                    REQUIRE(lista.empty());
                    REQUIRE(newSize == 0);
                }
            }
            
        }
    }
}