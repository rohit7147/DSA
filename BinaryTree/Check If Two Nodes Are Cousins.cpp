#include<iostream>
#include<stdlib.h>
#define max 7
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
node *Insert(node *,int);
int checkCousin(node *,int,int);
void findLevel(node *,int ,int *,int);
void getParentNode(node *,int ,node **);
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
    if(checkCousin(root,key1,key2))
        cout<<"\nTrue";
    else
        cout<<"\nFalse";
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
int checkCousin(node *root,int key1,int key2)
{
    if(root==NULL)
        return 0;
    int level=1;
    int Levelkey1,Levelkey2;
    findLevel(root,key1,&Levelkey1,level);
    findLevel(root,key2,&Levelkey2,level);
    cout<<"\nLevelkey1 : "<<Levelkey1<<" LevelKey2 : "<<Levelkey2;
    if(Levelkey1==Levelkey2)
    {
        node *parentKey1,*parentKey2;
        getParentNode(root,key1,&parentKey1);
        getParentNode(root,key2,&parentKey2);
        if(parentKey1!=parentKey2)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
void findLevel(node *root,int key,int *Levelkey,int level)
{
    if(root==NULL)
        return;
    if(root->info==key)
        *Levelkey=level;
    findLevel(root->lt,key,Levelkey,(level)+1);
    findLevel(root->rt,key,Levelkey,(level)+1);
}
void getParentNode(node *root,int key,node **parentKey)
{
    if(root==NULL)
        return;
    if((root->lt && root->lt->info==key) || (root->rt && root->rt->info==key))
            *parentKey=root;
    getParentNode(root->lt,key,parentKey);
    getParentNode(root->rt,key,parentKey);
}
