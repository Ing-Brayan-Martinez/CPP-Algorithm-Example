#include <iostream>

using namespace std;

class nodo
{
    private:
    double valor;
    nodo *siguiente;
    public:
    nodo(double v, nodo*sig=NULL)
    {
        valor=v;
        siguiente=sig;
        }
        friend class lista_simple;
};


 class lista_simple
 {
     private:
     nodo *primero;
     nodo *actual;
     public:
     lista_simple()
     {primero=actual=NULL;}
     void siguiente();
     /*void primero();
     void ultimo();
     bool esta_vacia();*/
     void Incluir_primero(double v);
     //void Incluir_ultimo(double v);
 };
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
  }




int main()
{
    lista_simple L ;
    L.Incluir_primero(4);
    L.Incluir_primero(6);
    return 0;
}
