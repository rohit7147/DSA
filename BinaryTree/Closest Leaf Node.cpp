#include<iostream>
#include<stdlib.h>
#include<climits>
#define max 7
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
node *Insert(node *,int);
int findClosestLeaf(node *,int);
int findLeaf(node *,int,node * [],int );
int findDown(node *);
int getmin(int,int);
node *tmp;
int main()
{
    node *root=NULL;
    int i,val,key;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>key;
    cout<<"Closest Leaf to "<<key<<" is "<<tmp->info<<" At Distance "<<findClosestLeaf(root,key);

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
int findClosestLeaf(node *root,int key)
{
    node *ancestors[max];
    return findLeaf(root,key,ancestors,0);
}
int findLeaf(node *root,int key,node *ancestors[],int index)
{
    if(root==NULL)
        return INT_MAX;
    if(root->info==key)
    {
        int res=findDown(root);
        for(int i=index-1;i>=0;i--)
            res=getmin(res,index-i+findDown(ancestors[i]));
        return res;
    }
    ancestors[index]=root;
    getmin(findLeaf(root->lt,key,ancestors,index+1),findLeaf(root->rt,key,ancestors,index+1));
}
int findDown(node *root)
{
    if(root==NULL)
        return INT_MAX;
    if(!root->lt && !root->rt)
    {
        tmp=root;
        return 0;
    }
    return 1+getmin(findDown(root->lt),findDown(root->rt));
}
int getmin(int x,int y)
{
    return (x<y)?x:y;
}
