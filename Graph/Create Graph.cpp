#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
struct Graph *createGraph(struct Graph *G,int V,int E)
{
    G=new Graph();
    G->V=V;
    G->E=E;
    G->adj=new list<int>[G->V];
    return G;
}
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src-1].push_back(dest-1);
}
void display(struct Graph *G)
{
    for(int i=0;i<G->V;i++)
    {
        list<int>::iterator it;
        cout<<i<<"->";
        for(it=G->adj[i].begin();it!=G->adj[i].end();it++)
        {
            cout<<*it<"->";
        }
        cout<<endl;
    }
}
int getComponent(struct Graph *G,int k,long long int a[])
{
    int i,count=0;
    stack<int> s;
    list<int>::iterator it;
    map<int,int> m;
    vector<bool> vis(G->V,false);
    for(i=0;i<G->V;i++)
    {
        s.push(i);
        cout<<"dfs"<<endl;
        m[i]++;
        vis[i]=true;
        while(!s.empty())
        {
            cout<<"while"<<endl;
            int src=s.top();
            s.pop();
            cout<<src<<endl;
            for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
            {
                if(!vis[*it])
                {
                    m[a[*it]]++;
                    if(m.size()<=k)
                        count++;
                    s.push(*it);
                    break;
                }
            }
            if(it==G->adj[src].end())
            {
                m[a[src]]--;
                if(m[src]==0)
                    m.erase(a[src]);
                s.pop();
            }
        }
        m.clear();
    }
    return count;
}
int main()
{
    int t,n,k,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        struct Graph *G=NULL;
        G=createGraph(G,n,n-1);
        for(i=0;i<G->E;i++)
            addEdge(G);
        display(G);
        cout<<getComponent(G,k,a)<<endl;
    }
}
