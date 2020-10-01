#include <iostream>
#include "estructuras.hpp"


using std::cout;

int main(int, char **) {
	// problema 1: cola de prioridades con camisas, primero van las menores
	{
		colaPrioridad<int> camisas(true);
		camisas.insertar(3);
		camisas.insertar(2);
		camisas.insertar(1);

		// en la lista con prioridad se requiere el acceso aleatorio tambien
		for (size_t i = 0; i < camisas.size(); i++) {
			cout << camisas.at(i) << "\n";
		}
	}

	// problema 2: ordenes, una cola LIFO
	// suponiendo que se ingresan segun el tiempo
	cout << "---------------\n";
	{
		cola<int> ordenes;
		ordenes.insertar(1);
		ordenes.insertar(22);
		ordenes.insertar(333);

		// solo deberiamos poder acceder en orden, y luego expulsar la orden
		while (!ordenes.vacio()) {
			cout << ordenes.recuperar() << "\n";
		}
	}
	// problema 3: platos, el mismo problema que sucede con las ordenes
	cout << "---------------\n";
	{
		cola<int> platos;
		platos.insertar(1);
		platos.insertar(22);
		platos.insertar(333);

		while (!platos.vacio()) {
			cout << platos.recuperar() << "\n";
		}
	}
	// problema 4, banco, cola con prioridades
	cout << "---------------\n";
	{
		colaPrioridad<int> clientes;
		clientes.insertar(2);
		clientes.insertar(3);
		clientes.insertar(1);

		while (!clientes.vacio()) {
			cout << clientes.recuperar() << "\n";
		}
	}
	// problema 5: araña, con el patron compuesto basta
	cout << "---------------\n";
	{
		dummy d1("d1", "{informacion de d1}");
		dummy d2("d2", "{informacion de d2}", &d1);
		dummy d3("d3", "{informacion de d3}", &d2);

		std::cout << "d1 dice:\n" << d1.toString() << "\n";
		std::cout << "d2 dice:\n" << d2.toString() << "\n";
		std::cout << "d3 dice:\n" << d3.toString() << "\n";
	}
	std::cin.ignore();
}
