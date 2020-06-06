#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    vector<pair<pair<int,int>,int> > edge;
};
struct subset
{
    int parent;
    int rank;
};
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest,wt;
    cin>>src>>dest>>wt;
    G->edge.push_back({{src,dest},wt});
}
void createSubset(struct subset *ss,int V)
{
    int i;
    for(i=0;i<V;i++)
    {
        ss[i].parent=i;
        ss[i].rank=0;
    }
}
int findSet(struct subset *ss,int data)
{
    if(ss[data].parent!=data)
        ss[data].parent=findSet(ss,ss[data].parent);
    return ss[data].parent;
}
void unionSet(struct subset *ss, int x,int y)
{
    int xroot=findSet(ss,x);
    int yroot=findSet(ss,y);
    if(ss[xroot].rank > ss[yroot].rank)
        ss[yroot].parent=xroot;
    else if(ss[xroot].rank < ss[yroot].rank)
        ss[xroot].parent=yroot;
    else
    {
        ss[yroot].parent=xroot;
        ss[xroot].rank++;
    }
}
int kruskalMST(struct Graph *G)
{
    int V=G->V;
    int wtMST=0;
    struct subset *ss=(struct subset *)malloc(V * sizeof(struct subset));
    createSubset(ss,V);
    sort(G->edge.begin(), G->edge.end());
    vector<pair<pair<int,int>,int> >::iterator it;
    for(it=G->edge.begin();it!=G->edge.end();it++)
    {
        int src=(*it).first.first;
        int dest=(*it).first.second;
        int x=findSet(ss,src);
        int y=findSet(ss,dest);
        if(x!=y)
        {
            cout<<src<<"-"<<dest<<" : "<<(*it).second;
            wtMST=wtMST+(*it).second;
            unionSet(ss,x,y);
        }
    }
    return wtMST;
}
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    for(int i=0;i<G->V;i++)
        addEdge(G);
    cout<<kruskalMST(G);
}
