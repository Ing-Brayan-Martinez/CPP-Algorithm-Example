#include <iostream>

using namespace std;
class matry
{
protected://permite accesos a la clase heredad y permite accder a las variables privadas desde el ambiente de herencia
int n;
int m;

public:
double **A;
matry (int f, int c)
{
m=f;
n=c;
A=new double *[m];//creo la priemra dimension del arreglo las filas, se le baja la dimension por eso *
for(int i=0;i<m;i++)
    A[i]=new double[n];
}
};

class Sist_Lineal:public matry//Herencia, no accede a funciones amigas
{
private:
string *V;//vector de palabras , nombre de la variable

public:
int k;
double *b;//Ax=b

Sist_Lineal(int a, int a1):matry (a,a1)//filas y columnas, despues de :llamado del constructor de la clase previa
{
V=new string[a1];//nombres x1 x2
b=new double[a];//los valores
k=n+m;
}
};

Sist_Lineal (const string Nombre):Matry(Nombre)
{
V=new string[n];
b=new double[m];
}

int main()
{
Sist_Lineal SL(2,3);//genera los espacios vacios de la matriz.
SL.A[0][0]=4;//se puede escribir los valores de la matriz a11=4
//cout<<SL.n_cal()<<endl;//me da numero de filas
//cout<<SL.m;
}
