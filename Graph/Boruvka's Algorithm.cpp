#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    vector<pair<int,pair<int,int> > > edge;
};
struct disjointSet
{
    int parent;
    int rank;
};
void createSet(struct disjointSet *ds,struct Graph *G)
{
    for(int i=0;i<G->V;i++)
    {
        ds[i].parent=i;
        ds[i].rank=0;
    }
}
int findSet(struct disjointSet *ds,int i)
{
    if(ds[i].parent!=i)
        ds[i].parent=findSet(ds,ds[i].parent);
    return ds[i].parent;
}
void unionSet(struct disjointSet *ds,int src,int dest)
{
    int xroot=findSet(ds,src);
    int yroot=findSet(ds,dest);
    if(ds[xroot].rank > ds[yroot].rank)
        ds[yroot].parent=xroot;
    else if(ds[xroot].rank < ds[yroot].rank)
        ds[xroot].parent=yroot;
    else
    {
        ds[yroot].parent=xroot;
        ds[xroot].rank++;
    }
}
int boruvkaMST(struct Graph *G)
{
    int V=G->V,E=G->E,i,wt=0;
    struct disjointSet *ds=(struct disjointSet *)malloc(G->V * sizeof(struct disjointSet));
    vector<pair<int,pair<int,int> > > *edge=G->edge;
    for(i=0;i<E;i++)
    {
         cout<<"skdfksdfhs";
        cout<<edge[i]<<endl;
    }
    createSet(ds,G);
    int cheapest[V];
    for(i=0;i<V;i++)
        cheapest[i]=-1;
    int numTree=V;
    /*while(numTree>1)
    {
        cout<<"numTree : "<<numTree<<endl;
        for(edge=G->edge.begin();edge!=G->edge.end();edge++)
        {
            int u=findSet(ds,(*edge).second.first);
            int v=findSet(ds,(*edge).second.second);
            if(u==v)
                continue;
            else
            {
                if(cheapest[u] == -1 || edge[cheapest[u]].first > (*edge).first)
                    cheapest[u]=i;
                if(cheapest[u] == -1 || edge[cheapest[v]].first > (*edge).first)
                    cheapest[v]=i;
            }
        }
        for(i=0;i<V;i++)
        {
            if(cheapest[i]!=-1)
            {
                int u=findSet(ds,edge[cheapest[i]].second.first);
                int v=findSet(ds,edge[cheapest[i]].second.second);
                if(u==v)
                    continue;
                wt=wt+1;
                unionSet(ds,u,v);
                numTree--;

            }
        }
    }*/
    return wt;
}
void addEdge(struct Graph *G)
{
    int src,dest,wt;
    cin>>src>>dest>>wt;
    G->edge.push_back({wt,{src,dest}});
}
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    return G;
};
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    for(int i=0;i<G->E;i++)
        addEdge(G);
    cout<<"Boruvkas's MST : "<<boruvkaMST(G)<<endl;
}
/*
5
5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/
