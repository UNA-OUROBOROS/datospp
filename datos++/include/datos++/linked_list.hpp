#pragma once
#include <cstddef>
#include <stdexcept>
#include <tuple>
#include <type_traits>

namespace datospp {
template <typename T> class LinkedList {
  private:
	class Nodo {
		T valor;
		Nodo *siguiente = nullptr;

	  public:
		explicit Nodo(T &valor, Nodo *siguiente = nullptr)
		    : valor(valor), siguiente(siguiente) {}
		const T &getValor() const { return valor; }
		T &getValor() { return valor; }
		void setSiguiente(Nodo *n) { siguiente = n; }
		Nodo *getSiguiente() const { return siguiente; }
	};
	Nodo *inicio = nullptr;
	size_t len = 0;

  public:
	LinkedList() = default;
	explicit LinkedList(std::initializer_list<T> l) : len(l.size()) {
		Nodo *actual = nullptr;
		for (auto val : l) {
			if (actual) {
				actual->setSiguiente(new Nodo(val));
				actual = actual->getSiguiente();
			} else {
				inicio = new Nodo(val);
				actual = inicio;
			}
		}
	}
	explicit LinkedList(const LinkedList &l) : len(l.len) {
		Nodo *otro = l.inicio;
		Nodo *actual = inicio;
		for (size_t pos = 0; pos < l.len; pos++) {
			if (actual) {
				actual->setSiguiente(new Nodo(otro->getValor()));
				actual = actual->getSiguiente();
			} else {
				actual = new Nodo(otro->getValor());
			}
			otro = otro->getSiguiente();
		}
	}
	explicit LinkedList(LinkedList &&l) noexcept
	    : inicio(l.inicio), len(l.len) {
		l.inicio = nullptr;
		l.len = 0;
	}

	// front
	T &front() {
		if (inicio) {
			return inicio->getValor();
		} else {
			throw std::out_of_range("La lista está vacía");
		}
	}
	const T &front() const {
		if (inicio) {
			return inicio->getValor();
		} else {
			throw std::out_of_range("La lista está vacía");
		}
	}
	// back
	T &back() {
		if (inicio) {
			Nodo *actual = inicio;
			while (actual->getSiguiente()) {
				actual = actual->getSiguiente();
			}
			return actual->getValor();
		} else {
			throw std::out_of_range("La lista está vacía");
		}
	}
	const T &back() const {
		if (inicio) {
			Nodo *actual = inicio;
			while (actual->getSiguiente()) {
				actual = actual->getSiguiente();
			}
			return actual->getValor();
		} else {
			throw std::out_of_range("La lista está vacía");
		}
	}

	void push_front(T &val) {
		inicio = new Nodo(val, inicio);
		len++;
	}
	void push_front(T &&val) {
		inicio = new Nodo(std::move(val), inicio);
		len++;
		if (std::is_pointer<T>::value) {
			delete val;
			val = nullptr;
		}
	}
	void push_back(T &n) {
		if (len == 0) {
			insertarInicio(n);
		} else {
			getNodo(len - 1)->setSiguiente(new Nodo(n));
			len++;
		}
	}
	void push_back(T &&val) {
		if (len == 0) {
			insertarInicio(val);
		} else {
			getNodo(len - 1)->setSiguiente(new Nodo(std::move(val)));
			len++;
		}
		if constexpr (std::is_pointer<T>::value) {
			delete val;
			val = nullptr;
		}
	}

	// emplace
	template <typename... Args> void emplace_front(Args &&...argumentos) {
		inicio = new Nodo(T(std::forward<Args>(argumentos)...), inicio);
		len++;
	}
	// emplace back
	template <typename... Args> void emplace_back(Args &&...argumentos) {
		if (len == 0) {
			emplace_front(std::forward<Args>(argumentos)...);
		} else {
			getNodo(len - 1)->setSiguiente(
			    new Nodo(T(std::forward<Args>(argumentos)...)));
			len++;
		}
	}

	void insert(T &n, size_t pos = 0) {
		if (pos == 0) {
			push_front(n);
		} else if (pos <= len) {
			Nodo *actual = getNodo(pos - 1);
			actual->setSiguiente(new Nodo(n, actual->getSiguiente()));
			len++;
		}
	}
	bool erase(size_t pos = 0) {
		if (pos == 0) {
			return erase_front();
		}
		if (pos < len) {
			Nodo *previo = getNodo(pos - 1);
			Nodo *sig = previo->getSiguiente()->getSiguiente();
			delete previo->getSiguiente();
			previo->setSiguiente(sig);
			len--;
			return true;
		}
		return false;
	}

	bool pop_front() {
		if (inicio) {
			Nodo *siguiente = inicio->getSiguiente();
			delete inicio;
			inicio = siguiente;
			len--;
			return true;
		}
		return false;
	}
	bool pop_back() {
		if (len != 0) {
			if (len == 1) {
				delete inicio;
			} else {
				Nodo *n = getNodo(len - 1);
				delete n->getSiguiente();
				n->setSiguiente(nullptr);
			}
			len--;
			return true;
		}
		return false;
	}

	T &at(size_t pos) const {
		Nodo *n = getNodo(pos);
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
	Nodo *getNodo(size_t pos) const {
		// c++ 17, pre c++17 puede declarar uno de los 2 afuera
		for (auto [n, i] = std::tuple{inicio, 0}; n;
		     i++, n = n->getSiguiente()) {
			if (i == pos) {
				return n;
			}
		}
		return nullptr;
	}

  public:
	class Iterator {
		Nodo *actual = nullptr;

	  public:
		Iterator(Nodo *n = nullptr) : actual(n) {}

		T &operator*() { return actual->getValor(); }
		bool operator!=(Iterator &o) { return this->actual != o.actual; }

		Iterator &operator++() {
			actual = actual ? actual->getSiguiente() : actual;
			return *this;
		}
	};

	LinkedList operator=(const LinkedList &l) {
		clear();

		Nodo *otro = l.inicio;
		Nodo *actual = inicio;
		for (size_t pos = 0; pos < l.len; pos++) {
			if (actual) {
				actual->setSiguiente(new Nodo(otro->getValor()));
				actual = actual->getSiguiente();
			} else {
				actual = new Nodo(otro->getValor());
			}
			otro = otro->getSiguiente();
		}
		return *this;
	}
	LinkedList operator=(LinkedList &&l) noexcept {
		clear();
		inicio = l.inicio;
		len = l.len;
		l.inicio = nullptr;
		l.len = 0;
		return *this;
	}

	// Iterator begin() { return Iterator(inicio); }
	// Iterator end() { return Iterator(getNodo(len - 1)); }
	Nodo begin() { return inicio; }
	Nodo end() { return getNodo(len - 1); }

	~LinkedList() { clear(); }
};

} // namespace datospp
