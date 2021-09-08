/*Funciones para Matrices
  RAUL PINEDA SOTOMAYOR*/
#include <iostream>

using namespace std;

double tz(int n,double **matriz)//TRAZA
{
    double t=0;
    for (int i=0;i<n;i++)
    {
        t=t+matriz[i][i];
    }
    return t;
}
void tr(int n,double **matriz)//TRANSPUESTA
{
    for (int j=0;j<n;j++)
        {
            for (int i=0;i<n;i++)
                {
                    cout << matriz[i][j]<<" ";
                }
            cout <<endl;
        }
}
void pr(int n,double **matriz)//PRESENTAR MATRIZ
{
    for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                {
                    cout << matriz[i][j]<<" ";
                }
            cout <<endl;
        }
}
void le(int n,double **matriz)//LEER MATRIZ
{
    for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    cin >> matriz[i][j];
                }
            }
}
  /*for (int k=0;k<C.n-1;k++)
            {
                for (int h=0;h<C.m-1;h++)
                {
                    for (int i=0;i<C.n;i++)
                    {
                        for (int j=0;j<C.m;j++)
                        {
                            S.A[k][h]=(C.A[i][0]*C.A[i+1][j+1]-C.A[i+1][0]*C.A[i][j+1]);
                        }
                    }
                }
            }*/
int main()
{
    double **matriz;
    int n;
    cout <<"Ingrese la dimension de la matriz: "<<endl;
    cin >> n;
    {matriz = new double *[n];//CREA ARREGLO DINAMICO PARA LA MATRIZ
        for (int i=0;i<n;i++)
            {
                matriz [i]=new double [n];
            }
    }
    cout <<"Ingrese las valores de la matriz por filas: "<<endl;
    le(n,matriz);
    cout <<"La matriz que ingreso es: "<<endl;
    pr(n,matriz);
    cout <<"La matriz transpuesta a la que ingreso es:"<<endl;
    tr(n,matriz);
    cout <<"La traza de la matriz que ingreso es igual a: "<<endl;
    cout<<tz(n,matriz)<<endl;
    {for (int i=0;i<n;i++)//LIBERA EL ESPACIO USADO POR EL ARREGLO DINAMICO DONDE SE ENCINTRABA LA MATRIZ
    {
        delete []matriz[i];
    }
    delete []matriz;}
    return 0;
}
