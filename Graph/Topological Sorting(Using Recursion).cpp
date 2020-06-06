#include<iostream>
#include<stdlib.h>
#include<list>
#include<stack>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    G->adj=new list<int>[G->V];
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src].push_back(dest);
}
void topologicalSortUtil(struct Graph *G,int src,int visited[],stack<int> &s)
{
    visited[src]=1;
    list<int>::iterator it;
    for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
    {
        if(!visited[*it])
            topologicalSortUtil(G,*it,visited,s);
    }
    s.push(src);
}
void topologicalSort(struct Graph *G)
{
    int i,visited[G->V];
    stack<int> s;
    for(i=0;i<G->V;i++)
        visited[i]=0;
    for(i=0;i<G->V;i++)
        if(!visited[i])
            topologicalSortUtil(G,i,visited,s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    for(int i=0;i<G->E;i++)
        addEdge(G);
    topologicalSort(G);
}
/*
8
8
4 2
1 2
1 3
2 0
0 7
0 5
5 6
3 5
*/
/*
6
10
0 1
1 3
3 5
0 2
1 2
2 3
2 5
2 4
4 5
3 4
*/
