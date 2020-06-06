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
void printAncestors(struct node *,int);
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>val;
    printAncestors(root,val);
}
struct node *Insert(struct node *root,int val)
{
    if(root==NULL)
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
};
void printAncestors(struct node *root,int val)
{
    stack<node *> s;
    struct node *tmp;
    int temp[max],i=0,len,flag=0;
    while(1)
    {
        if(root)
        {
            if(root->info == val && i!=0)
            {
                for(len=0;len<=i;len++)
                    cout<<temp[len]<<" ";
                break;
            }
            s.push(root);
            temp[i]=root->info;
            i++;
            root=root->lt;
        }
        else
        {
            root=s.top();
            if(root->rt == NULL || flag == 1)
            {
                if(!s.empty())
                {
                    root=s.top();
                    root=root->rt;
                    s.pop();
                    i--;
                    flag=0;
                }
                else
                    break;
            }
            else
            {
                root=root->rt;
                flag=1;
            }
        }
    }

}
