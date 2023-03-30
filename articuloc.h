#include <iostream>
#include "articulo.h"
#ifndef articuloS_H
#define articuloS_H

class ArticuloC : public Articulo{
public:
  ArticuloC(string nombre, int id, int precio, int disponibilidad, string tipo, int impuesto) : Articulo(nombre, id, precio, disponibilidad, tipo, impuesto){}
  int get_Precio() override{
      return this->precio+this->impuesto;
    }
  void set_Impuesto(int impuesto){
    this->impuesto=impuesto;
  }
  int get_Impuesto(){
    return this->impuesto;
  }
};
#endif
