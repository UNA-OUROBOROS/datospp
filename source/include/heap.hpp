#pragma once
#include <vector.hpp>

template <typename T> class Heap : private Vector<T> {
	size_t getPadre(size_t pos) { return (pos - 1) / 2; }
	size_t getIzquierdo(size_t pos) { return (2 * pos + 1); }
	size_t getDerecho(size_t pos) { return (2 * pos + 2); }

	void heapify_down(size_t pos, bool ordenMayor = true) {
		size_t izquierdo = getIzquierdo(pos);
		size_t derecho = getDerecho(pos);
		size_t mayor = pos;

		if (izquierdo < size() &&
		    (ordenMayor ? Vector<T>::at(izquierdo) > Vector<T>::at(pos)
		                : Vector<T>::at(izquierdo) < Vector<T>::at(pos))) {
			mayor = izquierdo;
		}
		if (derecho < size() &&
		    (ordenMayor ? Vector<T>::at(derecho) > Vector<T>::at(mayor)
		                : Vector<T>::at(derecho) < Vector<T>::at(mayor))) {
			mayor = derecho;
		}
		if (mayor != pos) {
			Vector<T>::swap(pos, mayor);
			heapify_down(mayor);
		}
	}
	void heapify_up(size_t pos, bool ordenMayor = true) {
		if (pos &&
		    (ordenMayor ? Vector<T>::at(getPadre(pos)) < Vector<T>::at(pos)
		                : Vector<T>::at(getPadre(pos)) > Vector<T>::at(pos))) {
			Vector<T>::swap(pos, getPadre(pos));
			heapify_up(getPadre(pos));
		}
	}

  public:
	Heap() = default;
	Heap(std::initializer_list<T> l) : Vector<T>(l) { heapify(); }
	Heap(Heap<T> &&heap) : Vector<T>(heap) { heapify(); }
	Heap(Heap<T> &heap) : Vector<T>(heap) { heapify(); }
	Heap(Vector<T> &&v) : Vector<T>(v) { heapify(); }
	Heap(Vector<T> &v) : Vector<T>(v) { heapify(); }

	size_t size() const { return Vector<T>::size(); }
	bool empty() const { return size() == 0; }

	void push(T &valor, bool ordenMayor = true) {
		Vector<T>::push_back(valor);
		size_t indice = size() - 1;
		heapify_up(indice, ordenMayor);
	}
	void push(T &&valor) {
		Vector<T>::push_back(valor);
		size_t indice = size() - 1;
		heapify_up(indice);
	}
	void pop() {
		if (empty()) {
			throw std::underflow_error("no hay elementos en el Heap");
		}
		Vector<T>::at(0) = Vector<T>::at(size() - 1);
		Vector<T>::pop_back();
		heapify_down(0);
	}
	T &top() {
		if (empty()) {
			throw std::underflow_error("no hay elementos en el Heap");
		}
		return Vector<T>::at(0);
	}
	const T &top() const {
		if (empty()) {
			throw std::underflow_error("no hay elementos en el Heap");
		}
		return Vector<T>::at(0);
	}

	void clear() { Vector<T>::clear(); }

	T &operator[](size_t pos) { return Vector<T>::at(pos); }

	Heap &operator=(Heap<T> &&heap) {
		Vector<T>::operator=(heap);
		heapify();
	}
	Heap &operator=(Heap<T> &heap) {
		Vector<T>::operator=(heap);
		heapify();
	}
	Heap &operator=(Vector<T> &&v) {
		Vector<T>::operator=(v);
		heapify();
	}
	Heap &operator=(Vector<T> &v) {
		Vector<T>::operator=(v);
		heapify();
	}

	Heap &heapify(bool ordenMayor = true) {
		if (size()) {
			for (size_t i = size() / 2 - 1; i >= 0; i--) {
				heapify_down(i, ordenMayor);
				if (i == 0) {
					break;
				}
			}
			for (size_t i = size() - 1; i >= 0; i--) {
				Vector<T>::swap(0, i);
				heapify_down(0, ordenMayor);
				if (i == 0) {
					break;
				}
			}
		}
		return *this;
	}
};
