#include<bits/stdc++.h>
#define max 9
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
struct node *add(struct node *root,int val)
{
    if(!root)
    {
        struct node *tmp=new node();
        tmp->info=val;
        tmp->lt=tmp->rt=NULL;
        root=tmp;
    }
    else if(root->info > val)
        root->lt=add(root->lt,val);
    else
        root->rt=add(root->rt,val);
    return root;
};
void printDiagonally(struct node *root)
{
    if(!root)
        return;
    queue<node *> q;
    node *curr;
    q.push(root);
    int count=0,prev;
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        while(curr)
        {
            cout<<curr->info<<" ";
            if(curr->lt)
            {
                q.push(curr->lt);
                count++;
            }
            if(!curr->rt)
                cout<<endl;
            curr=curr->rt;
        }
    }
}
int main()
{
    node *root=NULL;
    int val,i;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=add(root,val);
    }
    printDiagonally(root);
}
/*
8 3 10 1 6 14 4 7 13
*/
