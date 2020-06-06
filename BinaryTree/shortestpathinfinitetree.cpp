#include<iostream>
#include <math.h>
#include<cmath>
using namespace std;

long int findSide(long int x,long int n)
{
    if(x>=pow(2,n)&&x<(pow(2,n)+pow(2,n-1)))
        return 1;
    else if(x>=(pow(2,n)+pow(2,n-1))&&x<pow(2,n+1))
        return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long int x,y,levelx,levely,isLx,isLy;
        cin>>x>>y;
        levelx=(long int)(log2f(x));
        levely=(long int)(log2f(y));
        if(levelx==0){
            cout<<levely-levelx;
        }else{
            isLx=findSide(x,levelx);
            isLy=findSide(y,levely);
            if(isLx==isLy)
            {
                cout<<abs(levely-levelx)<<endl;
            }
            else{
                cout<<levely+levelx<<endl;
            }
        }
    }
}
