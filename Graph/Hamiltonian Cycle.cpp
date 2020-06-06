#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    list<int> *adj;
};
void createGraph(struct Graph *G)
{
    cin>>G->V>>G->E;
    G->adj=new list<int>[G->V];
}
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src-1].push_back(dest-1);
    G->adj[dest-1].push_back(src-1);
}
int isHamiltonian(struct Graph *G,int source)
{
    list<int>::iterator it;
    int count=1;
    stack<int> s;
    vector<bool> visited(G->V,false);
    s.push(source);
    visited[source]=true;
    while(!s.empty())
    {
        int src=s.top();
        for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                s.push(*it);
                count++;
                break;
            }
        }
        if(it == G->adj[src].end())
        {
            if(count!=G->V)
                return 0;
            else return 1;
        }
    }
}
int main()
{
    struct Graph *G=new Graph;
    createGraph(G);
    for(int i=0;i<G->E;i++)
        addEdge(G);
    int flag=0;
    for(int i=0;i<G->V;i++)
        if(isHamiltonian(G,i))
        {
            flag=1;
            break;
        }
    if(flag)cout<<1;
    else cout<<0;
    cout<<endl;
}
/*
10 14
2 1 10 2 6 3 5 4 10 5 10 6 6 7 6 8 10 9 4 9 3 8 3 7 5 9 6 5
*/
/*
5
7
0 1
0 3
1 2
1 3
1 4
2 4
3 4
*/
/*
4 4
1 2
2 3
3 4
2 4
*/
/*
5
6
0 1
0 3
1 2
1 3
1 4
2 4
*/
/*
5
6
0 1
0 2
1 3
1 4
2 3
3 4
*/
