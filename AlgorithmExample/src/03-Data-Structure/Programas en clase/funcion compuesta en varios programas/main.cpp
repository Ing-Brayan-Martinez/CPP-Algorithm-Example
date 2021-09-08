#include <iostream>
#include "funcion.h"

using namespace std;
int main()
{
    double a,b,h;
    cout<<"a=";
    cin>>a;
    cout<<endl<<"b=";
    cin>>b;
    cout<<endl<<"h=";
    cin>>h;
    cout<<endl;
    F_intervalo(a,b,h);

    return 0;
}
