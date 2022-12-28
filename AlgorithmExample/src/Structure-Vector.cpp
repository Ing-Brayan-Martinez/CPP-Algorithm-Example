#include "Structure-Vector.h"

istream& operator >> (istream& en,vector &V)
{
    cout<<"Ingrese los elementos del vector:"<<endl;
    for (int i=0;i<V.n;i++)
    {
        en >> V.A[i];
    }
    return en;
}
ostream& operator << (ostream& sa,vector &V)
{
    for (int i=0;i<V.n;i++)
    {
        sa << V.A[i]<<" ";

    }
    cout << endl;
}
vector operator + (vector V,vector U)
{
    vector W(V.n);
    if (V.n!=U.n)
    {
        cout<<"Los vectores son de distinta dimension"<<endl;
        return 0;
    }
    else
    {
        for (int i=0;i<V.n;i++)
        {
            W.A[i]=V.A[i]+U.A[i];
        }
        return W;
    }
}
vector operator - (vector V,vector U)
{
    vector W(V.n);
    if (V.n!=U.n)
    {
        cout<<"Los vectores son de distinta dimension"<<endl;
        return 0;
    }
    else
    {
        for (int i=0;i<V.n;i++)
        {
            W.A[i]=V.A[i]-U.A[i];
        }
        return W;
    }
}
vector operator * (double x,vector V)
{
    vector W(V.n);
    for (int i=0;i<V.n;i++)
    {
        W.A[i]=x*V.A[i];
    }
    return W;
}
bool operator == (vector V,vector U)
{
    if (V.n==U.n)
    {
        for (int i=0;i<V.n;i++)
        {
            if(V.A[i]==U.A[i]);
            else
            return 0;
        }
        return 1;
    }
    else
    return 0;
}
bool operator != (vector V,vector U)
{
    if (V.n==U.n)
    {
        for (int i=0;i<V.n;i++)
        {
                if(V.A[i]==U.A[i]);
                else
                return 1;
        }
        return 0;
    }
    else
    return 1;
}
double norma(vector V)
{
    vector W(V.n);
    double s,t=0;
    for (int i=0;i<V.n;i++)
    {
        W.A[i]=V.A[i]*V.A[i];
        t=t+W.A[i];
    }
    s=sqrt(t);
    return s;
}
double punto(vector V,vector U)
{
    vector W(V.n);
    double t=0;
    if (V.n!=U.n)
    {
        cout<<"Los vectores son de distinta dimension"<<endl;
        return 0;
    }
    else
    {
        for (int i=0;i<V.n;i++)
            {
                W.A[i]=V.A[i]*U.A[i];
                t=t+W.A[i];
            }
        return t;
    }
}
