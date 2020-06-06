#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
void reverseLevelOrderTraversal(struct node *root)
{
    queue <node *> q;
    stack <node *> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        struct node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            if(q.size()>0)
            {
                s.push(NULL);
                q.push(NULL);
            }
            continue;
        }
        s.push(curr);
        if(curr->lt)
            q.push(curr->lt);
        if(curr->rt)
            q.push(curr->rt);
    }
    while(!s.empty())
    {
        if(s.top()!=NULL)
        cout<<s.top()->info<<" ";
        else
            cout<<endl;
        s.pop();
    }
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
    else if(val<root->info)
        root->lt=bst(root->lt,val);
    else if(val>root->info)
        root->rt=bst(root->rt,val);
    return root;
};
void traverseTree(node *root)
{
    if (root == NULL)  return;
    queue<node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        node *node = q.front();
        cout<<node->info<<" ";
        q.pop();
        if (root->lt != NULL)
        {
            q.push(node->lt);
        }
        if (root->rt != NULL)
        {
            q.push(node->rt);
        }
        cout<<endl;
    }
}
void inorder(node *root)
{
    if(!root) return;
    inorder(root->lt);
    cout<<root->info<<" ";
    inorder(root->rt);
}
int main()
{
    struct node *root=NULL;
    int i,val,level=1;
    for(i=0;i<7;i++)
    {
        cin>>val;
        root=bst(root,val);
    }
    inorder(root);
    cout<<endl;
    traverseTree(root);
    //reverseLevelOrderTraversal(root);
}
/*
20 15 17 10 25 22 30
*/
