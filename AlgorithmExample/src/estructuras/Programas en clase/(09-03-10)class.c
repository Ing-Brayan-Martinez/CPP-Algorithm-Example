#include <iostream>

using namespace std;

class estudiante
{
      private:
              string Nombre;
              string Apellido;
              int edad;
              double peso;
              int semestre;
              public:
                     int sexo;
                     string Ext_Nombre()
                     {
                            return Nombre;
                            }
                            string Ext_Apellido()
                            {
                                   return Apellido;
                                   }
                                  int presentar_edad()
                                  {
                                   return edad;
                                   }
                                   //Constructor
                                   estudiante ()
                                   {
                                              Nombre="S/N";
                                              Apellido="S/A";
                                              edad=peso=semestre=-1;
                                              }
                                   estudiante (string N, int e)
                                   {
                                       Nombre=N;
                                   edad=e;
                                   Apellido="S/A";
                                   }
                                   };

int main()
{
    estudiante x;
    x.sexo=1;
    cout << "Nombre:" <<x.Ext_Nombre()<<endl;
    estudiante y("Ramiro",22);
    cout <<y.Ext_Nombre();
    return 0;
}
