#include <iostream>
#include <fstream>

using namespace std;

int*aleatorios(int n)
    {
    int*A;
    A=new int[n];
    for (int i=0;i<n;i++)
        A[i]=(rand()%21)-10;
    return A;
    }

int*frecuencia(int n, int*A, int m)
    {
    int*f;
    f=new int[n];
    for (int i=0;i<n;i++)
        f[i]=0;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (A[i]==j-10)
                f[j]=f[j]+1;
    return f;
    }

int main()
{
    int*A,*f,n,m;
    n=1000;
    m=21;
    A=aleatorios(n);
    f=frecuencia(m,A,n);
    ofstream of;
    of.open("frecuencia.txt");
    for (int i=0;i<n;i++)
        of<<A[i]<<"\t";
    of<<endl;
    for (int i=0;i<m;i++)
        of<<i-10<<"\t"<<f[i]<<endl;
    of.close();
    return 0;
}
