#include<iostream>
using namespace std;
int main() {
    int a,b,maxm,c;
    while(1) {
        cin>>a>>b;
        int p = a+1;
        int q = b-1;
        int P=0, Q=0;
        maxm= -1;
        for(int i=a;i<b;i++) {
            for(int j=i+1;j<=b;j++) {
                c = i&j;
                if(c>maxm) {
                    maxm = c;
                    P = i;
                    Q = j;
                }
            }
        }
        cout<<"Max and is pair "<<P<<" "<<Q<<" : "<<maxm<<endl;
    }
}
