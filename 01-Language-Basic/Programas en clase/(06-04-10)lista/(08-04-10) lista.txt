#include <iostream>

using namespace std;

class nodo
{
    private:
    double valor;
    nodo *siguiente;
    friend class lista_simple; //clave para la lista colocarla en private
    public:
    nodo(double v, nodo*sig=NULL)
    {
        valor=v;
        siguiente=sig;
        }
};


 class lista_simple
 {
     private:
     nodo *primero;
     nodo *actual;
     int tamano;
     public:
     lista_simple()
     {
     primero=actual=NULL;
     tamano=0; //no reconoce la ñ
     }
     void siguiente();
     /*void primero();
     void ultimo();
     bool esta_vacia();*/
     void Incluir_primero(double v);
     void Incluir_ultimo(double v);
     void Mostrar();
     void Borrar_primero();
     void Borrar_ultimo();
     void Borrar(double v);

 };

 //funciones

void lista_simple::siguiente()
 {
     actual=actual->siguiente;
 }

void lista_simple::Incluir_primero(double v)
  {
      nodo*nuevo;
      if(primero==NULL)
      primero=new nodo(v);
      else
      {
          nuevo=new nodo(v,primero);
          primero=nuevo;
      }
      tamano++;
  }

void lista_simple::Incluir_ultimo(double v)
{
    nodo*nuevo;
      if(primero==NULL)
      primero=new nodo(v);
      else
      {
         actual=primero;
         while(actual->siguiente!=NULL)
         {
             actual=actual->siguiente;
             }
             nuevo=new nodo(v);
             actual->siguiente=nuevo;
      }
      tamano++;
    }

void lista_simple::Mostrar()
{
cout<<"La lista es: "<<endl;
actual=primero;
while(actual!=NULL)
//for(int i=0;i<tamano;i++)
{
cout<<actual->valor<<" , ";
actual=actual->siguiente;
}
}

void lista_simple::Borrar_primero()
{
    actual=primero;
    primero=actual->siguiente;
    delete actual;
    actual=primero;
    tamano --;
}

void lista_simple::Borrar_ultimo()
{
    nodo*anterior;
    anterior=primero;
    actual=primero;
    for(int i=1;i<tamano-1;i++){
        actual=actual->siguiente;
    }
    anterior=actual;
    actual=actual->siguiente;
    delete actual;
    anterior->siguiente=NULL;
    actual=primero;
    tamano--;
}

void lista_simple::Borrar(double v)
{
    nodo*anterior;
    anterior=primero;
    actual=primero;//
    if(primero->valor==v)
    Borrar_primero();
    else
    {
        actual=actual->siguiente;
        while(actual!=NULL)
        {
            if(actual->valor==v)
            {
                anterior->siguiente=actual->siguiente;
                actual=anterior->siguiente;
            }
            else {
                anterior=actual;
                siguiente();}
        }
    }
}

int main()
{
    lista_simple LS;
    LS.Incluir_primero(8);
    LS.Incluir_primero(-1);
    LS.Incluir_primero(4);
    LS.Mostrar();
    cout<<" "<<endl;
    LS.Borrar_primero();
    LS.Borrar_ultimo();
    LS.Mostrar();
    return 0;
}
