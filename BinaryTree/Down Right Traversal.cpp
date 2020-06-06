#include<iostream>
#include<stdlib.h>
#include<queue>
#define max 6
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *Insert(struct node *,int);
void display(node *);
void downRight(node *);
node *newNode(int );
void inorderTraversal(node *);
int main()
{
    struct node *root=NULL;
    int i,val;
    root=newNode(1);
    root->lt=newNode(2);
    root->rt=newNode(3);
    root->rt->lt=newNode(4);
    root->rt->rt=newNode(5);
    root->rt->lt->lt=newNode(6);
    root->rt->rt->lt=newNode(7);
    root->rt->rt->rt=newNode(8);
    /*for(i=0;i<max;i++)
    {
        cin>>val;
        //root=Insert(root,val);
    }*/
    inorderTraversal(root);

    downRight(root);
    cout<<"Traversal of the tree converted to down-right form"<<endl;
    display(root);
}
node *newNode(int val)
{
    node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->lt=tmp->rt=NULL;
    tmp->info=val;
    return tmp;
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
}
void downRight(node *root)
{
    if(root==NULL)
        return;
    queue <node *> q;
    queue <int>    l;
    int level=1;
    node *curr,*prev=NULL;
    q.push(root);
    l.push(level);
    while(!q.empty())
    {
        curr=q.front();
        level=l.front();
        q.pop();
        l.pop();
        if(curr->lt)
        {
            q.push(curr->lt);
            l.push(level+1);
        }
        if(curr->rt)
        {
            q.push(curr->rt);
            l.push(level+1);
        }
        if(q.size() && level == l.front() && (prev->rt != q.front() && prev->lt != q.front()))
            curr->rt=q.front();
        else
            curr->rt=NULL;
        prev=curr;
    }
}
void display(node *root)
{
    if(!root)
        return;
    cout<<"root->info : "<<root->info<<" ";
    if(root->lt)
        cout<<"root->lt->info : "<<root->lt->info<<" ";
    if(root->rt)
        cout<<"root->rt->info : "<<root->rt->info<<" ";
    cout<<endl;
    display(root->rt);
    display(root->lt);
}
void inorderTraversal(node *root)
{
    if(!root)
        return;
    cout<<"root->info : "<<root->info<<" ";
    if(root->lt)
        cout<<"root->lt->info : "<<root->lt->info<<" ";
    if(root->rt)
        cout<<"root->rt->info : "<<root->rt->info<<" ";
    cout<<endl;
    inorderTraversal(root->lt);
    inorderTraversal(root->rt);
}
