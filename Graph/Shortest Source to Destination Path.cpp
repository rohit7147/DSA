#include <iostream>
#include <climits>
#define MAX 20
using namespace std;
bool vis[MAX][MAX];
int a[MAX][MAX];
int row,col;
int minDistance(int i,int j,int x,int y)
{
    cout<<"i : "<<i<<"\t"<<"j : "<<j<<endl;
    if(i<0||j<0||i>=row||j>=col||vis[i][j]==true||a[i][j]==0)
        return INT_MAX;
    //cout<<"a["<<i<<"]["<<j<<"] : "<<a[i][j]<<endl;
    vis[i][j]=true;
    if(i==x&&j==y&&a[i][j]==1)
        return 1;
    int minSteps=min(
                     min(1+minDistance(i-1,j,x,y),1+minDistance(i,j-1,x,y)),
                     min(1+minDistance(i+1,j,x,y),1+minDistance(i,j+1,x,y))
                    );
    return minSteps-1;
}
int main()
{
	int t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>row>>col;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                {
                    vis[i][j]=false;
                    cin>>a[i][j];
                }
        int destx,desty;
        cin>>destx>>desty;
        int dist=minDistance(0,0,destx,desty);
        if(dist>=INT_MAX)
            cout<<-1;
            else cout<<dist;
        cout<<endl;
    }
	return 0;
}
/*
1
3 4
1 0 1 0
1 1 0 1
1 1 1 1
2 3
*/
