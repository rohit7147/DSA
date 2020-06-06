#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    vector<pair<int,pair<int,int> > > edge;
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
    G->edge.push_back(make_pair(wt,make_pair(src-1,dest-1)));
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
    sort(G->edge.begin(),G->edge.end());
    vector<pair<int,pair<int,int> > >::iterator it;
    //cout<<"\n Edge   Wt"<<endl;
    for(it=G->edge.begin();it!=G->edge.end();it++)
    {
        int src=(*it).second.first;
        int dest=(*it).second.second;
        int x=findSet(ss,src);
        int y=findSet(ss,dest);
        if(x!=y)
        {
            //cout<<src<<"-"<<dest<<"  :  "<<(*it).first<<endl;
            wtMST=wtMST+(*it).first;
            unionSet(ss,x,y);
        }
    }
    return wtMST;
}
int main()
{
    float n,power;
   cout<<"Enter a number: ";
   cin>>n;
   power=n*n*n*n*n*n;
   cout<<"power : "<<power<<endl;
    /*struct Graph *G=NULL;
    G=createGraph();
    for(int i=0;i<G->E;i++)
        addEdge(G);
    cout<<"Min Wt : "<<kruskalMST(G);*/
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
