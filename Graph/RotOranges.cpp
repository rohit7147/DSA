#include <iostream>
#define MAX 100
using namespace std;
bool vis[MAX][MAX];
void bfs(int a[MAX][MAX],int row,int col,int i,int j,int *countOfOnes)
{
    if(i<0||j<0||i>=row||j>=col||a[i][j]==0||vis[i][j]==true)
        return;
    if(a[i][j]==1)
    {
        a[i][j]=2;
        (*countOfOnes)--;
        bfs(a,row,col,i,j,countOfOnes);
    }
    vis[i][j]=true;
    bfs(a,row,col,i-1,j,countOfOnes);
    bfs(a,row,col,i,j+1,countOfOnes);
    bfs(a,row,col,i+1,j,countOfOnes);
    bfs(a,row,col,i,j-1,countOfOnes);
}
int main()
{
	int t,i,j,row,col;
	cin>>t;
	while(t--)
	{
	    cin>>row>>col;
	    int a[MAX][MAX],countOfOnes=0,count=0;
	    for(i=0;i<row;i++)
	    {
	        for(j=0;j<col;j++)
	        {
	            cin>>a[i][j];
	            if(a[i][j]==1)
	                countOfOnes++;
	            vis[i][j]=false;
	        }
	   }
	   int tmp;
	   for(i=0;i<row;i++)
	   {
	       for(j=0;j<col;j++)
	       {
	           if(a[i][j]==2 && !vis[i][j])
	           {
                   tmp=countOfOnes;
	               bfs(a,row,col,i,j,&countOfOnes);
	               if(countOfOnes<tmp)
	               count++;
	           }
	       }
	   }
	   if(countOfOnes>0) cout<<-1;
	   else cout<<count;
	   cout<<endl;
	}
	return 0;
}
/*
1
55 8
1 2 1 1 2 1 2 1 1 1 0 0 2 1 0 0 1 0 1 0 2 0 2 0 0 0 1 2 0 0 1 1 2 0 1 1 2 1 0 1 2 1 2 1 0 0 2 1 0 0 1 0 0 2 2 1 2 1 1 0 2 1 0 2 1 1 1 1 0 0 0 2 1 0 1 2 0
1 2 2 2 1 0 0 0 2 2 0 2 1 1 1 2 1 1 2 0 1 0 0 1 1 0 0 2 2 2 2 0 1 2 0 0 0 1 1 0 1 0 2 2 1 2 0 0 0 2 1 2 0 2 0 2 2 1 1 1 1 1 2 0 1 0 1 1 2 0 1 0 1 2 0 0 2
1 0 0 0 1 0 1 0 0 0 0 2 2 2 1 1 1 2 2 2 1 0 1 2 2 1 0 2 0 0 1 1 1 2 0 0 2 2 1 0 1 1 2 0 1 1 1 2 1 0 2 0 1 0 2 2 0 0 1 1 0 0 0 2 2 1 2 2 1 0 2 2 2 0 2 0 1
2 2 0 2 2 0 2 1 0 2 2 1 0 0 1 1 1 1 1 0 0 0 1 1 0 0 0 1 0 0 0 2 1 1 0 1 2 2 2 1 2 1 2 2 2 2 2 1 0 0 1 2 2 0 0 2 0 1 1 0 2 1 0 1 0 1 0 1 1 0 0 0 0 2 2 2 2
1 1 0 0 0 0 2 0 0 2 0 2 0 2 0 2 0 1 1 1 2 2 2 0 2 2 0 2 2 0 2 2 2 0 2 2 0 2 0 0 1 1 1 2 0 1 2 1 0 0 2 0 2 2 1 2 1 1 2 1 2 1 1 2 1 1 2 1 0 0 2 2 2 1 1 1 2
1 2 1 2 2 1 1 1 2 2 1 1 1 0 1 0 1 1 1 2 1 0 2 2 0 2 1 2 1 2 2 2 2 0 1 2 1 1 1 1 0 2 0 1 0 2 1 1 1 0 1 2 1 1 1
*/
/*
1
3 3
1 2 1
1 1 1
1 1 1
*/
