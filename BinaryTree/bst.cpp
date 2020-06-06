#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    node *lt,*rt;
};
struct node *bst(struct node *root,int val)
{
    if(root==NULL)
    {
        struct node *tmp=new node();
        tmp->info=val;
        tmp->lt=NULL;
        tmp->rt=NULL;
        root=tmp;
    }
    else if(root->info > val)
        root->lt=bst(root->lt,val);
    else
        root->rt=bst(root->rt,val);

    return root;
};
node *getSuccessor(node *root,int val,int *flag)
{
    if(!root) return NULL;
    getSuccessor(root->lt,val,flag);
    if(*flag==1)
        return root;
    if(root->info==val)
    {
        cout<<"val found : "<<root->info<<endl;
        *flag=1;
    }
    getSuccessor(root->rt,val,flag);
}
node *inOrderSuccessor(node *root, int val, int flag)
{
    if(!root) return NULL;
    return getSuccessor(root,val,&flag);
}
void printInorder(node *root)
{
    if(!root) return;
    printInorder(root->lt);
    cout<<root->info<<" ";
    printInorder(root->rt);
}
int main()
{
    node *root=NULL;
    int n=7,i,val;
    for(i=0;i<n;i++)
    {
        cin>>val;
        root=bst(root,val);
    }
    cout<<"\nInorder..."<<endl;
    printInorder(root);
    cout<<endl;
    cin>>val;
    node *succsessor=inOrderSuccessor(root,val,0);
    if(succsessor) cout<<succsessor->info<<endl;
}
/*
887 778 916 794 336 387 493 650 422 363 28 691 60 764 927 541 427 173 737 212 369 568 430 783 531 863 124 68 136 930 803 23 59 70 168 394 457 12 43 230 374
422 920 785 538 199 325 316 371 414 527 92 981 957 874 863 171 997 282 306 926 85 328 337 506 847 730 314 858 125 896 583 546 815 368 435 365 44 751 88 809
277 179 789
926
*/
/*
77
369 740 13 227 587 95 540 796 571 435 379 468 602 98 903 318 493 653 757 302 281 287 442 866 690 445 620 441 730 32 118 98 772 482 676 710 928 568 857
498 354 587 966 307 684 220 625 529 872 733 830 504 20 271 369 709 716 341 150 797 724 619 246 847 452 922 556 380 489 765 229 842 351 194 501 35 765
*/
