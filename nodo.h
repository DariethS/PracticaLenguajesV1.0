#include <iostream>
#include "articulo.h"
#include "menu.h"
#ifndef nodo_H
#define nodo_H

using namespace std;

class Nodo{
  private:
    Articulo articulo; //Articulo del nodo en este caso es un objeto
    Nodo* next; //Apuntador
  public:
  //Método constructor
    Nodo(Articulo); 
    //Métodos getter:
    Articulo getArticulo();
    Nodo* getNext();
    //Métodos setter:
    void setArticulo();
    void setNext(Nodo*);
    void set_Cantidad(int);
};

Nodo::Nodo(Articulo articulo){
  this->articulo=articulo;
  this->next=NULL;
}

void Nodo::setArticulo(){
  int choice=1;
  int aux=1;
  if((this->articulo.getTipo()=="Deportivo") or (this->articulo.getTipo()=="Tecnologico")){
    do{
      cout<<"Ingrese el dato cambiar"<<endl;
      cout<<"1. Nombre"<<endl<<"2. ID"<<endl<<"3. Precio"<<endl<<"4. Disponibilidad"<<endl;
      cin>>choice;
      switch(choice){
        case 1:{
          string n;
          cout<<"Digite el nombre"<<endl;
          cin>>n;
          this->articulo.set_Nombre(n);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
        case 2:{
          int id;
          cout<<"Digite la nueva ID"<<endl;
          cin>>id;
          this->articulo.set_Id(id);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
        case 3:{
          int precio;
          cout<<"Digite el nuevo precio"<<endl;
          cin>>precio;
          this->articulo.set_Precio(precio);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
        case 4:{
          int disponibilidad;
          cout<<"Digite la nueva disponibilidad"<<endl;
          cin>>disponibilidad;
          this->articulo.set_Disponibilidad( disponibilidad);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
      }
    }while(aux==1);
  }else{
    do{
      cout<<"Ingrese el dato cambiar"<<endl;
      cout<<"1. Nombre"<<endl<<"2. ID"<<endl<<"3. Precio"<<endl<<"4. Disponibilidad"<<endl<<"5. Impuesto"<<endl;
      cin>>choice;
      switch(choice){
        case 1:{
          string n;
          cout<<"Digite el nombre"<<endl;
          cin>>n;
          this->articulo.set_Nombre(n);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
        case 2:{
          int id;
          cout<<"Digite la nueva ID"<<endl;
          cin>>id;
          this->articulo.set_Id(id);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
        case 3:{
          int precio;
          cout<<"Digite el nuevo precio"<<endl;
          cin>>precio;
          this->articulo.set_Precio(precio);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
        case 4:{
          int disponibilidad;
          cout<<"Digite la nueva disponibilidad"<<endl;
          cin>>disponibilidad;
          this->articulo.set_Disponibilidad( disponibilidad);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
        case 5:{
          int impuesto;
          cout<<"Digite el nuevo impuesto"<<endl;
          cin>>impuesto;
          this->articulo.set_Disponibilidad(impuesto);
          Menu::menuArticuloActualizado();
          cin>>aux;
          break;
        }
      }
    }while(aux==1);
  }
} 

void Nodo::set_Cantidad(int cantidad){
  this->articulo.set_Cantidad(cantidad);
}
  
Articulo Nodo::getArticulo(){
  return this->articulo;
}

Nodo* Nodo::getNext(){
  return this->next;
}

void Nodo::setNext(Nodo *n){
  this->next=n;
}
#endif
