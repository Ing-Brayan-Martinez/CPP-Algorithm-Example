#include <iostream>

using namespace std;

int main()
{
    int x=4, *p;
    p=&x;
    cout << *p << endl;
    *p=10;
    cout << x << endl;
    char a[8]="Prueba";
    char *q;
    q=a;
    cout << *q << " " << a << endl;
    q++;
    // el operador mas incrementael punteroala siguiente direccion
    cout << *q << " " << a << endl;
    q+=1;
    cout << *q << " " << a << endl;
    double ** matriz;
    matriz = new double *[10];//10 filas
     for(int i=0; i<10 ; i++)
      matriz [i] = new double [15];
       for(int i=0; i<10 ; i++)
         {
             for(int j=0; j<15 ; j++)
             {
                 matriz[i][j]=i+j;
                 cout << matriz[i][j] << "\t";
             }
             cout << endl;
         }
       for(int i=0; i<10 ; i++)
        delete [] matriz[i];
        delete matriz;
    return 0;
}
