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
void findDistanceFromLeaf(node *,int,int [],int);
int visited[max];
int main()
{
    node *root=NULL;
    int i,val,k,a[max],len=0;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>k;
    cout<<"Nodes At distance "<<k<<" From Leaf are : ";
    findDistanceFromLeaf(root,k,a,len);
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
void findDistanceFromLeaf(node *root,int k,int path[],int len)
{
    if(root==NULL)
        return;
    path[len]=root->info;
    visited[len]=0;
    len++;
    if(!root->rt && !root->lt && len-k-1>=0 && visited[len-1-k]==0)
    {
        cout<<path[len-1-k]<<" ";
        visited[len-1-k] = 1;

    }
    else
    {
        findDistanceFromLeaf(root->lt,k,path,len);
        findDistanceFromLeaf(root->rt,k,path,len);
    }
}
//5 2 3 1 7 6 8
