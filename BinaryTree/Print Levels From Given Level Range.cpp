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
void printNodes(node *,int ,int ,int );
int main()
{
    struct node *root=NULL;
    int i,val,level=1,low,high;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>low>>high;
    printNodes(root,low,high,level);
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
void printNodes(node *root,int low,int high,int level)
{
    if(root==NULL || level>high)
        return;
    if(low<=level && level<=high)
    {
        cout<<"\n"<<root->info<<" "<<level;
    }
    printNodes(root->lt,low,high,level+1);
    printNodes(root->rt,low,high,level+1);
}
