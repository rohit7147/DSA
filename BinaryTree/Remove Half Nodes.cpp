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
node *removeHalfNodes(node *);
void display(node *);
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cout<<"Original Tree"<<endl;
    display(root);
    cout<<endl;
    root=removeHalfNodes(root);
    cout<<"\nModified Tree\n";
    display(root);
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
node *removeHalfNodes(node *root)
{
    if(root==NULL)
        return 0;
    node * left  = root->lt = removeHalfNodes(root->lt);
    node * right = root->rt = removeHalfNodes(root->rt);
    if(root->lt && !root->rt)
    {
        cout<<"Root Right freed : "<<root->info<<endl;
        free(root);
        return left;
    }
    else if(!root->lt && root->rt)
    {
        cout<<"Root Left freed : "<<root->info<<endl;
        free(root);
        return right;
    }
    else
    {
        cout<<"Root Returned : "<<root->info<<endl;
        return root;
    }
}
void display(node *root)
{
    if(!root)
        return;
    display(root->lt);
    cout<<root->info<<" ";
    display(root->rt);
}
//5 2 3 1 7 6 8
