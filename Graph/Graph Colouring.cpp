#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
void createGraph(struct Graph *G,int V,int E)
{
    G->V=V;
    G->E=E;
    G->adj=new list<int>[G->V];
}
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src-1].push_back(dest-1);
    G->adj[dest-1].push_back(src-1);
}
int colorGraph(struct Graph *G,int m)
{
    int i,flag,min_visited,max_visited;
    list<int>::iterator it;
    vector<int> res(G->V,-1);
    res[0]=0;
    for(i=1;i<G->V;i++)
    {
        flag=0;
        it=G->adj[i].begin();
        res[i]=0;
        for(it=G->adj[i].begin();it!=G->adj[i].end();it++)
        {
            if(res[*it]!=-1)
            {
                if(res[i]==res[*it])
                    res[i]=res[*it]+1;
            }
        }
    }
    set<int> s;
    for(i=0;i<G->V;i++)
        s.insert(res[i]);
    if(s.size() <= m)
        return 1;
    else
        return 0;

}
void sortGraph(struct Graph *G)
{
    int i;
    list<int>::iterator it;
    for(i=0;i<G->V;i++)
        G->adj[i].sort();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Graph *G = new Graph;
        int m,v,e;
        cin>>v>>m>>e;
        createGraph(G,v,e);
        for(int i=0;i<G->E;i++)
            addEdge(G);
        sortGraph(G);
        if(colorGraph(G,m))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
}
