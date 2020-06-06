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
void reverseAlternateLevel(node *,int);
void displayInOrder(node *);
int main()
{
    node *root=NULL;
    int i,val,level=1;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cout<<"Inorder Traversal\n";
    displayInOrder(root);
    reverseAlternateLevel(root,level);
    cout<<"\nModified Tree\n";
    displayInOrder(root);
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
void reverseAlternateLevel(node *root,int level)
{
    if(root==NULL)
        return;
    int tmp;
    if(level%2!=0 && root->lt && root->rt)
    {
        tmp=root->lt->info;
        root->lt->info=root->rt->info;
        root->rt->info=tmp;
    }
    reverseAlternateLevel(root->lt,level+1);
    reverseAlternateLevel(root->rt,level+1);
}
void displayInOrder(node *root)
{
    if(root==NULL)
        return;
    displayInOrder(root->lt);
    cout<<root->info<<" ";
    displayInOrder(root->rt);
}
