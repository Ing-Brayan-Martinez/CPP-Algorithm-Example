#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void escritura (int *x, int n)
{
    for (int i=0 ; i<n ; i++)
    x[i]=rand()%21-10;
}

void frecuencia (int *x, int n, int *y)
{
int j;
 for (int i=0 ; i<21 ; i++)
  y[i]=0;
 for (int i=0 ; i<n ; i++)
  {
  j=x[i]+10;
  y[j]=y[j]+1;
  }
}

int main()
{
int *x , n , *y, p;
p=0;
cout << "Ingrese el tama�o del arreglo " << endl;
cin >> n;
x = new int [n];
y = new int [21];
escritura (x , n);
frecuencia (x, n, y);
ofstream fa;
fa.open("Frecuencias.txt");
for (int i=0 ; i<n ; i++)
fa <<  i+1 << "\t" << x[i] << endl;
fa << "Frecuencias" << endl;
for (int i=0 ; i<21 ; i++)
{
    fa << i-10 << "\t" << y[i] << endl;
    p=p+y[i];
}
fa << "Numero de datos " << p;
fa.close();

    return 0;
}
