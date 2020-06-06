#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;
#define MAX 10
int M[MAX][MAX];
void printMat(int row,int col)
{
    char a[col];
    char *tmp=NULL;
    map<int,int> m;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            a[j]=M[i][j];
        for(int j=0;j<col;j++)
            cout<<"a["<<j<<"] : "<<a[j]<<endl;
        int val=strtoul(a,&tmp,2);
        cout<<"val : "<<val<<endl;
        if(m[val]!=1)
        {
            for(int j=0;j<col;j++)
                cout<<M[i][j]<<" ";
            cout<<"$";
        }
        m[val]=1;
    }
}
int main()
{
    int t,i,j,row,col;
    cin>>t;
    while(t--)
    {
        cin>>row>>col;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                cin>>M[i][j];
        printMat(row,col);
        cout<<endl;
    }
}
