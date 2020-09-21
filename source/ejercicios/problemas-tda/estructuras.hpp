#pragma once
#include <lista.hpp>

template <typename T> class colaPrioridad : public lista<T> {
  private:
	bool menor = false;

  public:
	colaPrioridad(bool menor = false) : menor(menor) {}
	void insertar(T elem) {
		for (size_t i = 0; i < lista<T>::size(); i++) {
			T val = lista<T>::getValor(i);
			// cada clase es responsable de sobrecargar su operador
			if (menor ? elem < val : elem > val) {
				lista<T>::insertar(elem, i);
				return;
			}
		}
		lista<T>::insertarFinal(elem);
	}
	T recuperar() {
		T val = lista<T>::getValor(0);
		lista<T>::eliminarInicio();
		return val;
	}
	bool vacio() { return lista<T>::size() == 0; }
};

// FILO
template <typename T> class pila : private lista<T> {
  public:
	void insertar(T elem) { insertarInicio(elem); }
	T recuperar() {
		T val = lista<T>::getValor(lista<T>::size());
		lista<T>::eliminarInicio();
		return val;
	}
	bool vacio() { return lista<T>::size() == 0; }
};

// FIFO
template <typename T> class cola : public lista<T> {
  public:
	void insertar(T elem) { lista<T>::insertarFinal(elem); }
	T recuperar() {
		T val = lista<T>::getValor(0);
		lista<T>::eliminarInicio();
		return val;
	}
	bool vacio() { return lista<T>::size() == 0; }
};

class dummy {
	
	std::string nombre;
	std::string informacion;
	dummy *siguiente = nullptr;

  public:
	dummy(std::string nombre, std::string informacion, dummy *sig = nullptr)
	    : nombre(nombre), informacion(informacion), siguiente(sig) {}
	std::string toString(int acc = 1) {
		std::string mensaje = "mi nombre es " + nombre + " y " + informacion;
		if (siguiente) {
			mensaje += ", ademas " + siguiente->nombre + " dijo\n";
			for (size_t i = 0; i < acc; i++) {
				mensaje += "\t";
			}

			mensaje += +"-> " + siguiente->toString(acc + 1);
		}
		return mensaje;
	}
};
