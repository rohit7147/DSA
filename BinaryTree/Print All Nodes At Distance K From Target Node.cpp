#include<iostream>
#include<stdlib.h>
#define max 15
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
node *Insert(node *,int);
int printKNodesFromTargetNodes(node *,int,int);
void printDown(node *,int);
int main()
{
    node *root=NULL;
    int i,val,target,k;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>target;
    cin>>k;
    cout<<"\n"<<printKNodesFromTargetNodes(root,target,k);
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
int printKNodesFromTargetNodes(node *root,int target,int k)
{
    if(root==NULL)
        return -1;
    if(root->info==target)
    {
        printDown(root,k);
        return 0;
    }
    int dl=printKNodesFromTargetNodes(root->lt,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
            cout<<root->info<<" ";
        else
            printDown(root->rt,k-dl-2);
        return dl+1;
    }
    int dr=printKNodesFromTargetNodes(root->rt,target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
            cout<<root->info<<" ";
        else
            printDown(root->lt,k-dr-2);
        return dr+1;
    }
    return -1;
}
void printDown(node *root,int k)
{
    if(root==NULL || k<0)
        return;
    if(k==0)
    {
        cout<<root->info<<" ";
        return;
    }
    printDown(root->lt,k-1);
    printDown(root->rt,k-1);
}
//20 8 22 4 12 10 14
//50 25 100 12 18 10 14 17 22 16 20 24 15 19 23
