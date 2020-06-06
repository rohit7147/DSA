#include<iostream>
#include<cstdlib>
#include<queue>
#include<random>
#define max 15
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
void LevelOrderTraversal(struct node *root)
{
    if(root==NULL) return;
    queue <node *> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *curr=q.front();
        cout<<curr->info<<" ";
        if(curr->lt)
            q.push(curr->lt);
        if(curr->rt)
            q.push(curr->rt);
        q.pop();
    }
    cout<<endl;
}
struct node *bst(struct node *root,int val)
{
    if(root==NULL)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->lt=tmp->rt=NULL;
        tmp->info=val;
        root=tmp;
    }
    else if(val>=root->info)
        root->rt=bst(root->rt,val);
    else
        root->lt=bst(root->lt,val);
    return root;
};
int main()
{
    struct node *root=NULL;
    int i,val,level=1;
    cout<<"Inserting 15 random values in the binary tree..."<<endl;
    for(i=0;i<max;i++)
    {
        val=rand();
        root=bst(root,val);
    }
    cout<<"Level order traversal of random binary tree..."<<endl;
    LevelOrderTraversal(root);
}
