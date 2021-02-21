#include <iostream>
#include <cmath>
#include <fstream>
using namespace std; //dejarlo siempre para poder obtener el modo estandar

class R_2
{
private:
double x;
double y;
string Nombre;
public:
R_2()
{
    x=0;
    y=0;
    Nombre="S/N";
}
R_2(double x1, double y1, string s);
double Valor_x()
{
    return x;
}
double Valor_y ();
void mod_x(double x1);
void mod_y(double y1)
{
    y=y1;
    }
    double norma()
    {
        return sqrt(x*x+y*y);
        }
//operadores
friend ostream & operator<<(ostream & os, R_2&z);
friend R_2 operator+(R_2 a,R_2 b);
};

//funciones fuera de la clase
double R_2::Valor_y()
{
    return y;

}
void R_2::mod_x (double x1)
{
    x=x1;
    }
ostream & operator <<(ostream&os,R_2&z)
{
   os<<"("<<z.x<<","<<z.y<<")"<<endl;
   return os;
    }

R_2::R_2(double x1,double y1, string s)
{
   x=x1;
   y=y1;
   Nombre=s;
    }


R_2 operator+(R_2 a,R_2 b)
{
R_2 c;
c.x=a.x+b.x;
c.y=a.y+b.y;
return c;
    }

//programa
int main()
{
   R_2 a,b(4,-1,"pedro"),c;
   a.mod_x(-5);     //. nos permite acceder a una funcion especifica
   a.mod_y(4);
   cout<<a;
   c=a+b;
   cout<<c<<c.norma()

     << endl;
    return 0;
}
