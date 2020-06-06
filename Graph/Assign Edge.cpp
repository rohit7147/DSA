#include<iostream>
#include<list>
#include<stdlib.h>
#include<limits.h>
#include<stack>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
void assignEdge(struct Graph *G,int topologicalOrder[])
{
    int u,v,i,indexU=INT_MIN,indexV=INT_MIN;
    cin>>u>>v;
    for(i=0;i<G->V;i++)
    {
        if(topologicalOrder[i]==u)
            indexU=u;
        else if(topologicalOrder[i]==v)
            indexV=v;
        if(indexU!=INT_MIN && indexV!=INT_MIN)
            break;
    }
    if(indexU<indexV)
    {
        G->adj[u].push_back(v);
        cout<<"Edge added from "<<u<<"to "<<v<<endl;
    }
    else
    {
        G->adj[v].push_back(u);
        cout<<"Edge added from "<<u<<"to "<<v<<endl;
    }
}
void topSort(struct Graph *G,int visited[],int src,stack<int> &s)
{
    visited[src]=1;
    list<int>::iterator it;
    for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
        if(!visited[*it])
            topSort(G,visited,*it,s);
    s.push(src);
}
void topologicalSort(struct Graph *G,stack<int> &s)
{
    int i,visited[G->V];
    for(i=0;i<G->V;i++)
        visited[i]=0;
    for(i=0;i<G->V;i++)
        if(!visited[i])
            topSort(G,visited,i,s);
}
void addEdge(struct Graph *G,int isDirected)
{
    int src,dest;
    cin>>src>>dest;
    if(isDirected)
        G->adj[src].push_back(dest);
    else
    {
        G->adj[src].push_back(dest);
        G->adj[dest].push_back(src);
    }
}
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    G->adj=new list<int>[G->V];
    return G;
};
int main()
{
    struct Graph *G=NULL;
    int i;
    stack<int> s;
    G=createGraph();
    for(i=0;i<G->E;i++)
        addEdge(G,1);
    topologicalSort(G,s);
    int topologicalOrder[G->V];
    i=0;
    while(!s.empty())
    {
        cout<<"s.top()"<<s.top()<<" ";
        topologicalOrder[i]=s.top();
        s.pop();
        i++;
    }
    assignEdge(G,topologicalOrder);
}
/*
6
10
0 1
0 5
1 2
1 3
1 4
2 3
2 4
3 4
4 5
5 2
*/
