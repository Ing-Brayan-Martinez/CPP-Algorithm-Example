#include <iostream>

using namespace std;

int main()
{
    double**Matry;
    Matry=new double*[10];//crea 10 filas

    for (int i=0;i<10;i++)
        Matry[i]=new double[15]; //Matrz de 10x15

        for (int i=0;i<10;i++)
            {
                for (int j=0;j<15;j++)
                {Matry [i][j]=i+j;
                    cout <<Matry [i][j]<<"\t";
                }
            cout<<endl;
            }
}
 //for (int i=0;i<10;i++)
 //delete[] Matry[i];
 //delete[] Matry

