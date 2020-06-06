#include <iostream>
#include <vector>
#include <climits>
#define MAX 50
using namespace std;
bool vis[MAX][MAX];
int getMin(vector<int> &v)
{
    int minm=v[0];
    /*for(int i=1;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;*/
    for(int i=1;i<v.size();i++)
        if(minm>v[i])
            minm=v[i];
    //cout<<"min : "<<minm<<endl;
    return minm;
}
int minCostPath(int A[MAX][MAX],int n,int i,int j)
{
    if(i<0||j<0||i>=n||j>=n||vis[i][j]==true)
        return INT_MAX;
    vis[i][j]=true;
    if(i==n-1&&j==n-1)
        return A[i][j];
    vector<int> v(4);
    v.push_back(minCostPath(A,n,i-1,j));
    v.push_back(minCostPath(A,n,i,j+1));
    v.push_back(minCostPath(A,n,i+1,j));
    v.push_back(minCostPath(A,n,i,j-1));
    int minCost=A[i][j]+getMin(v);
    cout<<"i : "<<i<<" j : "<<j<<" mincost : "<<minCost<<endl;
    return minCost;
}
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[MAX][MAX];
	    for(i=0;i<n;i++)
	        for(j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            vis[i][j]=false;
	        }
	    cout<<minCostPath(a,n,0,0)<<endl;
	}
	return 0;
}
/*
2
5
31 100 65 12 18
10 13 47 157 6
100 113 174 11 33
88 124 41 20 140
99 32 111 41 20
2
42 93
7 14
*/
