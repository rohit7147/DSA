#include<iostream>
#include<stdlib.h>
#define max 6
using namespace std;
struct node
{
    char info;
    struct node *lt,*rt;
};

void printInorder(struct node *);
struct node *constructTree(char [],char [],int,int);
int searchIndex(char [],int,int,char);
void printInorder(struct node *);
struct node *newNode(char);
int main()
{
      char in[max],pre[max];
      int i=0;
      while(i<max)
      {
          cin>>in[i];
          cout<<in[i]<<" ";
          i++;
      }
      cout<<"\n";
      i=0;
      while(i<max)
      {
          cin>>pre[i];
          cout<<in[i]<<" ";
          i++;
      }
      struct node *root = constructTree(in, pre, 0, i - 1);
      cout<<"\n Inorder traversal of the constructed tree is \n";
      printInorder(root);
}
struct node *constructTree(char in[],char pre[],int start,int end)
{
    static int preIndex=0;
    if(start>end)
    {
        return 0;
    }
    struct node *tmp=newNode(pre[preIndex++]);
    if(start==end)
        return tmp;
    int inIndex=searchIndex(in,start,end,tmp->info);
    tmp->lt=constructTree(in,pre,start,inIndex-1);
    tmp->rt=constructTree(in,pre,inIndex+1,end);
    return tmp;
};
struct node *newNode(char val)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=val;
    tmp->lt=tmp->rt=NULL;
    return tmp;
};
int searchIndex(char *in,int start,int end,char val)
{
    int i;
    for(i=start;i<=end;i++)
        if(in[i]==val)
        return i;
}
void printInorder(struct node *root)
{
    if(root==NULL){
        return;}
    printInorder(root->lt);
    cout<<root->info<<" ";
    printInorder(root->rt);
}
