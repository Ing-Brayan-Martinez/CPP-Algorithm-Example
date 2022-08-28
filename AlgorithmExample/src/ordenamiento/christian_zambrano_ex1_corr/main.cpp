#include <iostream>
#include <list>
#include <vector>

using namespace std;

void leer_lista (list<double>&L)
    {
    cout<<"ingrese lo valores reales positivos de la lista. Para finalizar ingrese -1."<<endl<<endl;
    double x=0;
    bool t=true;
    while (t==true)
        {
        cin>>x;
        if (x>=-1)
            {
            if (x!=-1)
                L.push_back(x);
            else
                t=false;
            }
        else
            cout<<"valor no ingresado"<<endl;
        }
    }

void ordenar_lista (list<double>&L)
    {
    list<double>::iterator it1;
    list<double>::iterator it2;
    list<double>::iterator it3;
    double min;
    double aux;
    for (it1=L.begin();it1!=L.end();it1++)
        {
        min=100000;
        for (it2=it1;it2!=L.end();it2++)
            {
            if (*it2<min)
                {
                min=*it2;
                it3=it2;
                }
            }
        aux=*it1;
        *it1=*it3;
        *it3=aux;
        }
    }

void escribir_lista(list<double> L)
    {
    cout<<endl<<endl;
    list<double>::iterator it;
    for (it=L.begin();it!=L.end();it++)
        cout<<*it<<endl;
    }

class nodo
    {
    private:
        double dato;
        int indice;
        nodo *padre;
        nodo *izq;
        nodo *der;
    public:
        nodo()
            {
            dato=0;
            indice=0;
            padre=NULL;
            izq=NULL;
            der=NULL;
            }
        void modificar(double dat, int ind, nodo* padr=NULL, nodo* izqu=NULL, nodo* dere=NULL)
            {
            dato=dat;
            indice=ind;
            padre=padr;
            izq=izqu;
            der=dere;
            }
        friend ostream&operator<<(ostream&os, nodo v)
            {
            os<<"(nodo "<<v.indice<<": ";
            if (v.padre!=NULL)
                os<<"p="<<v.padre->dato;
            if ((v.izq->dato)>1e-300)
                os<<",\tizq="<<v.izq->dato;
            if ((v.der->dato)>1e-300)
                os<<",\tder= "<<v.der->dato;
            os<<")";
            return os;
            }
   };

void crear_arbol(vector<nodo>&A, list<double> L)
            {
            A.resize(L.size());
            list <double>::iterator it;
            int j=0;
            for (it=L.begin();it!=L.end();it++)
                {
                A[j].modificar(*it,j+1);
                j++;
                }
            int padr,izqui,dere;
            A[0].modificar(L.front(),1,NULL,&A[1],&A[2]);
            it=L.begin();
            it++;
            for (int i=1;i<A.size();i++)
                {
                if (((i+1)%2)==0)
                    padr=((i+1)/2)-1;
                else
                    padr=(i-2)/2;
                izqui=(2*(i+1))-1;
                dere=((2*(i+1))+1)-1;
                A[i].modificar(*it,i+1,&A[padr],&A[izqui],&A[dere]);
                it++;
                }
            }

void escribir_arbol(vector<nodo> A)
            {
            cout<<endl<<endl;
            for (int i=0;i<A.size();i++)
                cout<<A[i]<<endl;
            }

int main()
{
    list<double> L;
    list<double> LG;
    leer_lista(L);
    LG=L;
    ordenar_lista(L);
    cout<<endl<<endl<<"Ejercicio 3";
    cout<<endl<<endl<<"la lista ordenada es:";
    escribir_lista(L);

    vector<nodo> A;
    crear_arbol(A,LG);
    cout<<endl<<endl<<"Ejercicio 4";
    cout<<endl<<endl<<"el grafo a partir de la lista inicial es:";
    escribir_arbol(A);

    return 0;
}
