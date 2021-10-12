#include <lista.hpp>

template <typename T> class colaPrioridad : public lista<T> {
  private:
	bool menor = false;

  public:
	colaPrioridad(bool menor = false) : menor(menor) {}
	void insertar(T elem) {
		for (size_t i = 0; i < lista<T>::size(); i++) {
			T val = lista<T>::at(i);
			// cada clase es responsable de sobrecargar su operador
			if (menor ? elem < val : elem > val) {
				lista<T>::insertar(elem, i);
				return;
			}
		}
		lista<T>::insertarFinal(elem);
	}
	T recuperar() {
		T val = lista<T>::at(0);
		lista<T>::eliminarInicio();
		return val;
	}
    void pop(){
        lista<T>::eliminarInicio();
    }
	bool vacio() { return lista<T>::size() == 0; }
};