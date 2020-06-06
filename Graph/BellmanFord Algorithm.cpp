#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct Graph
{
    int V;
    int E;
    vector<pair<int,pair<int,int> > > edge;
};
void BellmanFordShortestPath(struct Graph *G,int src)
{
    int E=G->E,V=G->V;
    vector<pair<int,pair<int,int> > >::iterator it;
    vector<int> dist(V,INF);
    dist[0]=0;
    for(int i=0;i<V-1;i++)
    {

        for(it=G->edge.begin();it!=G->edge.end();it++)
        {
            int wt=(*it).first;
            int u=(*it).second.first;
            int v=(*it).second.second;
            if(dist[v] > dist[u] + wt)
                dist[v]=dist[u]+wt;
        }
    }
    for(it=G->edge.begin();it!=G->edge.end();it++)
    {
            int wt=(*it).first;
            int u=(*it).second.first;
            int v=(*it).second.second;
            if(dist[v] > dist[u] + wt)
            {
                cout<<"\nGraph Contains negative Wait Cycle\n";
                return;
            }
    }
    cout<<"\nDistance of All Vertex from "<<src<<" is\n";
    cout<<"\nVertex \t\t Distance\n";
    for (int i = 0; i < G->V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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
    int src;
    cin>>src;
    BellmanFordShortestPath(G,src);
}
/*
5
8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0
*/
