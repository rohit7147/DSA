#include<iostream>
#include<stdlib.h>
#define max 7
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
node *Insert(node *,int);
node *removeNodesSmallerThanK(node *,int,int);
node *newNode(int );
void display(node *);
int main()
{
    node *root=NULL;
    int i,val,k,pathlen=1;
    root = newNode(1);
    root->lt = newNode(2);
    root->rt = newNode(3);
    root->lt->lt = newNode(4);
    root->lt->rt = newNode(5);
    root->lt->lt->lt = newNode(7);
    root->rt->rt = newNode(6);
    root->rt->rt->lt = newNode(8);
    /*for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }*/
    cin>>k;
    root=removeNodesSmallerThanK(root,pathlen,k);
    display(root);
}
node *newNode(int val)
{
    node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->lt=tmp->rt=NULL;
    tmp->info=val;
    return tmp;
}
node *Insert(node *root,int val)
{
    if(root==NULL)
    {
        node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->lt=tmp->rt=NULL;
        tmp->info=val;
        root=tmp;
    }
    else if(val>root->info)
        root->rt=Insert(root->rt,val);
    else
        root->lt=Insert(root->lt,val);
    return root;
}
node *removeNodesSmallerThanK(node *root,int pathlen,int k)
{
    if(!root)
        return 0;
    root->lt = removeNodesSmallerThanK(root->lt,pathlen+1,k);
    root->rt = removeNodesSmallerThanK(root->rt,pathlen+1,k);
    if(!root->lt && !root->rt)
    {
        if(pathlen<k)
        {
            free(root);
            return 0;
        }
        else
            return root;
    }
    return root;
}
void display(node *root)
{
    if(!root)
        return;
    cout<<root->info<<" ";
    display(root->lt);
    display(root->rt);
}
