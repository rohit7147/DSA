#include<iostream>
#include<stdlib.h>
#include<list>
#include<queue>
#include<time.h>
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
int isCycle(int,struct Graph *);
int main()
{
    clock_t begin, end;
    double time_spent;
    begin = clock();
    struct Graph *G=NULL;
    G=createGraph();
    cin>>G->E;
    for(int i=0;i<G->E;i++)
        addEdge(G);
    //display(G);
    if(detectCycle(G))
        cout<<"\nCycle Detected\n";
    else
        cout<<"\nNo Cycle Detected\n";
        end = clock();

time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

cout<<"\nTime Taken %lf "<<time_spent;
}
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V;
    G->adj = new list<int>[G->V];
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src].push_back(dest);
}
void display(struct Graph *G)
{
    int i;
    list<int>::iterator ptr;
    for(i=0;i<G->V;i++)
    {
        ptr=G->adj[i].begin();
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
    int i;
    for(i=0;i<G->V;i++)
    {
        if(isCycle(i,G))
            return 1;
    }
    return 0;
}
int isCycle(int src,struct Graph *G)
{
    list<int>::iterator i;
    int visited[G->V];
    for(int j=0;j<G->V;j++)
        visited[j]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        for(i=G->adj[src].begin();i!=G->adj[src].end();i++)
        {
            if(!visited[*i])
            {
                q.push(*i);
                visited[*i]=1;
            }
            else
                return 1;
        }
    }
    return 0;
}
/*
4
4
0 1
1 2
2 3
3 0
*/
