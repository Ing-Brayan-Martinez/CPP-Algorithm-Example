#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
   /* int n;
    cout<<"Ingrese tamano: ";
    cin>>n;
    vector<double>ve(n,0);
    for(unsigned int i=0;i<ve.size();i++)
    ve[i]=double(i*i/(i+1));


    cout<<"Ultimo: "<<ve.back()<<endl;
    cout<<"Primero: "<<ve.front()<<endl;


    ve.resize(150,-1);
    for(unsigned int i=0;i<ve.size();i++)
    ve[i]=i*i/(i+1);
    cout<<"Ultimo: "<<ve.back()<<endl;
    cout<<"Primero: "<<ve.front()<<endl;
    ve.clear();*/

     list <int>L;
     L.push_back(7);
     L.push_front(10);
     L.push_back(-1);
     if(L.empty()==false)
     {
         int x=L.back();
         L.pop_back();
         cout<<x<<" "<<L.back()<<endl;
     }
     L.push_front(20);
     L.push_back(-50);
     L.sort();
     list<int>::iterator it;
     for(it=L.begin();it!=L.end();it++)
     cout<<*it<<" ";

    return 0;
}
