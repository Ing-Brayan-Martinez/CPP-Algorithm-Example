#include <iostream>

using namespace std;

int main()
{
    double*x,*p;
    int n;
    cout<<"ingrese el número de componentes n=";
    cin>>n;
    x=new double[n];
    cout<<"ingrese las componentes"<<endl;
    for (int i=0;i<n;i++)
        cin>>x[i];
    cout<<endl<<"los datos ingresados son:"<<endl;
    p=x;
    for (int i=0;i<n;i++)
        {
        cout<<*p<<endl;
        p++;
        }
    *p=100;
    p++;
    *p=-100;
    p=x;
    for (int i=0;i<n+2;i++)
        cout<<x[i]<<" ";

    return 0;
}
