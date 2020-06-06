#include<iostream>
#include<stdlib.h>
#include<queue>
#define max 7
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt,*nr;
};
struct node *Insert(struct node *,int);
void nextRightKey(struct node *);

int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    nextRightKey(root);
}
struct node *Insert(struct node *root,int val)
{
    if(root == NULL)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->lt=tmp->rt=NULL;
        tmp->info=val;
        root=tmp;
    }
    else if(val>root->info)
        root->rt=Insert(root->rt,val);
    else
        root->lt=Insert(root->lt,val);
    return root;
};
void nextRightKey(struct node *root)
{
    if(root==NULL)
        return;
    queue <node *> qn;
    queue <int> q;
    int level=1;
    qn.push(root);
    q.push(level);
    while(qn.size())
    {
        node *curr=qn.front();
        level=q.front();
        qn.pop();
        q.pop();
        if(!qn.size())
            cout<<"\nNo right Key of "<<curr->info<<"\n";
        else if(level == q.front())
        {
            curr->nr=qn.front();
            cout<<"\nRight key of "<<curr->info<<" is "<<(qn.front())->info<<"\n";
        }
        else
            cout<<"\nNo right Key of "<<curr->info<<"\n";
        if(curr->lt)
        {
            qn.push(curr->lt);
            q.push(level+1);
        }
        if(curr->rt)
        {
            qn.push(curr->rt);
            q.push(level+1);
        }
    }
}
//20 15 17 10 25 22 30
