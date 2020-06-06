#include<iostream>
#include<stdlib.h>
#include<queue>
#define max 7
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
int findDistance(node *,int,int);
node *Insert(node *,int);
int flag1=0,flag2=0;
int main()
{
    node *root=NULL;
    int i,val,key1,key2;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cin>>key1>>key2;
    cout<<"\nDistance Between Two Key is : "<<findDistance(root,key1,key2);
}
node *Insert(node *root,int val)
{
    if(root==NULL)
    {
        node *tmp=(struct node *)malloc(sizeof(struct node));
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
int findDistance(node *root,int key1,int key2)
{
    if(root==NULL)
        return 0;
    int ld=0,rd=0;
    static int count=0;
    count++;
    findDistance(root->lt,key1,key2);
    count--;
    findDistance(root->rt,key1,key2);
    if(root->info==key1)
        flag1=1;
    else if(root->info==key2)
        flag2=1;
    if(flag1 && flag2)
        return count;
}
