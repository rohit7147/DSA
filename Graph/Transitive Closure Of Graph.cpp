#include<iostream>
#include<stdlib.h>
#include<queue>
#include<list>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<pair<int,int> > *adj;
};
void transitiveClosure(struct Graph *G)
{
    list<pair<int,int> >::iterator it;
    bool reachMatrix[G->V][G->V];
    int i,j;
    vector<bool> visited(G->V,0);
    for(i=0;i<G->V;i++)
        for(j=0;j<G->V;j++)
            reachMatrix[i][j]=0;
    queue<int> q;
    q.push(0);
    visited[0]=1;
    while(!q.empty())
    {
        int src=q.front();
        for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
        {
            reachMatrix[src][(*it).first]=1;
            if(!visited[(*it).first])
            {
                visited[(*it).first]=1;
                q.push((*it).first);
            }
        }
        q.pop();
    }
    for (int k = 0; k < G->V; k++)
        for (i = 0; i < G->V; i++)
            for (j = 0; j < G->V; j++)
                reachMatrix[i][j] = reachMatrix[i][j] || (reachMatrix[i][k] && reachMatrix[k][j]);
    for(i=0;i<G->V;i++)
    {
        for(j=0;j<G->V;j++)
            cout<<reachMatrix[i][j]<<" ";
        cout<<endl;
    }
}
void addEdge(struct Graph *G)
{
    int src,dest,wt;
    cin>>src>>dest>>wt;
    G->adj[src].push_back(make_pair(dest,wt));
}
void createGraph(struct Graph **G)
{
    (*G)=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>(*G)->V>>(*G)->E;
    (*G)->adj=new list<pair<int,int> >[(*G)->V];
}
int main()
{
    struct Graph *G=NULL;
    createGraph(&G);
    for(int i=0;i<G->E;i++)
        addEdge(G);
    transitiveClosure(G);
}
/*
4
7
0 0 5
0 1 10
1 1 15
1 2 20
2 2 25
2 3 30
3 3 12
*/
