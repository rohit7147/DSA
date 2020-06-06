#include<iostream>
#include<stdlib.h>
#define max 7
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *Insert(struct node*,int);
void DisplayInorder(struct node *);
void binaryTree2Dll(struct node *,struct node **);
void DisplayDll(struct node *);
int main()
{
    struct node *root=NULL,*start=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    DisplayInorder(root);
    binaryTree2Dll(root,&start);
    DisplayDll(start);
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
void binaryTree2Dll(struct node *root,struct node **start)
{
    if(root==NULL)
        return;
    static struct node *prev=NULL;
    binaryTree2Dll(root->lt,start);

    if(*start==NULL)
        *start=root;
    else
    {
        root->lt=prev;
        prev->rt=root;
    }
    prev=root;
    binaryTree2Dll(root->rt,start);
};
void DisplayInorder(struct node *root)
{
    if(root==NULL)
        return;
    DisplayInorder(root->lt);
    cout<<root->info<<" ";
    DisplayInorder(root->rt);
}
void DisplayDll(struct node *start)
{
    if(start==NULL)
        return;
    cout<<"\n";
    while(start!=NULL)
    {
        cout<<start->info<<" ";
        start=start->rt;
    }
}
