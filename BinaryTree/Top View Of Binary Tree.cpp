#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
#define max 6
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
    int horizontalDistance;
};
node *Insert(node *,int);
void assignHorizontalDistance(node *,int ,int *,int *);
void printTopView(node *,int [],int);
void Hash(int ,int [],int);
int isVisited(int ,int [],int );

int main()
{
    node *root=NULL;
    int i,val,hd=0,minm=0,maxm=0;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    assignHorizontalDistance(root,hd,&minm,&maxm);
    int hashTableSize=abs(minm) + maxm + 1;
    int hashTable[hashTableSize];
    printTopView(root,hashTable,maxm);
    cout<<endl;
    for(i=0;i<hashTableSize;i++)
        cout<<"hashTable["<<i<<"] : "<<hashTable[i]<<endl;
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
void assignHorizontalDistance(node *root,int hd,int *minm,int *maxm)
{
    if(!root)
        return;
    root->horizontalDistance=hd;
    cout<<"root->info : "<<root->info<<"\t"<<"root->hd : "<<root->horizontalDistance<<endl;
    if(hd < *minm )
        *minm=hd;
    else if(hd > *maxm)
        *maxm=hd;
    assignHorizontalDistance(root->lt,hd-1,minm,maxm);
    assignHorizontalDistance(root->rt,hd+1,minm,maxm);
}
void printTopView(node *root,int hashTable[],int maxm)
{
    if(!root)
        return;
    queue <node *> q;
    queue <int > hd;
    int hdi=0;
    q.push(root);
    hd.push(hdi);
    while(!q.empty())
    {
        node *curr=q.front();
        hdi=hd.front();
        q.pop();
        hd.pop();
        if(!isVisited(curr->horizontalDistance,hashTable,maxm))
        {
            cout<<curr->info<<" ";
            Hash(curr->horizontalDistance,hashTable,maxm);
        }
        if(curr->lt)
        {
            q.push(curr->lt);
            hd.push(hdi-1);
        }
        if(curr->rt)
        {
            q.push(curr->rt);
            hd.push(hdi+1);
        }
    }
}
int isVisited(int val,int hashTable[],int maxm)
{
    if(hashTable[val+maxm]==val)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Hash(int val,int hashTable [],int maxm)
{
    hashTable[val+maxm]=val;
}
//5 2 3 1 7 6 8
