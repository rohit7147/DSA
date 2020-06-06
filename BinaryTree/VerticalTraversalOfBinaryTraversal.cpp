#include<bits/stdc++.h>
#define MAX 7
using namespace std;
struct node
{
    node *left,*right;
    int data;
};
struct node *Insert(struct node *root,int val)
{
    if(root==NULL)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=val;
        tmp->left=tmp->right=NULL;
        root=tmp;
    }
    else if(val<root->data)root->left=Insert(root->left,val);
    else root->right=Insert(root->right,val);
    return root;
};
void buildMap(struct node *root,map<int,vector<int> > &m,int hd)
{
    if(!root) return;
    m[hd].push_back(root->data);
    buildMap(root->left,m,hd-1);
    buildMap(root->right,m,hd+1);
}
void verticalTraversal(struct node *root)
{
    map<int,vector<int> > m;
    buildMap(root,m,0);
    map<int,vector<int> >::iterator it=m.begin();
    vector<int>::iterator it1;
    while(it!=m.end())
    {
        it1=m[(*it).first].begin();
        while(it1!=m[(*it).first].end())
        {
            cout<<(*it1)<<" ";
            it1++;
        }
        it++;
    }
    cout<<endl;
}
int main()
{
    int val,i;
    struct node *root=NULL;
    for(i=0;i<MAX;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    verticalTraversal(root);
}
