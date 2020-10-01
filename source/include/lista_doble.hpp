#pragma once
#include <cstddef>
#include <stdexcept>
#include <tuple>

template <typename T> class listaDoble {
  private:
	template <typename A>
	class nodo {
		A valor;
		nodo *siguiente = nullptr;
		nodo *anterior = nullptr;

	  public:
		
		nodo(A valor, nodo *siguiente = nullptr, nodo *anterior = nullptr)
		    : valor(valor), siguiente(siguiente), anterior(anterior) {}
		A getValor() { return valor; }
		void setSiguiente(nodo *n) { siguiente = n; }
		void setAnterior(nodo *n) { anterior = n; }
		nodo *getSiguiente() { return siguiente; }
		nodo *getAnterior() { return anterior; }
	};
	nodo<T> *inicio = nullptr;
	nodo<T> *ultimo = nullptr;
	size_t len = 0;

  public:
	listaDoble() = default;
	void insertar(T n, size_t pos = 0) {
		if (pos == 0) {
			insertarInicio(n);
		} else if (pos <= len) {
			nodo<T> *anterior = getNodo(pos - 1);
			nodo<T> *nuevo = new nodo<T>(n, anterior, anterior->getSiguiente());
			anterior->getSiguiente()->setSiguiente(nuevo);
			anterior->setSiguiente(nuevo);
			len++;
		}
	}
	void insertarInicio(T n) {
		inicio = new nodo<T>(n, inicio);
		len++;
	}
	void insertarFinal(T n) {
		if (n == 0) {
			insertarInicio(n);
		} else {
			ultimo->setSiguiente(new nodo(n, nullptr, ultimo));
			ultimo = ultimo->getSiguiente();
			// getNodo(len - 1)->setSiguiente(new nodo(n));
			len++;
		}
	}
	bool eliminar(size_t pos = 0) {
		if (pos == 0) {
			return eliminarInicio();
		}
		if (pos < len) {
			nodo<T> *previo = getNodo(pos - 1);
			nodo<T> *sig = previo->getSiguiente()->getSiguiente();
			delete previo->getSiguiente();
			previo->setSiguiente(sig);
			len--;
			return true;
		}
		return false;
	}
	bool eliminarInicio() {
		if (inicio) {
			nodo<T> *siguiente = inicio->getSiguiente();
			delete inicio;
			if (siguiente) {
				siguiente->setAnterior(nullptr);
			}
			inicio = siguiente;
			len--;
			return true;
		}
		return false;
	}
	bool eliminarFinal() {
		if (len != 0) {
			if (len == 1) {
				delete inicio;
			} else {
				nodo<T> *n = getNodo(len - 1);
				delete n->getSiguiente();
				n->setSiguiente(nullptr);
			}
			len--;
			return true;
		}
		return false;
	}
	T getValor(size_t pos) {
		nodo<T> *n = getNodo(pos);
		if (n != nullptr) {
			return n->getValor();
		}
		throw std::out_of_range("posicion fuera de los limites");
	}
	size_t size() { return len; }

	void clear() {
		while (len) {
			eliminarInicio();
		}
	}

  private:
	nodo<T> *getNodo(size_t pos) {
		// c++ 17, pre c++17 puede declarar uno de los 2 afuera
		bool reversa = pos > len / 2;
		for (auto [n, i] = std::tuple{inicio, reversa ? len - 1 : 0};
		     n != nullptr; reversa ? i-- : i++) {
			if (i == pos) {
				return n;
			}
			n = reversa ? n->getAnterior() : n->getSiguiente();
		}
		return nullptr;
	}

  public:
	~listaDoble() { clear(); }
};
