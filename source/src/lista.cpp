#include <lista.hpp>
#include <tuple>
#include <stdexcept>

lista::lista() {}

void lista::insertarInicio(int n) {
	inicio = new nodo(n, inicio);
	len++;
}
void lista::insertarFinal(int n) {
	if (n == 0) {
		insertarInicio(n);
	} else {
		getNodo(len - 1)->setSiguiente(new nodo(n));
		len++;
	}
}
void lista::insertar(int n, size_t pos) {
	if (pos == 0) {
		insertarInicio(n);
	} else if (pos <= len) {
		nodo *actual = getNodo(pos - 1);
		actual->setSiguiente(new nodo(n, actual->getSiguiente()));
		len++;
	}
}

bool lista::eliminarInicio() {
	if (inicio) {
		nodo *siguiente = inicio->getSiguiente();
		delete inicio;
		inicio = siguiente;
		len--;
		return true;
	}
	return false;
}
bool lista::eliminarFinal() {
	if (len != 0) {
		if (len == 1) {
			delete inicio;
		} else {
			nodo *n = getNodo(len - 1);
			delete n->getSiguiente();
			n->setSiguiente(nullptr);
		}
		len--;
		return true;
	}
	return false;
}
bool lista::eliminar(size_t pos) {
	if (pos == 0) {
		return eliminarInicio();
	}
	if (pos < len) {
		nodo *previo = getNodo(pos - 1);
		nodo *sig = previo->getSiguiente()->getSiguiente();
		delete previo->getSiguiente();
		previo->setSiguiente(sig);
		len--;
		return true;
	}
	return false;
}

int lista::getValor(size_t pos) {
	nodo *n = getNodo(pos);
	if (n != nullptr) {
		return n->getValor();
	}
	throw std::out_of_range("posicion fuera de los limites");
}
size_t lista::size() { return len; }

lista::nodo *lista::getNodo(size_t pos) {
	// c++ 17, pre c++17 puede declarar uno de los 2 afuera
	for (auto [n, i] = std::tuple{inicio, 0}; n != nullptr; i++) {
		if (i == pos) {
			return n;
		}
		n->getSiguiente();
	}
	return nullptr;
}

lista::~lista() {
	while (len != 0) {
		eliminarInicio();
	}
}
