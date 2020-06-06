#include<bits/stdc++.h>
using namespace std;
int nextPowerOfTwo(int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
void createSegmentTree(int arr[],pair<int, int> segmentTree[], int low, int high, int pos) {
    if(low == high) {
        if(arr[low] == 0) {
            segmentTree[pos].first = 1;
        } else {
            segmentTree[pos].second = 1;
        }
        return;
    }
    int mid = (low+high)/2;
    createSegmentTree(arr, segmentTree, low, mid, 2*pos+1);
    createSegmentTree(arr, segmentTree, mid+1, high, 2*pos+2);
    segmentTree[pos].first = segmentTree[2*pos+1].first + segmentTree[2*pos+2].first;
    segmentTree[pos].second = segmentTree[2*pos+1].second + segmentTree[2*pos+2].second;
}
pair<int,int> rangeQuery(pair<int,int> segmentTree[],int qlow,int qhigh,int low,int high,int pos)
{
    pair<int, int> temp;
    temp.first = 0;
    temp.second = 0;
    if(qlow<=low && qhigh>=high)
        return segmentTree[pos];
    if(low>qhigh || high<qlow) return temp;
    int mid=(low+high)/2;
    pair<int, int> left = rangeQuery(segmentTree,qlow,qhigh,low,mid,2*pos+1);
    pair<int, int> right = rangeQuery(segmentTree,qlow,qhigh,mid+1,high,2*pos+2);
    pair<int, int> res;
    res.first = left.first + right.first;
    res.second = left.second + right.second;
    return res;
}
int main() {
    int n,i,q, l, r;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    int sizeOfSegmentTree = 2*nextPowerOfTwo(n)-1;
    pair<int, int> segmentTree[sizeOfSegmentTree];
    for(i=0;i<sizeOfSegmentTree;i++) {
        segmentTree[i].first = 0;
        segmentTree[i].second = 0;
    }
    createSegmentTree(arr, segmentTree, 0, n-1, 0);
    cin>>q;
    while(q--) {
        cin>>l>>r;
        pair<int,int> countOfSetAndUnsetBit = rangeQuery(segmentTree,l-1,r-1,0,n-1,0);
        if(countOfSetAndUnsetBit.second % 2 == 0) cout<<"0 ";
        else cout<<"1 ";
        cout<<countOfSetAndUnsetBit.first<<endl;
    }
}
