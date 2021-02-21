#ifndef CLASEVECTOR_H_INCLUDED
#define CLASEVECTOR_H_INCLUDED
#include <iostream>
#include <cmath>

using namespace std;

class vector
{
    private:
        int n;
        double *A;
    public:
        vector (int dimension)
        {
            n=dimension;
            A=new double [n];
            for (int i=0;i<n;i++)
            {
                A[i]=0;
            }
        }
        friend istream& operator >> (istream& en,vector &V);
        friend ostream& operator << (ostream& sa,vector &V);
        friend vector operator + (vector V,vector U);
        friend vector operator - (vector V,vector U);
        friend vector operator * (double x,vector V);
        //friend vector operator * (vector V,vector U);
        friend bool operator == (vector V,vector U);
        friend bool operator != (vector V,vector U);
        friend double norma(vector V);
        friend double punto(vector V,vector U);
};
#endif // CLASEVECTOR_H_INCLUDED
