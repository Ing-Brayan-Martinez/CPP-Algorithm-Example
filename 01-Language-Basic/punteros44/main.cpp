#include <iostream>

using namespace std;

double v_abs (double x)
{
 double x_abs;
 if (x>0)
 x_abs=x;
 else
  x_abs=-x;
  return x_abs;
}
void permutacion (int & x, int & y)
//si escribimos asi void permutacion (int x, int y) no retorna los datos
//con los & trabaja con las direccones cea una copia no manipula lavariable
{
int aux;
aux=x;
x=y;
y=aux;
}

int main()
{double x=-50, abs;
 abs=v_abs(x);
 cout<< abs << endl;
 int a=-10, b=50;
 permutacion (a,b);
 cout<< "a= " << a << endl;
 cout<< "b= " << b << endl;
    return 0;
}
