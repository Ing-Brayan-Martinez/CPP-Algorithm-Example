#include <iostream>
#include <list>
using namespace std;

class nodo
{
    private:
    double dato;
    int indice;
    nodo *padre;
    nodo *izq;
    nodo *der;

    public:
    nodo (double valor ,nodo *derecho=NULL ,nodo *izquierdo=NULL , nodo *padre=NULL)
    {
        dato=valor;
    }
};

void escribir (list<double> L)
{
    list <double>::iterator it;
    int i=1;
    for (it=L.begin();it!=L.end();it++)
    {
        cout<<"L["<<i<<"]:"<<*it<<endl;
        i=i+1;
    }
}

list<double> leer ()
{
    list<double> L;
    bool t=true;
    double v;
    cout<<"Ingrese los valores de la lista L"<<endl;
    while (t==true)
    {
        cin>>v;
        if (v<=0)
        {
            if (v==-1)
            t=false;
            else
            cout<<"Los valores deben ser reales positivos"<<endl;
        }
        else
        L.push_back(v);
    }
    return L;



list<double> ordenar (list<double>L)
{
    list<double>U;
    list<double>::iterator it;
    list<double>::iterator at;
    double p=-1,s;
    for (it=L.begin();it!=L.end();it++)
    {
        if (*it>p)
        p=*it;
    }

    for(int i=0;i<L.size();i++)
    {
        s=p;
        for (it=L.begin();it!=L.end();it++)
        {
            if(*it<=s)
            {
                s=*it;
                at=it;
            }
        }
        U.push_front(s);
        *at=p;
    }
    return U;
}

int main()
{
    list<double>L,U;
    L=leer();
    U=ordenar(L);
    escribir(U);

    return 0;
}
