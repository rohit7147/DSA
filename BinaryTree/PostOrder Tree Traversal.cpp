#include<iostream>
#include<stdlib.h>
#include<stack>
#define max 7
using namespace std;
int count=0;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *Insert(struct node *,int);
void PostOrderTraversal(struct node *);
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    PostOrderTraversal(root);
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
void PostOrderTraversal(struct node *root)
{
    stack<struct node *> s;
    struct node *tmp;
    while(1)
    {
        if(root)
        {
            s.push(root);
            root=root->lt;
        }
        else
        {
            root=s.top();
            if(root->rt)
            {
                tmp=root;
                root=root->rt;
                tmp->rt=NULL;
            }
            else
            {
                cout<<root->info<<" ";
                s.pop();
                if(s.empty())
                    break;
                root=s.top();
                tmp=root;
                root=root->rt;
                tmp->rt=NULL;
            }
        }
    }
}
//30 15 25 18 23 21 22
