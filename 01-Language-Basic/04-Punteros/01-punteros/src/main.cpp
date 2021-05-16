#include <iostream>

using namespace std;

int main() {

double *x, *p, *q, y;

y=8;
x=new double[3];//p y q punturos
q=&y;//apunta a la direccion de y
p=x;//apunta a x ubica 1ra casilla
*p=*q+1;// 1ra casilla =9
p++;
*q=y-6;//y ahora vale 2
*p=x[0]+2;//2da casilla vale 9+2=11
x[2]=x[1]+x[0]-y;//20 -2 =18


}
