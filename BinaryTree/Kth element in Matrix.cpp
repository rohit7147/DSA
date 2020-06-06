#include<bits/stdc++.h>
#define MAX 20
using namespace std;
/*You are required to complete this function*/
int a[MAX][MAX];
void buildMinHeap(int a[],int pos,int val)
{
    a[pos]=val;
    while(pos>=0 && a[pos]<a[(pos-1)/2])
    {
        swap(a[pos],a[(pos-1)/2]);
        pos=(pos-1)/2;
    }
}
void minHeapify(int a[],int pos,int size)
{
    int leftChild=(2*pos+1);
    int rightChild=(2*pos+2);
    int smallest=pos;
    if(leftChild<size && a[pos]>a[leftChild])
        smallest=leftChild;
    if(rightChild<size && a[rightChild]<a[smallest])
        smallest=rightChild;
    if(smallest!=pos)
    {
        swap(a[pos],a[smallest]);
        minHeapify(a,smallest,size);
    }
}
void extractMin(int a[],int n)
{
    swap(a[0],a[n-1]);
    minHeapify(a,0,n-1);
}
int kthSmallest(int n, int k)
{
    int i,j;
    int mat[n*n],l=0;
    int m=n*n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            buildMinHeap(mat,k,a[i][j]);
            l++;
        }
    while((k--)>1)
        extractMin(mat,m--);
    cout<<mat[0];
}

int main()
{
    int t,i,j,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>a[i][j];
        int k;
        cin>>k;
        kthSmallest(n,k);
        cout<<endl;
    }
}
