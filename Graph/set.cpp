#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> st;
    for(int i=0;i<5;i++)
        st.insert(i);
    set<int>::iterator it=st.begin();
    it=st.find(1);
    cout<<*st.find(2);
}
