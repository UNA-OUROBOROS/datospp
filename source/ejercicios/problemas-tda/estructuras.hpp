#pragma once
#include <lista_doble.hpp>

template <typename T> class colaPrioridad : public listaDoble<T> {
  private:
	bool menor = false;

  public:
	colaPrioridad(bool menor = false) : menor(menor) {}
	void insertar(T elem) {
		for (size_t i = 0; i < listaDoble<T>::size(); i++) {
			T val = listaDoble<T>::at(i);
			// cada clase es responsable de sobrecargar su operador
			if (menor ? elem < val : elem > val) {
				listaDoble<T>::insertar(elem, i);
				return;
			}
		}
		listaDoble<T>::insertarFinal(elem);
	}
	T recuperar() {
		T val = listaDoble<T>::at(0);
		listaDoble<T>::eliminarInicio();
		return val;
	}
	bool vacio() { return listaDoble<T>::size() == 0; }
};

// FILO
template <typename T> class pila : private listaDoble<T> {
  public:
	void insertar(T elem) { insertarInicio(elem); }
	T recuperar() {
		T val = listaDoble<T>::at(listaDoble<T>::size());
		listaDoble<T>::eliminarInicio();
		return val;
	}
	bool vacio() { return listaDoble<T>::size() == 0; }
};

// FIFO
template <typename T> class cola : public listaDoble<T> {
  public:
	void insertar(T elem) { listaDoble<T>::insertarFinal(elem); }
	T recuperar() {
		T val = listaDoble<T>::at(0);
		listaDoble<T>::eliminarInicio();
		return val;
	}
	bool vacio() { return listaDoble<T>::size() == 0; }
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
