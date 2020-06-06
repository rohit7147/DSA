#include<iostream>
#include<stdlib.h>
#include<queue>
#define max 7
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *Insert(struct node *,int);
int checkLeafLevel(struct node *);
int main()
{
    struct node *root=NULL;
    int i,val,k,len=0;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    if(checkLeafLevel(root))
        cout<<"\nLeafs Are At Same Level\n";
    else
        cout<<"\nLeafs Are Not At Same Level\n";
}
struct node *Insert(struct node *root,int val)
{
    if(root==NULL)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=val;
        tmp->lt=tmp->rt=NULL;
        root=tmp;
    }
    else if(val>root->info)
        root->rt=Insert(root->rt,val);
    else
        root->lt=Insert(root->lt,val);
    return root;
};
int checkLeafLevel(struct node *root)
{
    if(root==NULL)
        return 1;
    queue <node *> q;
    struct node *temp[max];
    struct node *curr,*prev=NULL;
    int flag=1,i=0;
    q.push(root);
    while(!q.empty())
    {
        curr=q.front();
        temp[i]=curr;
        i++;
        if(curr->lt)
            q.push(curr->lt);
        if(curr->rt)
            q.push(curr->rt);
        q.pop();
    }
    i=0;
    while(i<max)
    {
        curr=temp[i];
        if(!curr->lt && !curr->rt)
            break;
        i++;
    }
    while(i<max)
    {
        curr=temp[i];
        if(curr->lt || curr->rt)
        {
            flag=0;
            break;
        }
        i++;
    }
    if(flag==0)
        return 0;
    else
        return 1;
}
