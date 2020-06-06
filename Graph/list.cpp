#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<pair<int,int> > l;
    for(int i=0;i<5;i++)
    {
        l.push_back(make_pair(i,i+1));
    }
    list<pair<int,int> >::iterator it=l.begin();
    while(it!=l.end())
    {
        cout<<(*it).first<<" ";
        it++;
    }
}
