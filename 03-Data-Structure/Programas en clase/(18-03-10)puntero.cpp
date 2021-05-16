#include <iostream>

using namespace std;

int main()
{
   /* char a[8]="prueba";
    char*p;
    p=a;
    cout<<*p<<" "<<a;
    p++; // q salga la siguiente letra //p+=3 sale la letra e
    cout<<*p;  */

  // Arreglo Bidimensional
   double **Matriz;
   Matriz=new double*[10];
   for(int i=0;i<10;i++)
   Matriz[i]=new double[15];
   for(int i=0;i<10;i++)
   {
       for (int j=0;j<15;j++)
       {
           Matriz [i][j]=i+j;
           cout<<Matriz[i][j]<<" ";
           }
    cout<<endl;
   }

for(int i=0;i<10;i++)
delete[] Matriz[i];
delete[] Matriz;


    return 0;
}
