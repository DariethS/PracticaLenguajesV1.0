#include <iostream>
#include "articulo.h"
#ifndef articuloT_H
#define articuloT_H

using namespace std;

class ArticuloT : public Articulo{
  public:
    //método constructor
    ArticuloT(string, int, int ,int, string); 
};

ArticuloT::ArticuloT(string nombre, int id, int precio, int disponibilidad, string tipo) : Articulo(nombre,id,precio,disponibilidad, tipo){}  


#endif
