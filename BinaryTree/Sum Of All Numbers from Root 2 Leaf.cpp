#include<iostream>
#include<math.h>
#include<stdlib.h>
#define max 5
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *Insert(struct node *,int);
int rootLeaf(struct node *,int);
int a[max],len=0,sum=0;
int main()
{
    struct node *root=NULL,*start=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cout<<"Sum is "<<rootLeaf(root,len);
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
int rootLeaf(struct node *root,int len)
{
    if(root==NULL)
        return 0;
    a[len]=root->info;
    len++;
    if(root->lt==NULL && root->rt==NULL)
    {
        int i=0;
        while(len-1>=0)
        {
            sum=sum+a[len-1]*pow(10,i);
            len--;
            i++;
        }
    }
    else
    {
        rootLeaf(root->lt,len);
        rootLeaf(root->rt,len);
    }
    return sum;
}
// 5 2 1 3 7 6 8
