#include<iostream>
#include<stdlib.h>
#include<list>
#include<vector>
#include<stack>
#define INF 0x3f3f3f3f

using namespace std;
struct Graph
{
    int V;
    int E;
    list<pair<int,int> > *adj;
};
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    G->adj=new list<pair<int,int> >[G->V];
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest,wt;
    cin>>src>>dest>>wt;
    G->adj[src].push_back(make_pair(dest,wt));
}
void topologicalSortUtil(struct Graph *G,int src,int visited[],stack<int> &s)
{
    visited[src]=1;
    list<pair<int,int> >::iterator it;
    for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
    {
        if(!visited[(*it).first])
            topologicalSortUtil(G,(*it).first,visited,s);
    }
    s.push(src);
}
stack<int> topologicalSort(struct Graph *G)
{
    int i,visited[G->V];
    stack<int> s;
    for(i=0;i<G->V;i++)
        visited[i]=0;
    for(i=0;i<G->V;i++)
        if(!visited[i])
            topologicalSortUtil(G,i,visited,s);
    return s;
}
void shortestPath(struct Graph *G,stack<int> &s,int src)
{
    list<pair<int,int> >::iterator it;
    vector<int> d(G->V,INF);
    d[src]=0;
    while(!s.empty())
    {
        int u=s.top();
        it=G->adj[u].begin();
        if (d[u] != INF)
        {
            for(it=G->adj[u].begin();it!=G->adj[u].end();it++)
            {
                int v = (*it).first;
                int wt=(*it).second;
                if(d[v] > d[u]+wt)
                    d[v]=d[u]+wt;
            }
        }
        s.pop();
    }

    for(int i=0;i<G->V;i++)
        (d[i] == INF)? cout << "INF ": cout << d[i] << " ";
}
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    for(int i=0;i<G->E;i++)
        addEdge(G);
    int src;
    stack<int> s=topologicalSort(G);
    cin>>src;
    shortestPath(G,s,src);
}
/*
6
9
0 1 5
0 2 3
1 3 6
1 2 2
2 4 4
2 5 2
2 3 7
3 4 -1
4 5 -2
*/

