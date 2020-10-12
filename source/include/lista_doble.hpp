#pragma once
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <tuple>
#include <type_traits>

template <typename T> class listaDoble {
  private:
	class nodo {
		T valor;
		nodo *siguiente = nullptr;
		nodo *anterior = nullptr;

	  public:
		nodo(T &valor, nodo *siguiente = nullptr, nodo *anterior = nullptr)
		    : valor(valor), siguiente(siguiente), anterior(anterior) {}
		const T &getValor() const { return valor; }
		T &getValor() { return valor; }
		void setSiguiente(nodo *n) { siguiente = n; }
		void setAnterior(nodo *n) { anterior = n; }
		nodo *getSiguiente() const { return siguiente; }
		nodo *getAnterior() const { return anterior; }
		~nodo() {
			if constexpr (std::is_pointer<T>::value) {
				delete valor;
			}
		}
	};
	nodo *inicio = nullptr;
	nodo *ultimo = nullptr;
	size_t len = 0;

  public:
	listaDoble() = default;
	void insertar(T &n, size_t pos = 0) {
		if (pos == 0) {
			insertarInicio(n);
		} else if (pos <= len) {
			nodo *anterior = getNodo(pos - 1);
			nodo *nuevo = new nodo(n, anterior, anterior->getSiguiente());
			anterior->getSiguiente()->setSiguiente(nuevo);
			anterior->setSiguiente(nuevo);
			len++;
		}
		else{
			throw std::out_of_range("posicion fuera de los limites");
		}
	}
	void insertarInicio(T &n) {
		inicio = new nodo(n, inicio);
		nodo *sig = inicio->getSiguiente();
		if (sig) {
			sig->setAnterior(inicio);
		}
		
		if (!ultimo) {
			ultimo = inicio;
		}
		len++;
	}
	void insertarFinal(T &n) {
		if (n == 0 || len == 0) {
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
			nodo *previo = getNodo(pos - 1);
			nodo *sig = previo->getSiguiente()->getSiguiente();
			delete previo->getSiguiente();
			previo->setSiguiente(sig);
			len--;
			return true;
		}
		return false;
	}
	bool eliminarInicio() {
		if (inicio) {
			nodo *siguiente = inicio->getSiguiente();
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
				nodo *n = getNodo(len - 1);
				delete n->getSiguiente();
				n->setSiguiente(nullptr);
			}
			len--;
			return true;
		}
		return false;
	}
	T &at(size_t pos) const {
		nodo *n = getNodo(pos);
		if (n) {
			return n->getValor();
		}
		throw std::out_of_range("posicion fuera de los limites");
	}
	size_t size() const { return len; }
	bool empty() const { return len; }
	void clear() {
		while (len) {
			eliminarInicio();
		}
	}

	T &operator[](size_t pos) const { return at(pos); }

  private:
	nodo *getNodo(size_t pos) const {
		// c++ 17, pre c++17 puede declarar uno de los 2 afuera
		bool reversa = pos > len / 2;
		for (auto [n, i] = std::tuple{inicio, reversa ? len - 1 : 0}; n;
		     (reversa ? i-- : i++),
		              n = (reversa ? n->getAnterior() : n->getSiguiente())) {
			if (i == pos) {
				return n;
			}
		}
		return nullptr;
	}

  public:
	~listaDoble() { clear(); }
};
