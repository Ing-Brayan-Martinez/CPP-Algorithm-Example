/*Clase Matriz
RAUL PINEDA SOTOMAYOR*/
#ifndef CLASEMATRIZ_H_INCLUDED
#define CLASEMATRIZ_H_INCLUDED
#include <iostream>

using namespace std;

class matriz
{
    private:
        int n;
        int m;
        double **A;
    public:
        matriz(int dimension)
        {
            n=dimension;
            m=dimension;
            A=new double *[n];
            for (int i=0;i<n;i++)
            {
                A[i]=new double [m];
            }
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<m;j++)
                {
                    A[i][j]=0;
                    A[i][i]=1;
                }
            }
        }
        matriz(int filas,int columnas)
        {
            n=filas;
            m=columnas;
            A=new double *[n];
            for (int i=0;i<n;i++)
            {
                A[i]=new double [m];
            }
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<m;j++)
                {
                    A[i][j]=0;
                }
            }
        }
        friend istream& operator >> (istream& en,matriz &C);
        friend ostream& operator << (ostream& sa,matriz &C);
        friend matriz operator + (matriz C,matriz D);
        friend matriz operator - (matriz C,matriz D);
        friend matriz operator * (double x,matriz C);
        friend matriz operator * (matriz C,matriz D);
        friend bool operator == (matriz C,matriz D);
        friend bool operator != (matriz C,matriz D);
        friend double determinante(matriz C);
        friend double traza(matriz C);
        friend matriz transpuesta(matriz C);
        friend matriz inversa(matriz C);
        friend bool simetrica(matriz C);
};
#endif // CLASEMATRIZ_H_INCLUDED
