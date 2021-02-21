#include <iostream>

using namespace std;

class nodo_e
{
    private:
    double valor;
    nodo_e*siguiente;
    nodo_e*anterior;
    friend class lista_doble;
    public:
    nodo_e(double v, nodo_e*sig=NULL,nodo_e*ant=NULL)
    {
        valor=v;
        siguiente=sig;
        anterior=ant;
    }

    class lista_doble
 {
     private:
     nodo_e *primero;
     nodo_e *actual;
     nodo_e *ultimo;
     int tamano;
     public:
     lista_doble()
     {
     primero=actual=ultimo=NULL;
     }
    void Incluir_primero(double v);
    void Incluir_ultimo(double v);

void lista_doble::Incluir_primero(double v)
  {
      nodo_e*nuevo;
      if(primero==NULL&&ultimo==NULL)
      primero=new nodo_e(v);
      else
      {
          nuevo=new nodo_e(v,primero);
          primero->anterior=nuevo;
          primero=nuevo;
      }
  }

void lista_doble::Incluir_ultimo(double v)
{
    nodo_e*nuevo;
      if(primero==NULL&&ultimo==NULL)
      primero=new nodo_e(v);
      else
      {
         actual=primero;
         while(actual->siguiente!=NULL)
         {
             actual=actual->siguiente;
             }
             nuevo=new nodo_e(v);
             actual->siguiente=nuevo;
      }
    }


int main()
{
    lista_doble LD;
    LD.Incluir_primero(8);
    LD.Incluir_primero(-1);
    LD.Incluir_primero(4);
    LD.Mostrar();
    cout<<" "<<endl;
    //LD.Borrar_primero();
    //LD.Borrar_ultimo();
    //LD.Mostrar();
    return 0;
}

