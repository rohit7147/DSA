#include<bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
struct Graph
{
    int V;
    int E;
    list<pair<int,int> > *adj;
};
void dijkstraShortestPath(struct Graph *G,int src,int dest)
{
    typedef pair<int,int> iPair;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    list<pair<int,int> >::iterator it;
    vector<int> dist(G->V,INF);
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(it=G->adj[u].begin();it!=G->adj[u].end();it++)
        {
            int v=(*it).second;
            int wt=(*it).first;
            if(dist[v] > dist[u] + wt)
            {
                dist[v]=dist[u]+wt;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    cout<<"Distance of "<<dest<<" from "<<src<<" : ";
    cout<<dist[dest]<<endl;
    int sum=0;
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < G->V; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
        sum=sum+dist[i];
    }
    printf("%d",sum);
}
void addEdge(struct Graph *G)
{
    int src,dest,wt;
    cin>>src>>dest>>wt;
    G->adj[src].push_back(make_pair(wt,dest));
    G->adj[dest].push_back(make_pair(wt,src));
}
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    G->adj=new list<pair<int,int> >[G->V];
    return G;
};
int main()
{
    struct Graph *G=NULL;
    int i,src,dest;
    G=createGraph();
    for(i=0;i<G->E;i++)
        addEdge(G);
    cin>>src>>dest;
    dijkstraShortestPath(G,src,dest);
}
/*
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
/*
5
9
0 1 1
0 2 2
0 3 3


*/
