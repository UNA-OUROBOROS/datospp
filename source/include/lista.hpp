#pragma once
#include <cstddef>

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
	lista();
	void insertar(int n, size_t pos = 0);
	void insertarInicio(int n);
	void insertarFinal(int n);
	bool eliminar(size_t pos = 0);
	bool eliminarInicio();
	bool eliminarFinal();

	int getValor(size_t pos);
	size_t size();

  private:
	nodo *getNodo(size_t n);

  public:
	~lista();
};
