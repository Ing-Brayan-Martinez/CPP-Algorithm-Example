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
friend istream& operator >>(istream& is,R_2 &a);
friend R_2 operator * (R_2 a,R_2 b);
friend R_2 operator * (double k,R_2 a);

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
R_2 s;
s.x=a.x+b.x;
s.y=a.y+b.y;
return s;
    }

istream&operator >>(istream&is, R_2& a)
    {
        cout<<"Ingrese los datos de R_2"<<endl;
        cout<<"x= ";
        is>>a.x;
        cout<<"y= ";
        is>>a.y;
        return is;
        }
R_2 operator*(double k,R_2 a)
{
    R_2 b;
    b.x=k*a.x;
    b.y=k*a.y;
    return b;
    }

//programa
int main()
{
   R_2 a,b,s,m;
   cin >> a;
   cin >> b;
   s=a+b;
   m=3*a;
  cout<<s;
  cout<<m;
  ofstream fa;
   fa.open("Pares_ordenados.txt",ios::app);
   fa<<a << endl;
   fa<<s<<endl;
   fa<<m<<endl;
   fa.close();

    return 0;
}
