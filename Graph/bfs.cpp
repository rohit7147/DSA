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
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cout<<"Enter number of Vertices and Edges in the graph : ";
    cin>>G->V>>G->E;
    G->adj=new list<int>[G->V];
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src-1].push_back(dest-1);
    G->adj[dest-1].push_back(src-1);
}
void display(struct Graph *G)
{
    int i;
    for(i=0;i<G->V;i++)
    {
        list<int>::iterator p=G->adj[i].begin();
        cout<<i+1<<" ";
        while(p!=G->adj[i].end())
        {
            cout<<(*p)+1<<" ";
            p++;
        }
        cout<<"\n";
    }
}
bool bfs(struct Graph *G)
{
    int visited[G->V],i,src=0;
    for(i=0;i<G->V;i++)
        visited[i]=0;
    queue<int> q;
    list<int>::iterator ptr = G->adj[src].begin();
    visited[src]=1;
    q.push(src);
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        int count=0;
        for(ptr=G->adj[src].begin();ptr!=G->adj[src].end();ptr++)
        {
            if(!visited[*ptr])
            {
                count++;
                visited[*ptr]=1;
                q.push(*ptr);
            }
        }
        if(count>2)
            return false;
    }
    return true;
}
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    cout<<"Enter "<<G->E<<" pairs of source and destination vertices"<<endl;
    for(int i=0;i<G->E;i++)
        addEdge(G);
    cout<<"Displaying input undirected graph..."<<endl;
    display(G);
    if(bfs(G)) cout<<"Input Undirected Graph is a binary tree"<<endl;
    else cout<<"Input Undirected graph is not a binary tree"<<endl;
}
