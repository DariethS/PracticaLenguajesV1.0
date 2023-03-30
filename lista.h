#include <iostream>
#ifndef lista_H
#define lista_H
#include "nodo.h"
using namespace std;

class Lista {
protected:
  Nodo *head; // Guardará la dirección del primer nodo
public:
  Lista(); // Método constructor
  // Métodos setter
  void setHead(Nodo *);
  // Métodos getter
  Nodo *getHead();
  Nodo *getUltimo();
  // Otros métodos
  void agregarNodo(Nodo *); // Agrega nodos a la lista
  Nodo *buscar(int);        // Busca un Nodo con un ID asociado
  void eliminar(int);       // Elimina un Nodo con el ID asociado
  void mostrar();
  int sumarPrecios();
  void mostrar2();
  bool buscarConsecutivos();
  void mostrarCarrito();
};

// Inicializamos los métodos
Lista::Lista() { this->head = NULL; }

void Lista::setHead(Nodo *head) { this->head = head; }

Nodo *Lista::getHead() { return this->head; }

Nodo *Lista::getUltimo() {
  Nodo *current = getHead();
  while (current->getNext() != NULL) {
    current = current->getNext();
  }
  return current;
}

void Lista::agregarNodo(Nodo *n) {
  if (getHead() == NULL) {
    setHead(n);
  } else {
    getUltimo()->setNext(n);
  }
}

Nodo *Lista::buscar(int id) {
  Nodo *busqueda = getHead();
  while ((busqueda != NULL) and (busqueda->getArticulo().get_Id() != id)) {
    busqueda = busqueda->getNext();
  }
  return busqueda;
}

void Lista::eliminar(int id) {
  Nodo *busqueda = getHead();
  Nodo *prev = NULL;
  if (busqueda != NULL) {
    if (busqueda->getArticulo().get_Id() == id) {
      setHead(getHead()->getNext());
    } else {
      while ((busqueda != NULL) and (busqueda->getArticulo().get_Id() != id)) {
        prev = busqueda;
        busqueda = busqueda->getNext();
      }
      if (busqueda != NULL) {
        prev->setNext(busqueda->getNext());
      }
      delete busqueda;
    }
  }
}

void Lista::mostrar() {
  Nodo *aux = getHead();
  if (aux != NULL) {
    cout << "\t|Articulos deportivos|" << endl;
    while (aux != NULL) {
      if (aux->getArticulo().getTipo() == "Deportivo") {
        cout << aux->getArticulo().toString() << endl;
      }
      aux = aux->getNext();
    }
    aux = getHead();
    cout << "\t|Articulos Tecnológicos|" << endl;
    while (aux != NULL) {
      if (aux->getArticulo().getTipo() == "Tecnologico") {
        cout << aux->getArticulo().toString() << endl;
      }
      aux = aux->getNext();
    }
    aux = getHead();
    cout << "\t|Articulos Extranjeros|" << endl;
    while (aux != NULL) {
      if (aux->getArticulo().getTipo() == "Extranjero") {
        cout << aux->getArticulo().toString() << endl;
      }
      aux = aux->getNext();
    }
  } else {
    cout << "No hay artículos" << endl;
  }
}

void Lista::mostrar2() {
  Nodo *aux = getHead();
  if (aux != NULL) {
    cout << "\t|Articulos Deportivos|" << endl;
    while (aux != NULL) {
      if (aux->getArticulo().getTipo() == "Deportivo") {
        cout << aux->getArticulo().toString2() << endl;
      }
      aux = aux->getNext();
    }
    aux = getHead();
    cout << "\t|Articulos Tecnológicos|" << endl;
    while (aux != NULL) {
      if (aux->getArticulo().getTipo() == "Tecnologico") {
        cout << aux->getArticulo().toString2() << endl;
      }
      aux = aux->getNext();
    }
    aux = getHead();
    cout << "\t|Articulos Extranjeros|"<< endl;
    while (aux != NULL) {
      if (aux->getArticulo().getTipo() == "Extranjero") {
        cout << aux->getArticulo().toString2() << endl;
      }
      aux = aux->getNext();
    }
  } else {
    cout << "No hay artículos" << endl;
  }
}
bool Lista::buscarConsecutivos(){
  bool aux1=false;
  Nodo *busqueda = getHead();
  while(busqueda != NULL){
    if(busqueda->getArticulo().getTipo()==busqueda->getNext()->getArticulo().getTipo()){
      aux1=true;
    }
    busqueda = busqueda->getNext();
  }
  return aux1;
  
}

void Lista::mostrarCarrito(){
  Nodo *aux = getHead();
  Nodo *aux1;
  while (aux != NULL) {
    cout << aux->getArticulo().toString2() << endl;
    aux1 = aux->getNext();
    aux=aux1;
  }
}
int Lista::sumarPrecios() {
  int suma = 0;
  Nodo *aux = getHead();
  if (aux == NULL) {
    cout << "No hay artículos para sumar precio" << endl;
  } else {
    while (aux != NULL) {
      suma += aux->getArticulo().get_Cantidad()*(aux->getArticulo().get_Precio());
      aux = aux->getNext();
    }
  }
  return suma;
}
#endif
