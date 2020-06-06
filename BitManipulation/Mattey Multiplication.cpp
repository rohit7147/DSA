#include<iostream>
using namespace std;
void solve(long long n, long long m) {
    bool arr[64] = {false};
    int msbIndex=0;
    for(int i=0;i<64;i++) {
        if(m&(1LL<<i)) {
            //cout<<m<<" : "<<(1LL<<i)<<endl;
            arr[i] = true;
            msbIndex = i;
            //cout<<"MSBIndex : "<<msbIndex<<endl;
        }
    }
    //cout<<"Binary of "<<m<<" : ";
    for(int i=0;i<=msbIndex;i++) {
        //cout<<arr[i]<<' ';
    }
    //cout<<endl;
    for(int i=msbIndex;i>=0;i--) {
        if(arr[i] == true) {
            if(i != msbIndex) {
               cout<<" + ";
            }
            cout<<"("<<n<<"<<"<<i<<")";
        }
    }
}
int main() {
    int t, i;
    long long n, m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        solve(n,m);
        cout<<endl;
    }
}
/*
2
2 1
2 3
*/
