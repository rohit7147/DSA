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
struct node *Truncate(struct node *,int);
void display(struct node *);
int temp[max],len=0;
int main()
{
    struct node *root=NULL;
    int i,val,k;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>k;
    root=Truncate(root,k);
    cout<<"\nTree After Truncation\n";
    display(root);
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
struct node *Truncate(struct node *root,int k)
{
    if(root==NULL)
        return 0;
    static int sum=0;
    sum=sum+root->info;
    root->lt=Truncate(root->lt,k);
    root->rt=Truncate(root->rt,k);
    cout<<"\nSum : "<<sum;
    if(!root->rt && !root->lt)
    {
        if(sum<k)
        {
            sum=sum-root->info;
            free(root);
            return NULL;
        }
    }
    return root;
}
void display(struct node *root)
{
    if(root==NULL)
        return;
    cout<<root->info<<" ";
    display(root->lt);
    display(root->rt);
}
