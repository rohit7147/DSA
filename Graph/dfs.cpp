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
    cin>>G->V;
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
        list<int>::iterator ptr=G->adj[i].begin();
        cout<<i+1<<" ";
        while(ptr!=G->adj[i].end())
        {
            cout<<(*ptr)+1<<" ";
            ptr++;
        }
        cout<<"\n";
    }
}
void dfs(struct Graph *G)
{
    int i,visited[G->V],src;
    for(i=0;i<G->V;i++)
        visited[i]=0;
    cin>>src;
    stack<int> s;
    list<int>::iterator ptr;
    visited[src]=1;
    s.push(src);
    cout<<"\nDFS of given graph\n";
    cout<<src<<" ";
    while(!s.empty())
    {
        src=s.top();
        for(ptr=G->adj[src].begin();ptr!=G->adj[src].end();ptr++)
        {
            if(!visited[*ptr])
            {
                visited[*ptr]=1;
                cout<<(*ptr)+1<<" ";
                s.push(*ptr);
                break;
            }
        }
        if(ptr==G->adj[src].end())
            s.pop();
    }
}
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    cin>>G->E;
    for(int i=0;i<G->E;i++)
        addEdge(G);
    cout<<"Undirected graph\n";
    display(G);
    cout<<endl;
    dfs(G);
}
/*input
0 1
0 2
0 3
1 3
2 3
3 4
*/
