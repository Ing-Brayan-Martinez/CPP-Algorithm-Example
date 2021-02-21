#include <iostream>
#include <list>

using namespace std;

list<double> lectura()
{
    list<double> L;
    double v;
    do
    {
        cout<<"Ingrese el valor "<<endl;
        cin>>v;
        if(v!=-1)
        L.push_front(v);
    }
    while(v!=-1);
    return L;
}
void presentar(list<double> L)
{
    list<double>::iterator it;
    for(it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" ";
    }
}
list<double> seleccion(list<double> L)
{
    list<double>T;
    list<double>::iterator it,et,at;
    double min;
    while(L.size()!=0)
    {
        it=L.begin();
        at=it;
        min=*it;
        for(et=L.begin();et!=L.end();et++)
        {
            if(*et<min)
            {
                min=*et;
                at=et;
            }
        }
        L.erase(at);
        T.push_back(min);
    }
    return T;
}
int main()
{
    list<double> L;
    list<double> T;
    double v;
    /*do
    {
        cout<<"Ingrese el valor "<<endl;
        cin>>v;
        if(v!=-1)
        L.push_front(v);
    }
    while(v!=-1);*/
    L=lectura();
    cout<<"La lista que ingreso es:"<<endl;
    presentar(L);
    cout<<endl;
    cout<<"La lista ordenada es:"<<endl;
    T=seleccion(L);
    presentar(T);
    return 0;
}
