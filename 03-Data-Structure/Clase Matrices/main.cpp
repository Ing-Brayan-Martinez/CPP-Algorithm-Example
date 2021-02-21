/*Clase Matriz
RAUL PINEDA SOTOMAYOR*/
#include <iostream>
#include "clasematriz.h"

using namespace std;

int main()
{
    int n,m,n1,m1;
    double x,t,d;
    bool s;
    cout<<"Ingrese el numero de filas de la matriz A:"<<endl;
    cin>>n;
    cout<<"Ingrese el numero de columnas de la matriz A:"<<endl;
    cin>>m;
    matriz A(n,m),T(n,m),B(n,m),C(n,m),E(n,m);
    cin>>A;
    cout<<"La matriz A es:"<<endl;
    cout<<A;
    s=simetrica(A);
    if (s==1)
    {
        cout<<"La matriz A es simetrica"<<endl;
    }
    else
    {
        cout<<"La matriz A no es simetrica"<<endl;
    }
    cout<<"La matriz transpuesta de A es:"<<endl;
    T=transpuesta(A);
    cout<<T;
    cout<<"El determinate de la matriz A es"<<endl;
    d=determinante(A);
    cout<<d<<endl;
    cout<<"La traza de la matriz A es:"<<endl;
    t=traza(A);
    cout<<t<<endl;
    cout<<"La matriz inversa de A es:"<<endl;
    B=inversa(A);
    cout<<B;
    cout<<"Ingrese un numero real:"<<endl;
    cin>>x;
    C=x*A;
    cout<<"La matriz A multiplicada por "<<x<<" es igual a:"<<endl;
    cout<<C;
    cout<<"Ingrese el numero de filas de la matriz B:"<<endl;
    cin>>n1;
    cout<<"Ingrese el numero de columnas de la matriz B:"<<endl;
    cin>>m1;
    matriz D(n1,m1),F(n,m1),G(n1,m);
    cout<<"Ingrese la matriz B"<<endl;
    cin>>D;
    cout<<"La matriz B es:"<<endl;
    cout<<D;
    if(A==D)
    {
        cout<<"La matriz A es igual a B"<<endl;
    }
    if(A!=D)
    {
        cout<<"La matriz A no es igual a B"<<endl;
    }
    cout<<"La matriz suma de A con B es:"<<endl;
    E=A+D;
    cout<<E;
    cout<<"La matriz A menos B es:"<<endl;
    E=A-D;
    cout<<E;
    cout<<"El producto de A por B:"<<endl;
    F=A*D;
    cout<<F;
    cout<<"El producto de B por A:"<<endl;
    G=D*A;
    cout<<G;
    return 0;
}
