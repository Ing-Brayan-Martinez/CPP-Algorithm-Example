#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    /*list<int>L;
    L.push_back(7);
    L.push_front(-9);
    L.push_front(16);
    L.sort();
    list<int>::const_iterator it;
    for(it=L.begin();it!=L.end();it++)
    cout<< *it<<" ";*/
    vector<list<int> >f;
    vector<int>x;
    f.resize(10);
    x.resize(1000);
    for(int i=0;i<x.size();i++)
    x[i]=rand()%100;

    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<f.size();j++){
        if((x[i]>=10*j)&&(x[i]<10*(j+1)))
        f[j].push_front(x[i]);
        }
    }
    ofstream fa;
    fa.open("Histograma.txt");
    for(int i=0;i<f.size();i++)
    {
    list<int>::const_iterator it;
    fa<<"frecuencia"<<i<<": ";
    for(it=f[i].begin();it!=f[i].end();it++)
    fa<<*it<<" ";
    fa<<endl;
    }
fa.close();
return 0;
}
