#include<iostream>
#include<stdlib.h>
#define max 7
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *Insert(struct node *,int);
struct node *extractLeafNodes(struct node *,struct node **);
void displayDoublyLinkedList(struct node *);
void displayInorder(struct node *);
int main()
{
    struct node *root=NULL,*start=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cout<<"\nInorder Display of Binary tree\n\n";
    displayInorder(root);
    root=extractLeafNodes(root,&start);
    cout<<"\n\nDoubly Linked List Display\n\n";
    displayDoublyLinkedList(start);
    cout<<"\n\nModified Tree\n\n";
    displayInorder(root);
    cout<<"\n";
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
struct node *extractLeafNodes(struct node *root,struct node **start)
{
    if (root == NULL)
        return NULL;
    if(!root->lt && !root->rt)
    {
        root->rt = *start;
        if (*start != NULL)
            (*start)->lt = root;
        *start = root;
        return NULL;
    }
    root->rt = extractLeafNodes(root->rt,start);
    root->lt = extractLeafNodes(root->lt,start);
    return root;
};
void displayInorder(struct node *root)
{
    if(root==NULL)
        return;
    displayInorder(root->lt);
    cout<<root->info<<" ";
    displayInorder(root->rt);
}
void displayDoublyLinkedList(struct node *start)
{
    while(start!=NULL)
    {
        cout<<start->info<<" ";
        start=start->rt;
    }
}
//20 15 25 22 10 30 17
