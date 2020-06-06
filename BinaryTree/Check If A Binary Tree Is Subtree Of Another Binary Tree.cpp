#include<iostream>
#include<stdlib.h>
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
        Insert(root,val);
    }
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
