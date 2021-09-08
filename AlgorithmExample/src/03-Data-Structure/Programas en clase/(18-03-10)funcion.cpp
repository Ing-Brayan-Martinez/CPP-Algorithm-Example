#include <iostream>
using namespace std;

double v_abs(double x)
{
    double x_abs;
    if(x<0)
    x_abs=x;
    else
    x_abs=-x;
    return x_abs;
}
void permutacion (int &x,int &y)
{
    int aux;
    aux=x;
    x=y;
    y=aux;
    }

int main()
{
   double x=-50,abs;
   abs=v_abs(x);
   cout<<abs<<endl;
   int a=-10,b=50;
   permutacion (a,b);
   cout<<"a= " <<a<<endl;
   cout<<"b= "<<b;

    return 0;
}
