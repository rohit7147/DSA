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
void leftViewOfTree(struct node *,int);
void printLeftBoundry(struct node *);
int main()
{
    struct node *root=NULL;
    int i,val,level=1;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    leftViewOfTree(root,level);
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
void leftViewOfTree(struct node *root,int level)
{
    if(root==NULL)
        return;
    static int max_level=0;
    if(max_level<level)
    {
        cout<<root->info<<" ";
        max_level=level;
    }
    leftViewOfTree(root->lt,level+1);
    leftViewOfTree(root->rt,level+1);
}

