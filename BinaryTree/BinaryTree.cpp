#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
void traverseTree(node *root)
{
    if(!root) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        if(curr!=NULL)
        {
            cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        else
        {
            cout<<endl;
            if(q.size()>0)
                q.push(NULL);
        }
    }
}
node *newNode(int val)
{
    node *tmp=new node();
    tmp->left=tmp->right=NULL;
    tmp->data=val;
    return tmp;
}
void add(node *root,int val,queue<node*> &q)
{
    if(!root->left)
    {
        root->left=newNode(val);
        q.push(root->left);
    }
    else if(!root->right)
    {
        root->right=newNode(val);
        q.push(root->right);
    }
    else
    {
        q.pop();
        add(q.front(),val,q);
    }
}
bool isBinarySearchTreeU(node *root,int *prev)
{
    if (root==NULL)
        return 1;
    int lt=isBinarySearchTreeU(root->left,prev);
    if(*prev==-1)
        *prev=root->data;
    else
    {
        if(root->data >= *prev)
            *prev=root->data;
        else
            return 0;
    }
    int rt=isBinarySearchTreeU(root->right,prev);
    if(lt&&rt)
        return 1;
    return 0;
}
bool isBinarySearchTree(node* root)
{
    int prev=-1;
    return isBinarySearchTreeU(root,&prev);
}
int main()
{
    int i,val,n;
    node *root=NULL;
    queue<node *> q;
    cout<<"Enter number of nodes to be inserted in the binary tree : ";
    cin>>n;
    cout<<"Enter "<<n<<" nodes : ";
    for(i=0;i<n;i++)
    {
        cin>>val;
        if(root==NULL)
        {
            root=newNode(val);
            q.push(root);
        }
        else
            add(q.front(),val,q);
    }
    cout<<"Level order traversal of binary tree"<<endl;
    traverseTree(root);
    if(isBinarySearchTree(root))
        cout<<"Entered binary tree is a binary search tree\n";
    else
        cout<<"Entered binary tree is not a binary search tree\n";
}
/*1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16*/
