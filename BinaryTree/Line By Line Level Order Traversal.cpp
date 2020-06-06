#include<iostream>
#include<stdlib.h>
#include<queue>
#define max 7
using namespace std;
struct node
{
    int info;
    struct node *lt,*rt;
};
node *newNode(int val)
{
    node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->lt=tmp->rt=NULL;
    tmp->info=val;
    return tmp;
}
struct node *Insert(struct node *root,int val)
{
    if(root == NULL)
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
}

void LineByLineTraversal(node *root)
{
    if(root==NULL)
		return;
	queue<node *> q;
	q.push(root);
	while(q.size()>0)
	{
		node *curr=q.front();
		cout<<curr->info<<" ";
		if(curr->lt)
			q.push(curr->lt);
		if(curr->rt)
			q.push(curr->rt);
		q.pop();
	}
}
int DepthGreaterThanD(node *root, int depth, int D)
{
    if(root==NULL) return 0;
    int tmp=0;
    if(D<depth)
    {
        if(root->lt==NULL && root->rt==NULL)
            return 1;
        tmp=1;
    }
    return tmp+DepthGreaterThanD(root->lt,depth+1,D)+DepthGreaterThanD(root->rt,depth+1,D);
}
int main()
{
    struct node *root=NULL;
    int i,val;
    for(i=0;i<max;i++)
    {
        cin>>val;
        root=Insert(root,val);
    }
    cout<<"Even count : "<<DepthGreaterThanD(root,1,4)<<endl;
    //LineByLineTraversal(root);
}
/*
1 2 3 4 5 6 7
15 25 10 7 12 17 30
*/













/*root=newNode(1);
    root->lt=newNode(2);
    root->rt=newNode(3);
    root->rt->lt=newNode(4);
    root->rt->rt=newNode(5);
    root->rt->lt->lt=newNode(6);
    root->rt->rt->lt=newNode(7);
    root->rt->rt->rt=newNode(8);*/
