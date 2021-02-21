/*Clase Matriz
RAUL PINEDA SOTOMAYOR*/
#include "clasematriz.h"

istream& operator >> (istream& en,matriz &C)
{
    cout<<"Ingrese los elementos de la matriz por filas:"<<endl;
    for (int i=0;i<C.n;i++)
    {
        for (int j=0;j<C.m;j++)
        {
            en >> C.A[i][j];
        }
    }
    return en;
}
ostream& operator << (ostream& sa,matriz &C)
{
    for (int i=0;i<C.n;i++)
        {
            for (int j=0;j<C.m;j++)
                {
                   sa << C.A[i][j]<<" ";
                }
            cout << endl;
        }
}
matriz operator + (matriz C,matriz D)
{
    matriz S(C.n,C.m);
    if ((C.n!=D.n)||(C.m!=D.m))
    {
        cout<<"Matrices de distinta dimension"<<endl;
        return 0;
    }
    if ((C.n==D.n)&&(C.m==D.m))
    {
    for (int i=0;i<C.n;i++)
        {
            for (int j=0;j<C.m;j++)
                {
                    S.A[i][j]=C.A[i][j]+D.A[i][j];
                }
        }
    return S;
    }
}
matriz operator - (matriz C,matriz D)
{
    matriz S(C.n,C.m);
    if ((C.n!=D.n)||(C.m!=D.m))
    {
        cout<<"Matrices de distinta dimension"<<endl;
        return 0;
    }
    if ((C.n==D.n)&&(C.m==D.m))
    {
    for (int i=0;i<C.n;i++)
        {
            for (int j=0;j<C.m;j++)
                {
                    S.A[i][j]=C.A[i][j]-D.A[i][j];
                }
        }
    return S;
    }
}
matriz operator * (double x,matriz C)
{
    matriz S(C.n,C.m);
    for (int i=0;i<C.n;i++)
        {
            for (int j=0;j<C.m;j++)
                {
                    S.A[i][j]=x*C.A[i][j];
                }
        }
    return S;
}
matriz operator * (matriz C,matriz D)
{
    matriz S(C.n,D.m);
    if (C.m!=D.n)
    {
        cout<<"Matrices de distinta dimension"<<endl;
        return 0;
    }
    if (C.m==D.n)
    {
    for (int i=0;i<C.n;i++)
        {
            for (int j=0;j<D.m;j++)
            {
                for (int k=0;k<C.m;k++)
                {
                    S.A[i][j]=S.A[i][j]+(C.A[i][k]*D.A[k][j]);
                }
            }
        }
    return S;
    }
}
bool operator == (matriz C,matriz D)
{
    if ((C.n==D.n)&&(C.m==D.m))
    {
        for (int i=0;i<C.n;i++)
        {
            for (int j=0;j<C.m;j++)
            {
                if(C.A[i][j]==D.A[i][j]);
                else
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    return 0;
}
bool operator != (matriz C,matriz D)
{
    if ((C.n==D.n)&&(C.m==D.m))
    {
        for (int i=0;i<C.n;i++)
        {
            for (int j=0;j<C.m;j++)
            {
                if(C.A[i][j]==D.A[i][j]);
                else
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    else
    return 1;
}
double determinante(matriz C)
{
    double d;
    if (C.n!=C.m)
    {
        cout<<"La matriz no es cuadrada"<<endl;
        return 0;
    }
    if (C.n==C.m)
    {
        if (C.n==2&&C.m==2)
        {
            d=C.A[0][0]*C.A[1][1]-C.A[0][1]*C.A[1][0];
            return d;
        }
        if (C.n>2&&C.m>2)
        {
            matriz S(C.n-1,C.m-1);
            double a=1;
            for (int i=1;i<C.n-1;i++)
            {
                a=a*C.A[i][0];
            }
            for (int i=0;i<C.n-1;i++)
            {
                for (int j=0;j<C.m-1;j++)
                {
                    S.A[i][j]=C.A[i][0]*C.A[i+1][j+1]-C.A[i+1][0]*C.A[i][j+1];
                }
            }
            return (1/a)*determinante(S);
        }
    }
}
double traza(matriz C)
{
    double t=0;
    if (C.n!=C.m)
    {
        cout<<"La matriz no es cuadrada"<<endl;
        return 0;
    }
    if (C.n==C.m)
    {
        for (int i=0;i<C.n;i++)
            {
                t=t+C.A[i][i];
            }
        return t;
    }
}
matriz transpuesta(matriz C)
{
    matriz S(C.m,C.n);
    for (int j=0;j<C.m;j++)
    {
        for (int i=0;i<C.n;i++)
        {
            S.A[j][i]=C.A[i][j];
        }
    }
    return S;
}
matriz inversa(matriz C)
{
    if (C.n!=C.m)
    {
        cout<<"La matriz no es cudarada"<<endl;
        return 0;
    }
    else
    {
    matriz S(C.n),I(C.n),An(C.n),Bn(C.n),Am(C.n),Bm(C.n);
    double t;
    for (int i=1;i<=C.n;i++)
    {
        An=Bn*C;
        t=(-1)*(traza(An)/i);
        Bn=An+t*I;
    }
    for (int j=1;j<C.n;j++)
    {
        Am=Bm*C;
        t=(-1)*(traza(Am)/j);
        Bm=Am+t*I;
    }
    S=(C.n)/traza(An)*Bm;
    return S;
    }
}
bool simetrica(matriz C)
{
    matriz S(C.n,C.m);
    S=transpuesta(C);
    if (C==S)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
