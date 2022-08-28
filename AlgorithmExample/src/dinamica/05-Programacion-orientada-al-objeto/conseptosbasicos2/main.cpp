#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class R_2
{
private:
 double x;
 double y;
 string Nombre;
public:
//constructores
 R_2()
  {
  x=0;
  y=0;
  Nombre="s/n";
  }
 R_2(double x1, double y1, string s)
 {
  x=x1;
  y=y1;
  Nombre=s;
 }
 double valor_x()
 {
  return x;
 }
 double valor_y();
  void mod_x(double x1);
  void mod_y(double y1)
  {
   y=y1;
  }
 double norma()
 {
 return sqrt(x*x+y*y);
 }
//Operadores
 friend ostream & operator << (ostream & os, R_2 & z);
 friend R_2 operator + (R_2 & a, R_2 & b);
};
//escribir funciones a fuera dela clase
 double R_2 :: valor_y()
 {
  return y;
 }
 void R_2:: mod_x(double x1)
 {
  x=x1;
 }
ostream & operator << (ostream & os, R_2 & z)
{
 os << "(" << z.x << "," << z.y << ")" << endl;
 return os;
}
R_2 operator + (R_2 & a, R_2 & b)
{
R_2 c;
c.x=a.x+b.x;
c.y=a.y+b.y;
return c;
}


int main()
{
 double d;
 R_2 a, b(4,-1,"s1"), c;
 a.mod_x(-5);
 a.mod_y(4);
 cout << a << endl;
 cout << b << endl;
 c=a+b;
 cout << c;
 cin >> d;
 a.mod_x(d);
  c=a+b;
 cout << c;
 cout << c << c.norma();
    return 0;
}

