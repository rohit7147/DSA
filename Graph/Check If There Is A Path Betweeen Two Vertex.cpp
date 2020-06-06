#include<iostream>
#include<stdlib.h>
#include<queue>
#include<list>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
void createGraph(struct Graph **G)
{
    *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>(*G)->V>>(*G)->E;
    (*G)->adj=new list<int>[(*G)->V];
};
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src].push_back(dest);
}
int isReachable(int src,int dest,struct Graph *G)
{
    list<int>::iterator it;
    queue<int> q;
    vector<int> visited(G->V,0);
    q.push(src);
    visited[src]=1;
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
        {
            if(*it == dest)
                return 1;
            if(!visited[*it])
            {
                visited[*it]=1;
                q.push(*it);
            }
        }
    }
    return 0;
}
int main()
{
    struct Graph *G=NULL;
    createGraph(&G);
    for(int i=0;i<G->E;i++)
        addEdge(G);
    int src,dest;
    cin>>src>>dest;
    if(isReachable(src,dest,G))
        cout<<dest<<" is reachable from "<<src;
    else
        cout<<dest<<" not reachable from "<<src;
}
