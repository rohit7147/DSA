#include <iostream>
#include<queue>
using namespace std;
struct tree
{
    int data;
    struct tree *left,*right;
};
tree *createtree(int data)
{
    tree *temp=new tree;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
struct tree *deepestnode(tree *root)
{
    if(root==NULL)
        return 0;
    queue<tree *> q;
    q.push(root);
    tree *temp;
    while(!q.empty())
    {

        temp=q.front();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        q.pop();
    }
    return temp;
}
int main()
{
    tree *root=createtree(1);
    root->left=createtree(2);
    root->right=createtree(3);
    root->left->left=createtree(4);
    root->left->right=createtree(5);
    root->left->right->left=createtree(6);
    root->left->right->left->right=createtree(7);
    tree *deep=deepestnode(root);
    cout<<deep->data;
    return 0;
}

