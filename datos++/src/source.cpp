#include <datos++/vector.hpp>
#include <iostream>

int main(int, char **) {
	datospp::vector<int> v{1, 2, 3, 4, 5};
	v.emplace_back(6);
	for (auto &val : v) {
		std::cout << val << "\n";
	}
	v.erase(v.size() - 1);
	std::cout << "copiado el elemento\n";
	datospp::vector<int> v2(v);
	for (auto &val : v2) {
		std::cout << val << "\n";
	}
	v2.erase(v2.size() - 1);
	datospp::vector<int> v3(std::move(v2));
	std::cout << "movido el elemento\n";
	for (auto &val : v3) {
		std::cout << val << "\n";
	}
	size_t v2_size;

	// valido pero da una alerta si no llamamos a reinicializar
	// v2_size = v2.size();
	// si vaciamos el objeto v2 esta alerta no se muestra
	// sin embargo es un falso positivo ya que v2 es reinicado a un vector vacio
	v2 = {};
	v2_size = v2.size();

	std::cout << "longitud de v2: " << v2_size << std::endl;
	v3.resize(2);
	v3.erase(0);
	v = std::move(v3);
	// lo mismo pasa con v3
	v3 = {};
	size_t v3_size = v3.size();

	std::cout << "el resto esta en v1, len(v3):" << v3_size << "\n";
	for (auto &val : v) {
		std::cout << val << "\n";
	}

	std::cout << "fin del recorrido!\n";
	std::cin.ignore();
}
