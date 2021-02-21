#include <iostream>

using namespace std;

int main()
{
/*
double V[5];
double *p;
p=V;//apunta a la cabeza del arreglo
cout<<*p;//esta vacia
p++;
cout<<*p;//suma 1 casilla tambien esta vacia
p=V;//apunta nuevamente a la cabeza del arreglo
*p=-11;
cout<<" "<<V[0];
//imprime vacio vacio -11
*/
double *x, *p, *q;
y=8;
x=new double[3];//p y q punturos
q=&y;//apunta a la direccion de y
p=x;//apunta a x ubica 1ra casilla
*p=*q+1;// 1ra casilla =9
p++;
*q=y-6;//y ahora vale 2
*p=x[0]+2;//2da casilla vale 9+2=11
x[2]=x[1]+x[0]-y;//20 -2 =18
//(9,11,18)
}
