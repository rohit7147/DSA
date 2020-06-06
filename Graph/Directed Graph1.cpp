#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V,E;
    list<int> *adj;
};
struct Graph *createGraph(struct Graph *G)
{
    G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    G->adj=new list<int>[G->V];
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src-1].push_back(dest-1);
    //G->adj[dest-1].push_back(src-1);
}
void printGraph(struct Graph *G)
{
    int i;
    list<int>::iterator it;
    for(i=0;i<G->V;i++)
    {
        cout<<i+1<<" ";
        for(it=G->adj[i].begin();it!=G->adj[i].end();it++)
            cout<<(*it)+1<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    Graph *G=NULL;
    G=createGraph(G);
    for(int i=0;i<G->E;i++)
        addEdge(G);
    printGraph(G);
}
/*
0 1
0 2
0 4
1 2
1 3
2 3
3 4
4 2
*/
/*
5 8
1 2
1 3
1 5
2 3
2 4
3 4
4 5
5 3
*/
