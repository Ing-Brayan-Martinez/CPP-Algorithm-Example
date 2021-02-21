#include "funcion.h"

void V_absoluto(double x, double&y)
    {
    if (x>=0)
        y=x;
    else
        y=-1*x;
    }

void F_intervalo(double a, double b, double h)
    {
    double x;
    if (a<b)
        {
        cout<<"x"<<"\t"<<"f(x)"<<endl;
        for (int i=0;i<=(b-a)/h;i++)
            {
            x=a+i*h;
            cout<<x<<"\t"<<4*x*x-2*x+5<<endl;
            }
        }
    else
        cout<<"error"<<endl;
    }
