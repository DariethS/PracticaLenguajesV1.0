#include <iostream>
#ifndef coordinador_H //guards
#define coordinador_H
#include "inventario.h"
#include "articulo.h"
#include "articuloc.h"
#include "articulod.h"
#include "articulot.h"
#include "usuario.h"

using namespace std;
class Coordinador : public Usuario{
  private:
    Lista* inventario=new Inventario();
  public:  
    Coordinador();
    void crearArticulo();
    void modificarArticulo();
    Lista* getInventario();
};

Coordinador::Coordinador() : Usuario(){}

void Coordinador::crearArticulo(){
  string nombre;
  int id;
  int precio;
  int disponibilidad;
  int impuesto;
  int choice;
  Nodo* aux;

  do{
    cout<<"Digite el tipo del artículo: "<<endl<<"1. Deportivo"<<endl<<"2. Tecnologico"<<endl<<"3. Extranjero"<<endl;
    cin>>choice;
    if(choice==1){
      cout<<"\tTipo de artículo: DEPORTIVO"<<endl;
      Menu::menuCrearArticulo();
      cin>>nombre;
      cin>>id;
      cin>>precio;
      cin>>disponibilidad;
      ArticuloD a(nombre,id ,precio , disponibilidad, "Deportivo");
      Nodo* aux = new Nodo(a);
      this->inventario->agregarNodo(aux);
      cout<<"Artículo creado extiosamente"<<endl;
      this->inventario->getHead()->getArticulo().get_Nombre();
    }else if(choice==2){
      cout<<"\tTipo de artículo: TECNOLÓGICO"<<endl;
      Menu::menuCrearArticulo();
      cin>>nombre;
      cin>>id;
      cin>>precio;
      cin>>disponibilidad;
      ArticuloT a(nombre,id ,precio , disponibilidad, "Tecnologico");
      Nodo* aux = new Nodo(a);
      this->inventario->agregarNodo(aux);
      cout<<"Artículo creado extiosamente"<<endl<<endl;
      cout<<"--------------------------------------------"<<endl;
    } else if(choice==3){
      cout<<"\tTipo de artículo: EXTRANJERO"<<endl;
      Menu::menuCrearArticulo();
      cout<<"- Impuesto"<<endl;
      cin>>nombre;
      cin>>id;
      cin>>precio;
      cin>>disponibilidad;
      cin>>impuesto;
      ArticuloC a(nombre,id ,precio , disponibilidad, "Extranjero", impuesto);
      Nodo* aux = new Nodo(a);
      this->inventario->agregarNodo(aux);
      cout<<"Artículo creado extiosamente"<<endl<<endl;
      cout<<"--------------------------------------------"<<endl;
      }else{
      cout<<"Opción incorrecta"<<endl<<endl;
    }
    cout<<"¿Desea añadir un artículo otra vez?"<<endl<<"1. Sí"<<endl<<"2. No"<<endl;
    cin>>choice;
    if(choice==2){
      break;
    }
  } while (true);
}

void Coordinador::modificarArticulo(){
  int a=1;
  int id;
  Nodo* aux1;
  do{
    cout<<"Digite la ID a buscar: "<<endl;
    cin>>id;
    aux1=inventario->buscar(id);
    if(aux1==NULL){
     cout<<"no fue encontrado el artículo con el ID asociado"<<endl;
    cout<<"¿Desea intentarlo de nuevo?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
       cin>>a;
    }else{
        aux1->setArticulo();
        cout<<"Desea cambiar los atributos de otro artículo"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
        cin>>a;
    }
  }while (a==1);
}
Lista* Coordinador::getInventario(){
  return this->inventario;
}

#endif
