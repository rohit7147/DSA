#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
void createGraph(struct Graph **G,int rG)
{
    *G=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>(*G)->V;
    if(rG)
        cin>>(*G)->E;
    (*G)->adj=new list<int>[(*G)->V];
}
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src].push_back(dest);
}
void dfs(struct Graph *G,vector<int> &visited,stack<int> &s)
{
    list<int>::iterator it;
    while(!s.empty())
    {
        int u=s.top();
        for(it=G->adj[u].begin();it!=G->adj[u].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=1;
                cout<<*it<<" ";
                s.push(*it);
                break;
            }
        }
        if(it == G->adj[u].end())
            s.pop();
    }
    cout<<endl;
}
struct Graph *reverseGraph(struct Graph *G)
{
    int i;
    list<int>::iterator it;
    struct Graph *rG=NULL;
    createGraph(&rG,0);
    for(i=0;i<G->V;i++)
    {
        for(it=G->adj[i].begin();it!=G->adj[i].end();it++)
             rG->adj[*it].push_back(i);
    }
    return rG;
};
int isStronglyConnected(struct Graph *G)
{
    stack<int> s;
    int i;
    vector<int> visited(G->V,0);
    s.push(0);
    visited[0]=1;
    dfs(G,visited,s);
    for(int i=0;i<G->V;i++)
    if(visited[i]==0)
    {
        cout<<"\nreturned 0 dfs 1\n";
        return 0;
    }
    G=reverseGraph(G);
    for(int i=0;i<G->V;i++)
        visited[i]=0;
    s.push(0);
    visited[0]=1;
    dfs(G,visited,s);
    for(int i=0;i<G->V;i++)
        if(visited[i]==0)
            {
                cout<<"\nreturned 0 dfs 2\n";
                return 0;
            }
    return 1;
}
int main()
{
    struct Graph *G=NULL;
    createGraph(&G,1);
    for(int i=0;i<G->E;i++)
        addEdge(G);
    isStronglyConnected(G)?cout<<"Yes" : cout<<"No";
    return 0;
}
/*
5
6
0 1
1 2
2 3
3 0
2 4
4 2
*/
