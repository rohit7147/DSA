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
void deepestLeftLeaf(struct node *,int,int,struct node **);

int main()
{
    struct node *root=NULL,*tmp=NULL;
    int i,val,k,len=0;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    int level=0;
    deepestLeftLeaf(root,level,0,&tmp);
    if(tmp!=NULL)
        cout<<"\nDeepest Left Leaf Node is : "<<tmp->info;
    else
        cout<<"\nNo Left Leaf Is Present In The Tree";
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
void deepestLeftLeaf(node *root, int lvl, int isLeft,struct node **tmp)
{
    if (root == NULL)
        return;
    static int maxlvl=0;
    if (isLeft && !root->lt && !root->rt && lvl > maxlvl)
    {
        maxlvl = lvl;
        *tmp=root;
        return;
    }
    deepestLeftLeaf(root->lt, lvl+1, 1,tmp);
    deepestLeftLeaf(root->rt, lvl+1, 0,tmp);
}
