#include <iostream>
#include <list>
#include <vector>

using namespace std;

class nodo
{
    private:
        int indice;
        double valor;
        nodo *padre;
        nodo *izq;
        nodo *der;
        friend class arbol_binario;
    public:
        nodo(int id,double v)
        {
            indice=id;
            valor=v;
            padre=izq=der=NULL;
        }
        friend ostream&operator<<(ostream& sa,nodo &A);
};
ostream&operator<<(ostream& sa,nodo &A)
{
    cout<<"nodo: ";
    sa<<A.indice;
    cout<<", valor: ";
    sa<<A.valor;
    if(A.padre==NULL)
        cout<<", RAIZ";
    else
    {
        cout<<", padre:(id= ";
        sa<<A.padre->indice;
        cout<<",v= ";
        sa<<A.padre->valor;
        cout<<")";
    }
    if(A.izq==NULL&&A.der==NULL)
        cout<<", HOJA"<<endl;
    else
    {
        cout<<", izq:(id= ";
        sa<<A.izq->indice;
        cout<<",va= ";
        sa<<A.izq->valor;
        cout<<")";
        if(A.der==NULL)
            cout<<endl;
        else
        {
            cout<<", der:(id= ";
            sa<<A.der->indice;
            cout<<",va= ";
            sa<<A.der->valor;
            cout<<")"<<endl;
        }
    }
}
class arbol_binario:public list<nodo>
{
    private:
        nodo *raiz;
        nodo *actual;
    public:
        arbol_binario()
        {
            actual=NULL;
        }
        nodo crear_izq(nodo *A,int id,double v);
        nodo crear_der(nodo *A,int id,double v);
        list<nodo> construir(vector<double> V);
        //friend istream&operator<<(istream& en,arbol_binario &G);
        //friend ostream&operator<<(ostream& sa,arbol_binario &G);
};
nodo arbol_binario::crear_izq(nodo *A,int id,double v)
{
    nodo *nuevo;
    nuevo=new nodo(id,v);
    A->izq=nuevo;
    nuevo->padre=A;
    return *nuevo;
}
nodo arbol_binario::crear_der(nodo *A,int id,double v)
{
    nodo *nuevo;
    nuevo=new nodo(id,v);
    A->der=nuevo;
    nuevo->padre=A;
    return *nuevo;
}
list<nodo> arbol_binario::construir(vector<double> V)
{
    int j;
    list<nodo> L;
    list<nodo> T;
    list<nodo>::iterator it;
    nodo *nuevo, *actual_izq, *actual_der;
    nuevo=new nodo(1,V[0]);
    raiz=nuevo;
    actual=nuevo;
    L.push_back(*actual);
    for(int i=0;i<V.size();i++)
    {
        j=i+1;
        if(2*j<=V.size())
        {
            actual_izq=&crear_izq(actual,2*j,V[2*j-1]);
            L.push_back(*actual_izq);
        }
        if(2*j+1<=V.size())
        {
            actual_der=&crear_der(actual,2*j+1,V[2*j]);
            L.push_back(*actual_der);
        }
        if(actual->indice=j)
        {
            T.push_back(*actual);
        }
        for(it=L.begin();it!=L.end();it++)
        {
            if(it->indice==j+1)
            {
                if(it->indice%2==0)
                {
                    actual=it->padre->izq;
                }
                else
                {
                    actual=it->padre->der;
                }
            }
        }
    }
    return T;
}
/*ostream&operator<<(ostream& sa,arbol_binario &G)
{
    list<nodo>G;
    list<nodo>::iterator it;
    for(it=G.begin();it!=G.end();it++)
    {
        sa<<*it;
    }
}*/
int main()
{
    int n;
    cout<<"Ingrese el numero de nodos"<<endl;
    cin>>n;
    vector<double> V(n);
    list<nodo> L;
    list<nodo>::iterator it;
    arbol_binario G;
    //cin>>G;
    cout<<"Ingrese los valores de los nodos"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>V[i];
    }
    L=G.construir(V);
    cout<<"El arbol binario es"<<endl;
    for(it=L.begin();it!=L.end();it++)
    {
        cout<<*it;
    }
    //cout<<G;
    return 0;
}
