#include <iostream>
#ifndef menu_H
#define menu_H
using namespace std;
class Menu{
  public:
    static void menuInicio();
    static void menuCoordinador();
    static void menuCliente();
    static void menuCrearArticulo();
    static void menuArticuloActualizado();
    static void menuPagar();
};

void Menu::menuInicio(){
  cout<<"\t|Bienvenid@ usuario|"<<endl<<endl<<"Digite qué tipo de usuario es: "<<endl<<endl<<"1. Cliente"<<endl<<"2. Coordinador"<<endl<<"3. Salir"<<endl;
}

void Menu::menuCoordinador(){
  cout<<"\t|Menú Coordinador|"<<endl;
  cout<<"Digite qué acción quiere realizar: "<<endl<<"1. Agregar un artículo al inventario"<<endl<<"2. Modificar un artículo"<<endl<<"3. Eliminar un artículo"<<endl<<"4. salir"<<endl;
}

void Menu::menuCliente(){
  cout<<"\t|Menú Cliente|"<<endl;
  cout<<"Digite que acción quiere realizar: "<<endl<<"1. Añadir artículo a su carrito de compras"<<endl<<"2. Comprar articulos"<<endl<<"3. salir"<<endl;
}

void Menu::menuCrearArticulo(){
  cout<<"Digite en orden los siguientes datos del artículo para agregarlo: "<<endl<<"- Nombre"<<endl<<"- ID"<<endl<<"- Precio"<<endl<<"- Disponibilidad"<<endl;
}

void Menu::menuArticuloActualizado(){
  cout<<"Articulo actualizado exitosamente"<<endl;
  cout<<"----------------------------"<<endl;
  cout<<"¿Desea cambiar otro atributo del mismo Artículo?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
}

void Menu::menuPagar(){
  cout<<"Confirme su compra: "<<endl<<"1. Si"<<endl<<"2. No"<<endl;
}

#endif
