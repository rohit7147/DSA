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
int isFull(node *);
int main()
{
    node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    if(isFull(root))
        cout<<"Tree Is Full Tree"<<endl;
    else
        cout<<"Tree Is Not Full Tree"<<endl;
}
node *Insert(node *root,int val)
{
    if(root == NULL)
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
int isFull(node *root)
{
    if(!root)
        return 1;
    if(!root->lt && !root->rt)
        return 1;
    if(root->rt && root->lt)
    {
        int left  = isFull(root->lt);
        int right = isFull(root->rt);
        if(left && right)
            return 1;
    }
    return 0;
}
