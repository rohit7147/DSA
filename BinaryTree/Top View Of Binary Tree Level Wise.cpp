#include<iostream>
#include<stdlib.h>
#include<map>
#include<queue>
#define max 7
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
node *Insert(node *root,int val)
{
    if(root==NULL)
    {
        node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->lt=tmp->rt=NULL;
        tmp->info=val;
        root=tmp;
    }
    else if(val > root->info)
        root->rt=Insert(root->rt,val);
    else
        root->lt=Insert(root->lt,val);
    return root;
}
void topView(node *root,int horizontalDistance)
{
    if(!root)
        return;
    queue<node *> q;
    queue<int> hd;
    map<int,int> m;
    q.push(root);
    hd.push(0);
    while(!q.empty())
    {
        node *curr=q.front();
        int horiDist=hd.front();
        if(m[horiDist]==0)
        {
            cout<<curr->info<<" ";
            m[horiDist]=1;
        }
        if(curr->lt)
        {
            q.push(curr->lt);
            hd.push(horiDist-1);
        }
        if(curr->rt)
        {
            q.push(curr->rt);
            hd.push(horiDist+1);
        }
        q.pop();
        hd.pop();
    }
}
int main()
{
    node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    topView(root,0);
    cout<<endl;
}
