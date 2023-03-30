#include <iostream>
#include <string>
#include <sstream>
#ifndef articulo_H
#define articulo_H
using namespace std;

class Articulo{
  protected:
    string nombre;
    int id;
    int precio;
    int disponibilidad;
    string tipo;
    int cantidad;
    int impuesto;
  public:
  //Métodos constructores
  Articulo();
  Articulo(string,int,int,int,string);
  Articulo(string,int,int,int,string,int);
  //Métodos setter
    void set_Nombre(string);
    void set_Id(int);
    void set_Precio(int);
    void set_Disponibilidad(int);
    void set_Cantidad(int);
    //Métodos getter
    string get_Nombre();
    int get_Id();
    virtual int get_Precio();
    int get_Disponibilidad();
    int get_Cantidad();
    string getTipo();
    string toString();
    string toString2();
  
};

Articulo::Articulo() {
}

//Inicializamos los métodos
Articulo::Articulo(string nombre, int id, int precio, int disponibilidad,string tipo){
  this->nombre=nombre;
  this->id=id;
  this->precio=precio;
  this->disponibilidad=disponibilidad;
  this->tipo=tipo;
  this->cantidad=0;
}

Articulo::Articulo(string nombre, int id, int precio, int disponibilidad,string tipo,int impuesto){
  this->nombre=nombre;
  this->id=id;
  this->precio=precio;
  this->disponibilidad=disponibilidad;
  this->tipo=tipo;
  this->cantidad=0;
  this->impuesto=impuesto;
}
void Articulo::set_Nombre(string nombre){
  this->nombre=nombre;
}

void Articulo::set_Id(int id){
  this->id=id;
}

void Articulo::set_Precio(int precio){
  this->precio=precio;
}

void Articulo::set_Disponibilidad(int disponibilidad){
  this->disponibilidad=disponibilidad;
}

void Articulo::set_Cantidad(int cantidad){
  this->cantidad=cantidad;
}
string Articulo::get_Nombre(){
  return this->nombre;
}

int Articulo::get_Id(){
  return this->id;
}

int Articulo::get_Precio(){
  return this->precio;
}

int Articulo::get_Disponibilidad(){
  return this->disponibilidad;
}

string Articulo::getTipo(){
  return this->tipo;
}

int Articulo::get_Cantidad(){
  return this-> cantidad;
}

string Articulo::toString(){
  stringstream s;
  s<<"Tipo: "<<this->tipo<<endl;
  s<<"Nombre: "<<this->nombre<<endl;
  s<<"ID: "<<this->id<<endl;
  s<<"Precio: "<<this->precio<<endl;
  s<<"Disponibilidad: "<<this->disponibilidad<<endl;
  s<<"---------------------------------------------"<<endl;
  return s.str();
}

string Articulo::toString2(){
  stringstream s;
  s<<"Tipo: "<<this->tipo<<endl;
  s<<"Nombre: "<<this->nombre<<endl;
  s<<"ID: "<<this->id<<endl;
  s<<"Precio: "<<this->precio<<endl;
  s<<"Cantidad: "<<this->cantidad<<endl;
  s<<"---------------------------------------------"<<endl;
  return s.str();
}
#endif
