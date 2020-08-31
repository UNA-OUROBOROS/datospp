#pragma once
#include <cstddef>
#include <stdexcept>
#include <tuple>

class listaDoble {
  private:
	class nodo {
		int valor;
		nodo *siguiente = nullptr;
		nodo *anterior = nullptr;

	  public:
		nodo(int valor, nodo *siguiente = nullptr, nodo *anterior = nullptr)
		    : valor(valor), siguiente(siguiente), anterior(anterior) {}
		int getValor() { return valor; }
		void setSiguiente(nodo *n) { siguiente = n; }
		void setAnterior(nodo *n) { anterior = n; }
		nodo *getSiguiente() { return siguiente; }
		nodo *getAnterior() { return anterior; }
	};
	nodo *inicio = nullptr;
	nodo *ultimo = nullptr;
	size_t len = 0;

  public:
	listaDoble();
	void insertar(int n, size_t pos = 0);
	void insertarInicio(int n);
	void insertarFinal(int n);
	bool eliminar(size_t pos = 0);
	bool eliminarInicio();
	bool eliminarFinal();
	int getValor(size_t pos);
	size_t size();

  private:
	nodo *getNodo(size_t pos);

  public:
	~listaDoble();
};