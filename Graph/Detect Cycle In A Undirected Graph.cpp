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

struct Graph *createGraph();
void addEdge(struct Graph *);
void display(struct Graph *);
int detectCycle(struct Graph *);

int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    cin>>G->E;
    for(int i=0;i<G->E;i++)
        addEdge(G);
    display(G);
    if(detectCycle(G))
        cout<<"Cycle Detected";
    else
        cout<<"No Cycle Detected";
}
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V;
    G->adj=new list<int>[G->V];
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src].push_back(dest);
    G->adj[dest].push_back(src);
}
void display(struct Graph *G)
{
    cout<<"\nGraph Displayed\n";
    for(int i=0;i<G->V;i++)
    {
        list<int> :: iterator ptr=G->adj[i].begin();
        cout<<i<<" ";
        while(ptr!=G->adj[i].end())
        {
            cout<<*ptr<<" ";
            ptr++;
        }
        cout<<"\n";
    }
}
int detectCycle(struct Graph *G)
{
    int visited[G->V],src,parent;
    for(int i=0;i<G->V;i++)
        visited[i]=0;
    cin>>src;
    list<int> :: iterator i;
    stack<pair<int,int> > s;
    s.push(make_pair(src,-1));
    visited[src]=1;
    while(!s.empty())
    {
        src=s.top().first;
        parent=s.top().second;
        for(i=G->adj[src].begin();i!=G->adj[src].end();i++)
        {
            if(!visited[*i])
            {
                s.push(make_pair(*i,src));
                visited[*i]=1;
            }
            else if(*i==parent)
                continue;
            else
                return 1;
        }
        if(i==G->adj[src].end())
            s.pop();
    }
    return 0;
}
/*
0 1
1 2
2 3
3 4
4 5
*/
