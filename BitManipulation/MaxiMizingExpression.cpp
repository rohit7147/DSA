#include<iostream>
using namespace std;
int getMSBIndex(long long n) {
    int MSB = 0;
    cout<<n<<" : ";
    for(int i=0;i<32;i++) {
        if(n & (1<<i)) {
            MSB = i;
            //cout<<"1";
        } else {
            //cout<<"0";
        }
    }
    for(int i=MSB;i>=0;i--) {
        if(n & (1<<i)) {
            cout<<"1";
        } else {
            cout<<"0";
        }
    }
    cout<<endl;
    return MSB;
}
int main() {
    int n,i;
    cin>>n;
    long long a[n];
    long long b[n];
    long long c[n];
    long long maxm[n] = {0};
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    for(i=0;i<n;i++) cin>>c[i];
    for(i=0;i<n;i++) {
        int MSBIndex = getMSBIndex(c[i]);
        long long D = (1LL<<MSBIndex);
        while(D) {
            long long cnd = (D & (c[i]));
            if(cnd == D) {
                long long axorbxord = ((b[i] ^ D) ^a[i]);
                if(maxm[i] < axorbxord) {
                    maxm[i] = axorbxord;
                }
            }
            D = (D>>1LL);
        }
        long long checkForMaxCi = ((b[i] ^ c[i]) ^ a[i]);
        if(maxm[i] < checkForMaxCi) {
            maxm[i] = checkForMaxCi;
        }
    }
    long long sum = 0;
    for(i=0;i<n;i++) {
            //cout<<maxm[i] <<" ";
        sum = sum +maxm[i];
    }
    //cout<<endl<<sum<<endl;
}
/*
3
669379973 164279053 914179473
134438107 405576610 128505765
383465663 686348907 591420499

2915341157
*/
