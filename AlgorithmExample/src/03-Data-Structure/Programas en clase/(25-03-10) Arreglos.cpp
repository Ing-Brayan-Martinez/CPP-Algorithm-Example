#include <iostream>
using namespace std;
int main()
{
    double *x,*p;
    int n;
    cin>>n;
    x=new double[n];
    for (int i=0;i<n;i++)
    cin>>x[i];
    cout<<"Los datos ingresados son: "<<endl;
    p=x;
    for(int j=0;j<n;j++)
    {
    cout <<*p << endl;
    p++;
    }
    *p=100; // se crea 2 direcciones mas
    p++;
    *p=-100;
    p=x;
    for(int i=0;i<n+2;i++)
    cout<<x[i]<<" "; // retorna los valores de 100 y -100

    return 0;
}
