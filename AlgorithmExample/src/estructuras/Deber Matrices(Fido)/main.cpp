#include <iostream>
#include <cmath>

using namespace std;

class matriz
    {
    private:
        int filas;
        int columnas;
        double**M;
    public:
        matriz(int m, int n)
            {
            filas=m;
            columnas=n;
            M=new double*[m];
            for (int i=0;i<m;i++)
                M[i]=new double [n];
            for (int i=0;i<m;i++)
                for (int j=0;j<n;j++)
                    M[i][j]=0;
            }
        matriz(int n)
            {
            filas=n;
            columnas=n;
            M=new double*[n];
            for (int i=0;i<n;i++)
                M[i]=new double [n];
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    M[i][j]=0;
            for (int i=0;i<n;i++)
                M[i][i]=1;
            }
        friend ostream& operator<<(ostream&of,matriz&A);
        friend istream& operator>>(istream&in, matriz&A);
        friend matriz operator+(matriz A, matriz B);
        friend matriz operator-(matriz A, matriz B);
        friend matriz operator*(matriz A, matriz B);
        friend matriz operator*(double a, matriz A);
        friend bool operator==(matriz A, matriz B);
        friend bool operator!=(matriz A, matriz B);
        void transpuesta(matriz&BT);
        double traza();
        void inversa(matriz&A_1);
        double determinante();
    };

ostream& operator<<(ostream&of,matriz&A)
            {
            for (int i=0 ; i<A.filas ; i++)
                {
                of << "|";
                for (int j=0 ; j<A.columnas ; j++)
                    {
                    if (j<A.columnas-1)
                        of << A.M[i][j] << "\t";
                    else
                        of << A.M[i][j];
                    }
                of << "|" <<endl;
                }
            return of;
            }

istream& operator>>(istream&in, matriz&A)
            {
            for (int i=0;i<A.filas;i++)
                for (int j=0;j<A.columnas;j++)
                    in>>A.M[i][j];
            return in;
            }
matriz operator+(matriz A, matriz B)
            {
            matriz aux(A.filas, A.columnas);
            if ((A.filas==B.filas)&&(A.columnas==B.columnas))
                {
                for (int i=0;i<A.filas;i++)
                    for (int j=0;j<A.columnas;j++)
                        aux.M[i][j]=A.M[i][j]+B.M[i][j];
                }
            else
                cout<<"las matrices deben ser de la misma dimension";
            return aux;
            }
matriz operator-(matriz A, matriz B)
            {
            matriz aux(A.filas, A.columnas);
            if ((A.filas==B.filas)&&(A.columnas==B.columnas))
                {
                for (int i=0;i<A.filas;i++)
                    for (int j=0;j<A.columnas;j++)
                        aux.M[i][j]=A.M[i][j]-B.M[i][j];
                }
            else
                cout<<"las matrices deben ser de la misma dimension";
            return aux;
            }
matriz operator*(matriz A, matriz B)
            {
            matriz aux(A.filas, B.columnas);
            if (A.columnas==B.filas)
                {
                for (int i=0;i<A.filas;i++)
                    for (int j=0;j<B.columnas;j++)
                        for (int k=0;k<A.columnas;k++)
                            aux.M[i][j]=aux.M[i][j]+(A.M[i][k]*B.M[k][j]);
                }
            else
                cout<<"el numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda";
            return aux;
            }
matriz operator*(double a, matriz A)
            {
            matriz aux(A.filas, A.columnas);
            for (int i=0;i<A.filas;i++)
                for (int j=0;j<A.columnas;j++)
                    aux.M[i][j]=a*A.M[i][j];
            return aux;
            }
bool operator==(matriz A, matriz B)
            {
            bool aux=true;
            if ((A.filas==B.filas)&&(A.columnas==B.columnas))
                {
                for (int i=0;i<A.filas;i++)
                    for (int j=0;j<A.columnas;j++)
                        if(A.M[i][j]!=B.M[i][j])
                            aux=false;
                }
            else
                aux=false;
            return aux;
            }
bool operator!=(matriz A, matriz B)
            {
            bool aux=false;
            if ((A.filas==B.filas)&&(A.columnas==B.columnas))
                {
                for (int i=0;i<A.filas;i++)
                    for (int j=0;j<A.columnas;j++)
                        if(A.M[i][j]!=B.M[i][j])
                            aux=true;
                }
            else
                aux=true;
            return aux;
            }
void matriz::transpuesta(matriz&BT)
            {
            if ((filas==BT.columnas)&&(columnas==BT.filas))
                for (int i=0;i<columnas;i++)
                    for (int j=0;j<filas;j++)
                        BT.M[i][j]=M[j][i];
            else
                cout<<"error";
            }
double matriz::traza()
            {
            double aux=0;
            if (filas=columnas)
                for (int i=0;i<filas;i++)
                    aux=aux+M[i][i];
            else
                cout<<"la matriz debe ser cuadrada";
            return aux;
            }
void matriz::inversa(matriz&A_1)
            {
            if (filas=columnas)
                {
                matriz A(filas, columnas);
                for (int i=0;i<filas;i++)
                    for (int j=0;j<columnas;j++)
                        A.M[i][j]=M[i][j];
                matriz An(filas, columnas);
                matriz Bn(filas);
                matriz I(filas);
                double t;
                double p;
                for (int i=1;i<filas;i++)
                    {
                    An=Bn*A;
                    p=An.traza();
                    t=(p/i)*(-1);
                    matriz D(filas, columnas);
                    D=t*I;
                    Bn=An+D;
                    }
                An=Bn*A;
                p=An.traza();
                t=(p/filas)*(-1);
                double r;
                r=(1/t)*(-1);
                A_1=r*Bn;
                }
            else
                cout<<"la matriz debe ser cuadrada";
            }
double matriz::determinante()
            {
            double det=1;
            if (filas=columnas)
            {
            matriz aux(filas, columnas);
            for (int i=0;i<filas;i++)
                for (int j=0;j<columnas;j++)
                    aux.M[i][j]=M[i][j];
            for (int k=0;k<(filas-1);k++)
                {
                for (int i=(k+1);i<filas;i++)
                    {
                    for (int j=k;j<filas;j++)
                        {
                        int l;
                        l=filas-1-j+k;
                        aux.M[i][l]=aux.M[i][l]-((aux.M[i][k]/aux.M[k][k])*aux.M[k][l]);
                        }
                    }
                }
            for (int i=0;i<filas;i++)
                det=det*aux.M[i][i];
            }
            else
                cout<<"la matriz debe ser cuadrada";
            return det;
            }
int main()
{
    int m;
    int n;
    cout << "Christian Zambrano, Andres Barriga y ....el licenciado"<<endl;
    cout << endl;
    cout << "Se tiene que probar el caso de una matriz cuadrada y una rectangular"<<endl;
    cout << endl;
    cout << "Ingrese el n'umero de filas de la Matriz mate:"<< endl;
    cin>> m;
    cout << "Ingrese el n'umero de columnas de la Matriz mate:"<< endl;
    cin>> n;
    double v;
    cout << "Ingrese el escalar mate"<< endl;
    cin>> v;
    matriz A(m,n), B(n,m), C(m,m), D(m,n);
    cout << "Ingrese la Matriz mate"<< endl;
    cin >> A;
    cout << endl;
    cout << endl;
    cout << "Matriz Ingresada:" << endl;
    cout << A;
    cout << endl;
    cout << endl;
    cout << "Transpuesta de la Matriz:" << endl;
    A.transpuesta (B);
    cout << B;
    cout << endl;
    cout << endl;
    if(m==n)
    {
    cout << "Traza de la Matriz:" << endl;
    cout << B.traza () << endl;
    cout << endl;
    }
    cout <<"Producto entre Matrices se multiplico la matriz por la transpuesta "<< endl;
    C=A*B;
    cout << C;
    cout << endl;
    cout << endl;
    if(m==n)
    {
    cout <<"suma entre la matriz y la transpuesta"<< endl;
    C=A+B;
    cout << C;
    cout << endl;
    cout << endl;
    cout <<"resta entre la matriz y la transpuesta"<< endl;
    C=A-B;
    cout << C;
    cout << endl;
    cout << endl;
    }
    cout <<"Producto por un Escalar"<< endl;
    C=v*A;
    cout << C;
    cout << endl;
    cout << endl;
    if(m==n)
    {
    cout <<"Inversa de la Matriz"<< endl;
    A.inversa (D);
    cout << D;
    cout << endl;
    cout << endl;
    cout <<"Determinante de la Matriz"<< endl;
    v=A.determinante ();
    cout << v;
    }
    return 0;
}
