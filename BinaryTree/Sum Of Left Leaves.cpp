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
int sumOfLeftLeaves(node *,int);
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cout<<"Sum Of Left Leaves : "<<sumOfLeftLeaves(root,0);
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
int sumOfLeftLeaves(node *root,int isLeft)
{
    if(!root)
        return 0;
    static int sum=0;
    if(!root->lt && !root->rt && isLeft)
    {
        sum = sum+root->info;
        return sum;
    }
    sumOfLeftLeaves(root->lt,1);
    sumOfLeftLeaves(root->rt,0);
    return sum;
}
