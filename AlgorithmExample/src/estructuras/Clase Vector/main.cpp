#include "clasevector.h"

int main()
{
    int n,m;
    double x,r,p;
    cout<<"Ingrese la dimension del vector A:"<<endl;
    cin>>n;
    vector A(n),S(n),R(n),P(n);
    cin>>A;
    cout<<"El vector A que ingreso es:"<<endl;
    cout<<A;
    cout<<"La norma del vector A es:"<<endl;
    r=norma(A);
    cout<<r<<endl;
    cout<<"Ingrese un numero real:"<<endl;
    cin>>x;
    P=x*A;
    cout<<"El producto de "<<x<<" por el vector A es:"<<endl;
    cout<<P;
    cout<<"Ingrese la dimension del vector B:"<<endl;
    cin>>m;
    vector B(m);
    cin>>B;
    cout<<"El vector B que ingreso es:"<<endl;
    cout<<B;
    if(A==B)
    cout<<"La vector A es igual al vector B"<<endl;
    if(A!=B)
    cout<<"La vector A no es igual al vector B"<<endl;
    cout<<"El producto punto de A por B es:"<<endl;
    p=punto(A,B);
    cout<<p<<endl;
    cout<<"El vector suma de A mas B es:"<<endl;
    S=A+B;
    cout<<S;
    cout<<"El vector resta de A menos B es:"<<endl;
    R=A-B;
    cout<<R;




    cout << "Hello world!" << endl;
    return 0;
}
