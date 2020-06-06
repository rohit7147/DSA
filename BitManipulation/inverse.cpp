#include <iostream>
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
int main()
{
    long long int a,b,c,m,ans1,ans2;
    cin>>a>>b>>c>>m;
    ans1=modularExponentiation(a,b,m);
    ans2=modInverse(c,m);
    cout<<ans2<<endl;
    cout<<((ans1%m)*(ans2%m))%m;
    return 0;
}
