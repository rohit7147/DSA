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
node *constructTree(int [],int [],int,int );
int search(int [],int,int,int);
void display(node *);
int main()
{
    node *root=NULL;
    int in[max],post[max],start=0,end=max-1,i;
    for(i=0;i<max;i++)
        cin>>in[i];
    for(i=0;i<max;i++)
        cin>>post[i];
    root=constructTree(in,post,start,end);
    display(root);
}
node *constructTree(int in[],int post[],int start,int end)
{
    if(start>end)
        return 0;
    static int preIndex=end;
    node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=post[preIndex--];
    tmp->lt=tmp->rt=NULL;
    if(start==end)
        return tmp;
    int Index=search(in,tmp->info,start,end);
    tmp->rt=constructTree(in,post,Index+1,end);
    tmp->lt=constructTree(in,post,start,Index-1);
    return tmp;
}
int search(int in[],int val,int start,int end)
{
    int i;
    for(i=0;i<max;i++)
        if(in[i]==val)
            return i;
}
void display(node *root)
{
    if(root==NULL)
        return;
    cout<<root->info<<" ";
    display(root->lt);
    display(root->rt);
}
