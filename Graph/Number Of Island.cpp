#include<iostream>
#define MAX 20
using namespace std;
bool vis[MAX][MAX];
bool bfs(int A[MAX][MAX],int row,int col,int i,int j)
{
    if(i<0||j<0||i>=row||j>=col||vis[i][j]==true||A[i][j]==0)
        return false;
    vis[i][j]=true;
    bfs(A,row,col,i-1,j-1);
    bfs(A,row,col,i-1,j);
    bfs(A,row,col,i-1,j+1);
    bfs(A,row,col,i,j+1);
    bfs(A,row,col,i+1,j+1);
    bfs(A,row,col,i+1,j);
    bfs(A,row,col,i+1,j-1);
    bfs(A,row,col,i,j-1);
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    int count=0,i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(A[i][j]==1 && !vis[i][j])
            {
                bfs(A,N,M,i,j);
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int t,i,j,row,col;
    cin>>t;
    while(t--)
    {
        int a[MAX][MAX];
        cin>>row>>col;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                cin>>a[i][j];
                vis[i][j]=false;
            }
        }
        cout<<findIslands(a,row,col)<<endl;
    }
}
/*
1
3 3
1 1 0
0 0 1
1 0 1
*/
/*
1
5 5
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1
*/
/*
1
5 8
0 1 0 1 1 1 0 1
0 1 0 1 0 0 1 0
1 0 0 0 0 0 1 1
0 1 0 0 0 0 1 0
0 0 0 1 1 0 0 0
*/
