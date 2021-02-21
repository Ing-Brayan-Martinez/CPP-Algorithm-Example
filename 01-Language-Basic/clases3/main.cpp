#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class R_2
{
private:
 double x;
 double y;
public:
//constructores
 R_2()
  {
  x=0;
  y=0;
  }
  double valor_x()
  {
  return x;
  }
  void mod_x(double x1);
  friend istream & operator >> (istream & is, R_2 & a);//datos entrada
  friend ostream & operator << (ostream & os, R_2 & z);//datos salida
  friend R_2 operator * (double k, R_2 a);//multiplicar por un k
  friend R_2 operator + (R_2 & a, R_2 & b);
};

void R_2::mod_x (double x1)
 {
 x=x1;
 }

istream & operator >> (istream & is, R_2 & a)//ingreso las componentes del vector x,y
 {
 cout << "Ingrese los datos de R_2" << endl;
 cout << "x= ";
 is >> a.x;
 cout << "y= ";
 is >> a.y;
 return is;
 }

R_2 operator * (double  k, R_2  a)//vector a.x y a.y multiplicado por la constante k
{
 R_2 b;
 b.x=k*a.x;
 b.y=k*a.y;
 return b;
}
R_2 operator + (R_2 & a, R_2 & b)//suma de las componente x y las y
{
R_2 c;
c.x=a.x+b.x;
c.y=a.y+b.y;
return c;
}
ostream & operator << (ostream & os, R_2 & z)
{
 os << "(" << z.x << "," << z.y << ")" << endl;
 return os;
}
int main()
{
 R_2 a, b, s, m;
 cin >> a;
 //a.mod_x(10); funcion perteneciente unicamente a la clase
 cin >> b;
 s=a+b;//suma de los 2 vectores ingresados
 m=3*a;//multiplica al primer vector por 3
 cout << s;
 cout << m;
 //@include<fstream> abre un archivo
 ofstream fa;
 //ios::app estopermite que se vaya al ultimo del archivo y escriba
 fa.open("Pares_ordenados.txt",ios::app);
 fa << a << endl;
 fa << s << endl;
 fa << m << endl;
 fa.close();
 return 0;
}
