#include <iostream>
#include <Vector.hpp>
using std::cout;

int main(int, char **) {
	Vector<int> v = {1, 2, 3, 4, 5};
	v.emplace_back(6);
	for (auto &val : v) {
		cout << val << "\n";
	}
	v.erase(v.size() - 1);
	std::cout << "copiado el elemento\n";
	Vector<int> v2 = v;
	for (auto &val : v2) {
		cout << val << "\n";
	}
	v2.erase(v2.size() - 1);
	Vector<int> v3 = std::move(v2);
	std::cout << "movido el elemento\n";
	for (auto &val : v3) {
		cout << val << "\n";
	}
	std::cout << "longitud de v2: " << v2.size() << std::endl;
	v3.resize(2);
	v3.erase(0);
	v = std::move(v3);
	std::cout << "el resto esta en v1, len(v3):" << v3.size() << "\n";
	for (auto &val : v) {
		cout << val << "\n";
	}

	std::cout << "fin del recorrido!\n";
	std::cin.ignore();
}
