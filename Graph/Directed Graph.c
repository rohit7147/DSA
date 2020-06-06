#include<iostream>
#include<stdlib.h>
#define max 3
using namespace std;
struct node
{
    int info;
    struct node *link;
};
struct Graph
{
    int V;
    struct node **start;
};
void printGraph(Graph *);
Graph *createGraph();
void AddEdge(Graph *);
int main()
{
    Graph *G;
    int i,j;
    G = createGraph();
    for(i=0;i<7;i++)
        AddEdge(G);
    printGraph(G);
}
Graph *createGraph()
{
    int i;
    Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cout<<"Enter number of vertex in the graph : ";
    cin>>G->V;
    G->start=(node **)malloc(G->V * sizeof(struct node));
    for(i=0;i<G->V;i++)
    {
        G->start[i]=(node*)malloc(sizeof(struct node));
        G->start[i]->info=i;
        G->start[i]->link=NULL;
    }
    return G;
}
void AddEdge(Graph *G)
{
    int source,destination;
    cin>>source>>destination;
   node *tmp=(struct node *)malloc(sizeof(struct node));
    node *ptr=G->start[source];
    tmp->info=G->start[destination]->info;
    while(ptr->link!=NULL)
        ptr=ptr->link;
    ptr->link=tmp;
    tmp->link=NULL;
}
void printGraph(Graph *G)
{
    int i;
    for(i=0;i<G->V;i++)
    {
        node *ptr=G->start[i];
        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->link;
        };
        cout<<endl;
    }
}
