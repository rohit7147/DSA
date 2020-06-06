#include<iostream>
#include<stdlib.h>
#include<stack>
#define max 7
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
node *Insert(node *,int);
int main()
{
    node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cout<<"\nBinary Tree\n";
    display(root);
    convertToThreadedBinaryTree(root);
    cout<<"\nInorder Traversal of Threaded Binary Tree\n";
    DisplayInorder(root);
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
        root->lt=Insert(root->lt,va);
    return root;
}
void convertToThreadedBinaryTree(node *root)
{
    if(root==NULL)
        return;
    stack <node *> s;
    push(root);
    convertToThreadedBinaryTree(root->lt);
    if(!root->rt)
    {
        s.pop();
        root->rt=s.top();
    }
    else
        s.pop();
    convertToThreadedBinaryTree(root->rt);
}
void display(node *root)
{
    if(root==NULL)
        return;
    display(root->lt);
    cout<<root->info<<" ";
    display(root->rt);
}
void displayInOrder(node *root)
{
    if(root==NULL)
        return;
    while(root->lt)
        root=root->lt;
    while(root!=NULL)
    {
        cout<<root->info<<" ";
        if(root->rt)
    }
}
