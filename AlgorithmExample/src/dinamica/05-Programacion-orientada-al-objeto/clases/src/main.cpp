#include <iostream>
#include <fstream>
using namespace std;

class matry
{
private:
int m; //filas
int n; //columnas

public:
double **A;//arreglo dinamico bidimensional A[i][j]

matry (int f, int c)//constructor
{
m=f;
n=c;
A=new double *[m];//creo la priemra dimension del arreglo las filas, se le baja la dimension por eso *
for(int i=0;i<m;i++)
    A[i]=new double[n];

}

~matry ()//destructor
{
for(int i=0;i<n;i++)
    delete[]A[i];
delete[]A;
cout<<"matriz eliminada"<<endl;
}

matry(const string matry)//constructor
{
ifstream fa;
fa.open(matry.c_str());//transforma el tipo string a un vector de caracteres const char ARCHIVO[50]
fa>>m;
fa>>n;
A=new double *[m];
for(int i=0;i<m;i++)
    A[i]=new double[n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            fa>>A[i][j];//la informacion pasa a este arreglo bidimensional
    fa.close();
}

int n_filas()//para acceder el numero de filas
{
return m;
}

int n_col()//para acceder el numero de columnas
{
return n;
}

bool es_tridiagonal()
{
bool tri=true;
for(int i=0;i<m-2;i++)
    for(int j=i+2;j<n;j++)
    if((A[i][j]!=0) || (A[j][i]!=0))
        tri=false; //para la parte triangular superior de ceros
    return tri;
}

friend ostream& operator<<(ostream&os, matry M)
{
for(int i=0;i<M.m;i++)
    {
    for(int j=0;j<M.n;j++)
    os<<M.A[i][j]<<" ";
    os<<endl;
    }
    return os;
}

};
int main()
{
matry M(3,4);
matry P("matry.txt");
cout<<P<<endl;

ofstream fs;
fs.open("matry_M.txt");
fs<<"Copia Matriz";
fs<<P;
fs.close();
}
