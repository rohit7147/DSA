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
void lowestCommonAncestor(struct node *);
int main()
{
    struct node *root=NULL;
    int i,val,a,b;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>a>>b;
    lowestCommonAncestor(root,a,b);
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
void lowestCommonAncestor(struct node *root,int a,int b)
{
    if(root==NULL)
        return;
    if(root->rt && root->lt)

}
