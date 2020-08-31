#include <lista_doble.hpp>
#include <stdexcept>
#include <tuple>

listaDoble::listaDoble() {}
void listaDoble::insertar(int n, size_t pos) {
	if (pos == 0) {
		insertarInicio(n);
	} else if (pos <= len) {
		nodo *anterior = getNodo(pos - 1);
		nodo *nuevo = new nodo(n, anterior, anterior->getSiguiente());
		anterior->getSiguiente()->setSiguiente(nuevo);
		anterior->setSiguiente(nuevo);
		len++;
	}
}
void listaDoble::insertarInicio(int n) {
	inicio = new nodo(n, inicio);
	len++;
}

void listaDoble::insertarFinal(int n) {
	if (n == 0) {
		insertarInicio(n);
	} else {
		ultimo->setSiguiente(new nodo(n, nullptr, ultimo));
		ultimo = ultimo->getSiguiente();
		// getNodo(len - 1)->setSiguiente(new nodo(n));
		len++;
	}
}
bool listaDoble::eliminar(size_t pos) {
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
bool listaDoble::eliminarInicio() {
	if (inicio) {
		nodo *siguiente = inicio->getSiguiente();
		siguiente->setAnterior(nullptr);
		delete inicio;
		inicio = siguiente;
		len--;
		return true;
	}
	return false;
}
bool listaDoble::eliminarFinal() {
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
int listaDoble::getValor(size_t pos) {
	nodo *n = getNodo(pos);
	if (n != nullptr) {
		return n->getValor();
	}
	throw std::out_of_range("posicion fuera de los limites");
}
size_t listaDoble::size() { return len; }

listaDoble::nodo *listaDoble::getNodo(size_t pos) {
	// c++ 17, pre c++17 puede declarar uno de los 2 afuera
	bool reversa = pos > len / 2;
	for (auto [n, i] = std::tuple{inicio, reversa ? len - 1 : 0}; n != nullptr;
	     reversa ? i-- : i++) {
		if (i == pos) {
			return n;
		}
		n = reversa ? n->getAnterior() : n->getSiguiente();
	}
	return nullptr;
}

listaDoble::~listaDoble() {
	while (len){
		eliminarInicio();
	}
}