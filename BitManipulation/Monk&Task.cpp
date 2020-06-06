#include<bits/stdc++.h>
using namespace std;
int getCountOfSetBits(int n) {
    int count = 0;
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}
bool cmp(pair<int, int> l, pair<int, int> r) {
    if(l.first == r.first) {
        return (l.second > r.second);
    } else {
        return (l.first < r.first);
    }
}
int main() {
    int t, n, i;
    cin>>t;
    while(t--) {
        cin>>n;
        long long arr[n];
        vector<pair<int, int> > v(n);
        for(i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(i=0;i<n;i++) {
            v[i].first = getCountOfSetBits(arr[i]);
            v[i].second = i;
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0;i<v.size();i++) {
            cout<<arr[v[i].second]<<' ';
        }
        cout<<endl;
    }
}
