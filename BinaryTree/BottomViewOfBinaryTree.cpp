#include<bits/stdc++.h>
#define max 8
using namespace std;
struct node
{
    int info;
    int hd;
    node *lt,*rt;
};
node *Insert(node *root,int val)
{
    if(root == NULL)
    {
        node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->lt=tmp->rt=NULL;
        tmp->info=val;
        tmp->hd=0;
        root=tmp;
    }
    else if(val>root->info)
        root->rt=Insert(root->rt,val);
    else
        root->lt=Insert(root->lt,val);
    return root;
}
void printBottomView(map<int,int> &m)
{
    map<int,int>::iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<it->second<<" ";
        it++;
    }
    cout<<endl;
}
void bottomView(struct node *root)
{
    if(!root)
        return;
    queue<node *> q;
    map<int,int> m;
    q.push(root);
    int hd=0;
    while(!q.empty())
    {
        node *curr=q.front();
        m[curr->hd]=curr->info;
        if(curr->lt)
        {
            curr->lt->hd=(curr->hd)-1;
            q.push(curr->lt);
        }
        if(curr->rt)
        {
            curr->rt->hd=(curr->hd)+1;
            q.push(curr->rt);
        }
        q.pop();
    }
    printBottomView(m);
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
    bottomView(root);
};
/*
20 8 22 5 3 25 10 14
*/
