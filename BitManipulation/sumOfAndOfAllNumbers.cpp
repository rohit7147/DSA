#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
long long int fast_pow(long long int x,long long int n)
{
  long long int res = 1;
  while(n>0)
  {
    if (n%2 == 1)
      res = (res*x)%M;
    x = (x*x)%M;
    n = n/2;
  }
  return res;
}
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,x,p=0,i,j;
        scanf("%lld",&n);
        long long int a[n],c, countArray[32];
        for(i=0;i<32;i++) countArray[i]=0;
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        long long int ans=0;
        for(i=0;i<32;i++)
        {
            c=0;
            int x = (1<<i);
            printf("x : %d\t", x);
            for(j=0;j<n;j++)
            {
                 if (a[j]&(1 << i))
                c++;
            }
            cout<<"i : "<<i<<", count : "<<c<<endl;
              ans = (ans + ((fast_pow(2,c)-1)*fast_pow(2,i))%M)%M;
        }
        printf("%lld\n",ans);
    }
}
/*
1
4
1 2 3 4
*/

