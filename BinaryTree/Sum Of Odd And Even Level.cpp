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
int findGreater(struct node *);
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    if(findGreater(root))
        cout<<"Even Level is Greater\n";
    else
        cout<<"Odd Level is Greater\n";
}
struct node *Insert(struct node *root,int val)
{
    if(root==NULL)
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
int findGreater(struct node *root)
{
    if(root==NULL)
        return 0;
    queue <node *> q;
    int nodeCount,height=0,OddSum=0,EvenSum=0;
    q.push(root);
    while(1)
    {
        nodeCount=q.size();
        if(nodeCount==0)
        {
            cout<<"\n"<<"Sum of Odd Level : "<<OddSum<<"\t"<<"Sum of Even Level : "<<EvenSum<<"\n";
            if(EvenSum>OddSum)
                return 1;
            else
                return 0;
        }
        height++;
        while(nodeCount>0)
        {
            struct node *curr=q.front();
            if(height%2==0)
                EvenSum=EvenSum+curr->info;
            else
                OddSum=OddSum+curr->info;
            if(curr->lt)
                q.push(curr->lt);
            if(curr->rt)
                q.push(curr->rt);
            q.pop();
            nodeCount--;
        }
    }
}
