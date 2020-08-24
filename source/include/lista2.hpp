#pragma once
#include <cstddef>
#include <stdexcept>
#include <tuple>

// este codigo tambien esta disponible en el siguiente gist

class lista {
  private:
	class nodo {
		int valor;
		nodo *siguiente = nullptr;

	  public:
		nodo(int valor, nodo *siguiente = nullptr)
		    : valor(valor), siguiente(siguiente) {}
		int getValor() { return valor; }
		void setSiguiente(nodo *n) { siguiente = n; }
		nodo *getSiguiente() { return siguiente; }
	};
	nodo *inicio = nullptr;
	size_t len = 0;

  public:
	lista::lista() {}
	void lista::insertar(int n, size_t pos = 0) {
		if (pos == 0) {
			insertarInicio(n);
		} else if (pos <= len) {
			nodo *actual = getNodo(pos - 1);
			actual->setSiguiente(new nodo(n, actual->getSiguiente()));
			len++;
		}
	}

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

	bool lista::eliminar(size_t pos = 0) {
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

	int getValor(size_t pos) {
		nodo *n = getNodo(pos);
		if (n != nullptr) {
			return n->getValor();
		}
		throw std::out_of_range("posicion fuera de los limites");
	}
	size_t lista::size() { return len; }

  private:
	lista::nodo *lista::getNodo(size_t pos) {
		// c++ 17, pre c++17 puede declarar uno de los 2 afuera
		for (auto [n, i] = std::tuple{inicio, 0}; n != nullptr; i++) {
			if (i == pos) {
				return n;
			}
		}
		return nullptr;
	}

  public:
	~lista() {}
};
