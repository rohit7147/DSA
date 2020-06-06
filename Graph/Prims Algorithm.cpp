#include<bits/stdc++.h>
# define MAX_INT 0x3f3f3f3f
using namespace std;
struct Graph
{
    int V;
    int E;
    list<pair<int,int> > *adj;
};
void primsMST(struct Graph *G)
{
    typedef pair<int,int> iPair;
    priority_queue<iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> key(G->V,MAX_INT);
    vector<int> parent(G->V,-1);
    vector<bool> inMST(G->V, false);
    int src=0;
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;
        list< pair<int, int> >::iterator i;
        for (i = G->adj[u].begin(); i != G->adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    list< pair<int, int> >::iterator it;
    printf("\n Edge     Wt\n");
    for (int i = 1; i < G->V; ++i)
    {
        it=G->adj[i].begin();
        printf("%d - %d  :  %d\n", parent[i], i,(*it).second);
    }
}
void addEdge(struct Graph *G)
{
    int src,dest,wt;
    cin>>src>>dest>>wt;
    G->adj[src].push_back(make_pair(dest,wt));
    G->adj[dest].push_back(make_pair(src,wt));
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
    G=createGraph();
    for(int i=0;i<G->E;i++)
        addEdge(G);
    primsMST(G);
}
/*
5
7
0 1 2
0 4 6
1 2 3
1 4 8
1 3 5
2 3 7
3 4 9
*/
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
