#include<iostream>
#include<stdlib.h>
#include<list>
#include<queue>
#include<vector>
using namespace std;
struct Graph
{
    int E;
    int V;
    list<int> *adj;
};
int isEulerianPathOrEulerianCycle(struct Graph *G)
{
    if(G->E == 0)
        return 2;
    list<int>::iterator it;
    vector<int> degree(G->V,0);
    vector<int> visited(G->V,0);
    queue<int> q;
    q.push(0);
    visited[0]=1;
    while(!q.empty())
    {
        int i=q.front();
        for(it=G->adj[i].begin();it!=G->adj[i].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=1;
                q.push(*it);
            }
            degree[*it]++;
        }
        q.pop();
    }
    int oddDegree=0,evenDegree=0;
    for(int i=0;i<G->V;i++)
    {
        if(degree[i]%2==0)
            evenDegree++;
        else
            oddDegree++;
    }
    if(evenDegree == G->V)
        return 2;
    else if(oddDegree == 0 || oddDegree == 2)
        return 1;
    else
        return 0;
}
void addEdge(struct Graph *G)
{
    int src,dest;
    cin>>src>>dest;
    G->adj[src].push_back(dest);
    G->adj[dest].push_back(src);
}
void createGraph(struct Graph **G)
{
    (*G)=(struct Graph *)malloc(sizeof(struct Graph));
    cin>>(*G)->V>>(*G)->E;
    (*G)->adj=new list<int>[(*G)->V];
}
int main()
{
    struct Graph *G=NULL;
    createGraph(&G);
    for(int i=0;i<G->E;i++)
        addEdge(G);
    if(isEulerianPathOrEulerianCycle(G) == 0)
        cout<<"\nGraph is not Eulerian\n";
    else if(isEulerianPathOrEulerianCycle(G) == 1)
        cout<<"\nGraph has Eulerian Path\n";
    else
        cout<<"\nGraph has Eulerian Cycle\n";
}
/*
88 13
12 28
67 17
0 26
30 11
38 85
57 60
57 15
75 31
65 80
75 19
68 67
73 84
63 86
*/
/*
5
5
1 0
0 2
2 1
0 3
3 4
*/
/*
5
6
1 0
0 2
2 1
0 3
3 4
4 0
*/
/*
5
6
1 0
0 2
2 1
0 3
3 4
1 3
*/
