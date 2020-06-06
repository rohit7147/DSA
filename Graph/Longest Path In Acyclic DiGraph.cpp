#include<iostream>
#include<stdlib.h>
#include<list>
#include<stack>
#include <limits.h>
#define NINF INT_MIN
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
void longestPath(struct Graph *G,int source)
{
    int i,visited[G->V],d[G->V];
    stack<int> s;
    for(i=0;i<G->V;i++)
        visited[i]=0;
    for(i=0;i<G->V;i++)
        if(!visited[i])
            topologicalSortUtil(G,i,visited,s);
    for(i=0;i<G->V;i++)
        d[i]=NINF;
    d[source]=0;
    list<pair<int,int> >::iterator it;
    while(!s.empty())
    {
        int src=s.top();
        s.pop();
        if(d[src]!=NINF)
        {
            for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
            {
                if(d[(*it).first] < d[src]+(*it).second)
                    d[(*it).first] = d[src]+(*it).second;
            }
        }
    }
    for(i=0;i<G->V;i++)
        (d[i]==NINF)?cout<<"INF ":cout<<d[i]<<" ";
}
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    for(int i=0;i<G->E;i++)
        addEdge(G);
    int source;
    cin>>source;
    longestPath(G,source);
}
/*
6
10
0 1 5
1 3 6
3 5 1
0 2 3
1 2 2
2 3 7
2 5 2
2 4 4
4 5 -2
3 4 -1
*/
