#include<iostream>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long unsigned dp[2016]={0};
void populateAllPossibleCombinationOfTwoBits() {
    int count = 0;
    for(int i = 63;i>=0;i++) {
        for(int j = i-1;j>63;j++) {
            long long unsigned x = (1UL<<i);
            long long unsigned y = (1UL<<j);
            dp[count] = (x+y);
            count++;
        }
    }
}
int main() {
    int t;
    long long unsigned n, sum;
    populateAllPossibleCombinationOfTwoBits();
    cin>>t;
    while(t--) {
        cin>>n;
        int i = 0;
        sum = 0;
        for(i=2015;i>=0;i--) {
            if(dp[i]<=n) {
                sum = sum + dp[i];
                sum = sum%mod;
            } else break;
        }
        cout<<(sum)<<"\n";
    }
}
