#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i,q, l, r;
    cin>>n;
    bool arr[n+1];
    for(i=1;i<=n;i++) cin>>arr[i];
    pair<int,int> p[n+1];
    p[0].first = p[0].second = 0;
    for(i=1;i<=n;i++) {
        if(arr[i] == false) {
            p[i].first = p[i-1].first + 1;
            p[i].second = p[i-1].second;
        } else {
            p[i].second = p[i-1].second + 1;
            p[i].first = p[i-1].first;
        }
    }
    cout<<"Index 0s 1s"<<endl;
    for(i=0;i<=n;i++) {
        cout<<"  "<<i<<" :  "<<p[i].first<<" "<<p[i].second<<endl;
    }
    cin>>q;
    while(q--) {
        cin>>l>>r;
        int setBits = p[r].second - p[l-1].second;
        int unSetBits = p[r].first - p[l-1].first;
        cout<<"SetBits : "<<setBits<<endl;
        cout<<"unSetBits : "<<unSetBits<<endl;
        if(setBits%2==0) cout<<"0 ";
        else cout<<"1 ";
        cout<<unSetBits<<endl;
    }
}
