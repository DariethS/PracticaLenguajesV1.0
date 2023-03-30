#include <iostream>
#include "carrito.h"
#include "usuario.h"
#ifndef cliente_h
#define cliente_h

using namespace std;
class Cliente : public Usuario{
  private:
    Lista* carrito=new Carrito();
  public:
   Cliente():Usuario(){}
    void comprarArticulo(Lista*);
    void pagar();
};

void Cliente:: comprarArticulo(Lista *inventario){
  Nodo* aux;
  Articulo aux2;
  int a;
  int choice;
  int cantidad;
  inventario->mostrar();
  do{
    cout<<"Digite la ID del artículo que quiere agregar al carrito: "<<endl;
  cin>>choice;
    aux=inventario->buscar(choice);
    if(aux!=NULL){
      aux2=aux->getArticulo();
      do{
        a=0;
        cout<<"Digite la cantidad que quiere de ese artículo: "<<endl;
        cin>>cantidad;
        if(cantidad<=aux2.get_Disponibilidad()){
          this->carrito->agregarNodo(aux);
          aux2.set_Disponibilidad(aux2.get_Disponibilidad()-cantidad);
          aux->set_Cantidad(cantidad);
        }else{
          cout<<"No hay tantos artículos como los que quiere"<<endl;
          a=1;
        }
      }while(a==1);
      if(aux2.get_Disponibilidad()<=0){
        inventario->eliminar(aux2.get_Id());
      }
    }else{
      cout<<"Artículo agotado"<<endl;
    }
    
    cout<<"¿Desea agregar otro artículo al carrito?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
    cin>>choice;
  }while(choice==1);
  cout<<"Artículos agregados al carrito: "<<endl;
  carrito->mostrarCarrito();
}

void Cliente::pagar(){
  int total;
  int totalConDescuento;
  if(this->carrito->getHead()==NULL){
    cout<<"No hay artículos en su carrito"<<endl;
  } else{
    int choice;
    cout<<"\tLos artículos añadidos al carrito fueron: "<<endl;
    this->carrito->mostrarCarrito();
    total=carrito->sumarPrecios();
    if(carrito->buscarConsecutivos()){
      total=total*0.1;
    }
    cout<<"Total a pagar: "<<total<<endl;
    Menu::menuPagar();
    cin>>choice;
    if(choice==1){
      cout<<"Articulos comprados"<<endl;
      carrito->setHead(NULL);
    }else{
      cout<<"Compra cancelada"<<endl;
      carrito->setHead(NULL);
    }
  }
}
#endif
