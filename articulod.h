#include <iostream>
#include "articulo.h"
#ifndef articuloD_H
#define articuloD_H

using namespace std;

class ArticuloD : public Articulo{
  public:
    //Método constructor
    ArticuloD(string ,int ,int ,int, string);
};
//Inicializamos el Método constructor que llama al constructor de la clase padre
ArticuloD::ArticuloD(string nombre,int id, int precio, int disponibilidad, string tipo) : Articulo(nombre,id,precio,disponibilidad, tipo){}

#endif
