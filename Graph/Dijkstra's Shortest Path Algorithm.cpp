#include<bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
struct Graph
{
    int V;
    int E;
    list<pair<int,int> > *adj;
};
map<pair<int,int>,int> m;
int dijkstraShortestPath(struct Graph *G,int src,int k)
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
    int sum=0,count=0;
    //printf("Vertex   Distance from Source\n");
    for (int i = 0; i < G->V; ++i)
    {
        //printf("%d \t\t %d\n", i, dist[i]);
        pair<int,int> p1,p2;
        p1.first=src;
        p1.second=i;
        p2.first=i;
        p2.second=src;
        if(dist[i]==k && m.find(p1)==m.end() && m.find(p2)==m.end())
        {
            count++;
            m.insert(make_pair(p1,1));
            m.insert(make_pair(p2,1));
        }
    }
    return count;
}
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src-1].push_back(make_pair(1,dest-1));
    G->adj[dest-1].push_back(make_pair(1,src-1));
}
struct Graph *createGraph(int n,int k)
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    G->V=n;
    G->E=n-1;
    G->adj=new list<pair<int,int> >[G->V];
    return G;
};
int main()
{
    struct Graph *G=NULL;
    int i,n,k;
    cin>>n>>k;
    G=createGraph(n,k);
    for(i=0;i<G->E;i++)
        addEdge(G);
    int sum=0;
    for(i=0;i<G->V;i++)
        sum=sum+dijkstraShortestPath(G,i,k);
    cout<<sum;
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
