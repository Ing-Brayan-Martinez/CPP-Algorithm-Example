#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class nodo
{
private:
double valor;
int padre;
int izq;
int der;
public:
nodo(double val=-1, int pa=-1, int iz=-1, int de=-1)
{
valor=val;
padre=pa;
izq=iz;
der=de;
}
friend class priority_queue;
};

class priority_queue: public vector <nodo>
{
private:
int heap_size;
public:
priority_queue()
{
heap_size=0;
}
void leer(priority_queue&A)
{
ifstream f;
double x;
f.open("ordenar_2.txt");
f>>x;
A.resize(x);
A.heap_size=x;
f>>A[0].valor;
A[0].izq=2;
A[0].der=3;
for (int i=2;i<=A.size();i++)
{
f>>A[i-1].valor;
A[i-1].padre=i/2;
A[i-1].izq=2*i;
A[i-1].der=(2*i)+1;
}
f.close();
A.mostrar(A,1);
BUILD_MAX(A);
}
void mostrar(priority_queue A, int i)
{
if (i==1)
{
ofstream of;
of.open("grafo1.txt");
of<<"INDICE"<<"\t"<<"VALOR"<<"\t"<<"PADRE"<<"\t"<<"IZQ"<<"\t"<<"DER"<<endl;
for (int i=0;i<A.heap_size;i++)
of<<i+1<<"\t"<<A[i].valor<<"\t"<<A[i].padre<<"\t"<<A[i].izq<<"\t"<<A[i].der<<endl;
}
if (i==2)
{
ofstream of;
of.open("grafo2.txt");
of<<"INDICE"<<"\t"<<"VALOR"<<"\t"<<"PADRE"<<"\t"<<"IZQ"<<"\t"<<"DER"<<endl;
for (int i=0;i<A.heap_size;i++)
of<<i+1<<"\t"<<A[i].valor<<"\t"<<A[i].padre<<"\t"<<A[i].izq<<"\t"<<A[i].der<<endl;
}
if (i==3)
{
ofstream of;
of.open("grafo3.txt");
of<<"INDICE"<<"\t"<<"VALOR"<<"\t"<<"PADRE"<<"\t"<<"IZQ"<<"\t"<<"DER"<<endl;
for (int i=0;i<A.heap_size;i++)
of<<i+1<<"\t"<<A[i].valor<<"\t"<<A[i].padre<<"\t"<<A[i].izq<<"\t"<<A[i].der<<endl;
}
}
void intercambiar(nodo&A, nodo&B)
{
double C=A.valor;
A.valor=B.valor;
B.valor=C;
}
void MAX_HEAPIFY(priority_queue&A,  int i)
{
int l,r,largest;
l=A[i-1].izq;
r=A[i-1].der;
if ((l<=A.heap_size)&&(A[l-1].valor>A[i-1].valor))
largest=l-1;
else
largest=i-1;
if ((r<=A.heap_size)&&(A[r-1].valor>A[largest].valor))
largest=r-1;
if (largest!=(i-1))
{
intercambiar(A[i-1],A[largest]);
MAX_HEAPIFY(A,largest+1);
}
}
void BUILD_MAX(priority_queue&A)
{
A.heap_size=A.size();
for (int i=A.size()/2;i>0;i--)
MAX_HEAPIFY(A,i);
}
double HEAP_MAXIMUM(priority_queue&A)
{
return A[0].valor;
}
double HEAP_EXTRACT_MAX(priority_queue&A)
{
double max;
if (A.heap_size<1)
cout<<"error: heap underflow";
else
{
max=A[0].valor;
A[0].valor=A[A.heap_size-1].valor;
A.heap_size=A.heap_size-1;
MAX_HEAPIFY(A,1);
return max;
}
}
void HEAP_INCREASE_KEY(priority_queue&A, int i, double key)
{
if (key<A[i-1].valor)
cout<<"error: el nuevo valor es menor que el actual"<<endl<<endl;
else
{
A[i-1].valor=key;
while ((i>1)&&(A[A[i-1].padre-1].valor<A[i-1].valor))
{
intercambiar(A[i-1],A[A[i-1].padre-1]);
i=A[i-1].padre;
}
}
}
void MAX_HEAP_INSERT(priority_queue&A, double key)
{
A.heap_size=A.heap_size+1;
if (A.heap_size<=A.size())
{
A[A.heap_size-1].valor=-100000;
HEAP_INCREASE_KEY(A,A.heap_size,key);
}
else
{
A.resize(A.heap_size);
A[A.heap_size-1].valor=-100000;
HEAP_INCREASE_KEY(A,A.heap_size,key);
}
}
};

int main()
{
    priority_queue A;
    int i=1;
    cout<<"ARBOL ANTES DE ORDENAR: grafo1.txt"<<endl<<endl;
    i++;
    A.leer(A);
    cout<<endl<<endl<<"ARBOL DESPUES DE ORDENAR: grafo2.txt"<<endl<<endl;
    A.mostrar(A,i);
    cout<<endl;
    cout<<"MAXIMO: "<<A.HEAP_MAXIMUM(A);
    cout<<endl<<endl;
    cout<<"MAXIMO EXTRAIDO: "<<A.HEAP_EXTRACT_MAX(A);
    cout<<endl<<endl;
    A.HEAP_INCREASE_KEY(A,1,18900);
    A.MAX_HEAP_INSERT(A,24);
    cout<<"NUEVO MAXIMO: "<<A.HEAP_MAXIMUM(A);
    i++;
    cout<<endl<<endl<<"ARBOL DESPUES DE LAS OPERACIONES: grafo3.txt"<<endl<<endl;
    A.mostrar(A,i);
    cout<<endl;

    return 0;
}
