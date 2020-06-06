#include<iostream>
#include<stdlib.h>
#include<stack>
#define max 7
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *Insert(struct node *,int);
void PreOrderTraversal(struct node *);
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    PreOrderTraversal(root);
}
struct node *Insert(struct node *root,int data)
{
    if(root == NULL)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->lt=tmp->rt=NULL;
        tmp->info=data;
        root=tmp;
    }
    else if(data <= root->info)
        root->lt=Insert(root->lt,data);
    else
        root->rt=Insert(root->rt,data);
    return root;
}
void PreOrderTraversal(struct node *root)
{
    stack<struct node *> s;
    while(1)
    {
        if(root)
        {
            s.push(root);
            cout<<root->info<<" ";
            root=root->lt;
        }
        else
        {
            if(!s.empty())
            {
                root=s.top();
                s.pop();
                root=root->rt;
            }
            else
                break;
        }
    }
}


