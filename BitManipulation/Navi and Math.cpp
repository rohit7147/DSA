#include<iostream>
#define mod 1000000007
using namespace std;
long long int d, z, y;
long long int modularExponentiation(long long int x,long long int n,long long int M)
{
    long long int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
void extendedEuclid(long long int c,long long int m)
{
    if(m == 0)
    {
        d = c;
        z = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(m, c%m);
        long long int temp = z;
        z = y;
        y = temp - (c/m)*y;
    }
}
long long int modInverse(int c, int M)
{
    extendedEuclid(c,M);
    return (z%M+M)%M;
}
int main() {
    long long t, i, n, j;
    cin>>t;
    int tmp = 1;
    while(tmp<=t) {
        cin>>n;
        long long arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        long long sum, prod, maxm, curr, count;
        maxm = 0;
        //long x = (1<<n);
        for(i=0;i<(1<<n);i++) {
            sum = 0L;
            prod = 1L;
            curr = 0L;
            count = 0;
            for(j = 0;j<n;j++) {
                if(i & (1<<j)) {
                    count++;
                    sum = sum + arr[j];
                    sum = sum % mod;
                    prod = prod * arr[j];
                    prod = prod % mod;
                }
            }
            if(sum!=0 && count>=2) {
               long long ans1=modularExponentiation(prod,1,mod);
               long long ans2=modInverse(sum,mod);
               curr = ((ans1%mod)*(ans2%mod))%mod;
            }
            if(curr > maxm && count>=2)
                maxm = curr;

        }
        cout<<"Case #"<<tmp<<": "<<maxm<<endl;
        tmp++;
    }
}
/*
sum = sum + arr[i];
                    sum = sum % mod;
                    prod = prod * arr[j];
                    prod = prod % mod;
                sum = 0;
            prod = 1;
            curr = 0;
            cout<<endl;
            curr = ((prod/sum)%mod);
            if(curr > maxm)
                maxm = curr;
*/
