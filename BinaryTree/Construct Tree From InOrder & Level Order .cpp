#include<iostream>
#include<stdlib.h>
#define max 7
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
struct node *newNode(int val)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=val;
    tmp->lt=tmp->rt=NULL;
    return tmp;
};
int findIndex(int inOrder[],int val,int size)
{
    int i;
    for(i=0;i<size;i++)
        if(inOrder[i]==val)
            return i;


}
struct node *constructTree(int level[],int inOrder[],int start,int end)
{
    static int levelIndex=0;
    if(start>end)
        return NULL;
    node *tmp=newNode(level[levelIndex++]);
    cout<<"tmp->info : "<<tmp->info<<endl;
    if(start==end)
        return tmp;
    int searchIndex=findIndex(inOrder,tmp->info,max);
    cout<<"searchIndex : "<<searchIndex<<endl;
    tmp->lt=constructTree(level,inOrder,start,searchIndex-1);
    tmp->rt=constructTree(level,inOrder,searchIndex-1,end);
    return tmp;
};
void printInorder(struct node *root)
{
    if(!root)
        return;
    printInorder(root->lt);
    cout<<root->info<<" ";
    printInorder(root->rt);
}
int main()
{
    int level[max],inorder[max];
    int i;
    for(i=0;i<max;i++)
        cin>>inorder[i];
    for(i=0;i<max;i++)
        cin>>level[i];
    struct node *root=NULL;
    root=constructTree(level,inorder,0,max-1);
    printInorder(root);
    cout<<endl;
}
/*
4 8 10 12 14 20 22
20 8 22 4 12 10 14
*/
