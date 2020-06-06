#include<iostream>
#include<stdlib.h>
#include<set>
#include<list>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
struct Graph *createGraph()
{
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>G->V>>G->E;
    G->adj=new list<int>[G->V];
    return G;
};
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src].push_back(dest);
    G->adj[dest].push_back(src);
}
int isBipartite(struct Graph *G)
{
    int i,visited[G->V];
    set<int> s1,s2;
    list<int>::iterator it;
    for(i=0;i<G->V;i++)
    {
        if(i%2==0)
        {
            s1.insert(i);
            for(it=G->adj[i].begin();it!=G->adj[i].end();it++)
                s2.insert(*it);
        }
        else
        {
            s2.insert(i);
            for(it=G->adj[i].begin();it!=G->adj[i].end();it++)
                s1.insert(*it);
        }
    }
    set<int>::iterator p,q;
    p=s1.begin();
    q=s2.begin();
    while(p!=s1.end() && q!=s2.end())
    {
        if(*q==*p)
            return 0;
        p++;
        q++;
    }
    return 1;
    cout<<endl<<endl;
}
int main()
{
    struct Graph *G=NULL;
    G=createGraph();
    for(int i=0;i<G->E;i++)
        addEdge(G);
    if(isBipartite(G))
        cout<<"Bipartite Graph";
    else
        cout<<"Not a Bipartite Graph";
}
