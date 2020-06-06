#include<iostream>
using namespace std;
int MSBIndex(int x) {
    int lastSetBit = 0;
    for(int i=0;i<64;i++) {
        if(x & (1LL<<i)) {
            lastSetBit = i;
        }
    }
    return lastSetBit;
}

void decimalToBinary(long long x, bool arr[]) {
    for(int i=0;i<64;i++) {
        if(x & (1LL<<i)) {
            arr[i] = true;
        }
    }
}

void AXNORB(bool arr[], int numberOfBitsInC) {
    for(int i=0;i<=numberOfBitsInC;i++) {
        cout<<arr[i]<<' ';
        if(arr[i] == false) {
            arr[i] = true;
        } else {
            arr[i] = false;
        }
        cout<<arr[i]<<endl;
    }
    cout<<"\nOnes Compliment : ";
    for(int i=0;i<=numberOfBitsInC;i++) {
        cout<<arr[i]<< ' ';
    }
    cout<<endl;
}

long long binaryToDecimal(bool arr[], int size) {
    long long res = 0;
    for(int i=0;i<=size;i++) {
        if(arr[i]) {
            res = res + (1LL<<i);
        }
    }
    return res;
}
int main() {
    int t, i;
    cin>>t;
    while(t--) {
        long long a, b, n;
        cin>>a>>b>>n;
        long long c = a^b;
        cout<<"a ^ b : "<<c<<endl;
        int MSBA = MSBIndex(a);
        int MSBB = MSBIndex(b);
        int numberOfBitsInC = max(MSBA, MSBB);
        bool arr[64];
        for(i = 0;i<64;i++) arr[i] = false;
        decimalToBinary(c, arr);
        cout<<"Binary of "<<c<<" : ";
        for(i = 0;i<=numberOfBitsInC;i++) {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        AXNORB(arr, numberOfBitsInC);
        long long d = binaryToDecimal(arr, numberOfBitsInC);
        if(n%3 == 0) {
            cout<<max(c,d);
        } else if(n%3 == 1) {
            cout<<a;
        } else if(n%3 == 2) {
            cout<<b;
        }
        cout<<"\n";
    }
}
