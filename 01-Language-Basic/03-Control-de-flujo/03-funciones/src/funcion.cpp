#include "funcion.h"
void v_absoluto(double x, double &y)
{
if (x>0)
  y=x;
else
  y=-x;
  x=1000;
}

void F_intervalo (double a, double b, double h)
{
 double p;
  p=a;
  if (a<b && h>0)
  {
   cout << "x" << "\t" << "|" << "\t" << "f(x)" << endl;
   while(p<=b)
   {
    cout << p << "\t" << "|" << "\t" << 4*p*p-2*p+5 << endl;//f(x)=4*pow(x,2.0)-2*x+5 utilizando #include<cmath>
    p=p+h;
   }
  }
  else
   cout << "los datos no cumplen las condiciones de a<b o h>0" << endl;
}
