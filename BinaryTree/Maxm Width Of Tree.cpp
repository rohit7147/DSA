#include<stdio.h>
#include<stdlib.h>
#define max 5
struct node
{
    int info;
    struct node *lt,*rt;
};
int front=-1,rear=-1;
struct node *q[max];
struct node *Insert(struct node *,int);
void DoubleTree(struct node *);
void DisplayTree(struct node *);
void push(struct node *);
void pop();
int isEmpty();
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        scanf("%d",&val);
        root=Insert(root,val);
    }
    getMaxWidth(root);
}
struct node *Insert(struct node *root,int val)
{
    if(root==NULL)
    {
        struct node *tmp=malloc(sizeof(struct node));
        tmp->info=val;
        tmp->lt=tmp->rt=NULL;
        root=tmp;
    }
    else if(val>root->info)
        root->rt=Insert(root->rt,val);
    else
        root->lt=Insert(root->lt,val);
    return root;
};
int getMaxWidth(struct node *root)
{
    if(root==NULL)
        return 0;

}
