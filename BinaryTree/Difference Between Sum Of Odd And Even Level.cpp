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
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>val;
    printAncestors(root,val);
    printf("Difference Between Odd And Even Levels : %d",OddEvenDifference(root));
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
int OddEvenDifference(struct node *root)
{
    if(root==NULL)
        return 0;
    queue <node *> q;
    int OddSum=0,EvenSum=0;
    q.push(root);
    while(!q.empty())
    {
        struct node *curr=q.front();

    }
}
