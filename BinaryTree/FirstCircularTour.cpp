#include<iostream>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n)
{
    int i,prev=0,count=0,start=0,prevStart=0,tmp;
    for(i=0;i<n;i++)
    {
        if(p[i].petrol+prev>=p[i].distance)
        {
            prev=p[i].petrol+prev-p[i].distance;
            cout<<"p["<<i<<"].petrol : "<<p[i].petrol<<"\tp["<<i<<"].distance : "<<
            p[i].distance<<"\tdifference : "<<prev<<endl;
            count++;
            cout<<"count : "<<count<<"   i : "<<i<<"\t"<<endl;
            if(count==n)
                return start;
            if(i==n-1 && count<n) i=-1;
        }
        else
        {
            cout<<"p["<<i<<"].petrol : "<<p[i].petrol<<"\tp["<<i<<"].distance : "<<p[i].distance
            <<"\tNegative difference : "<<p[i].petrol+prev-p[i].distance<<endl;
            count=0;
            prev=0;
            if(start==n-1) return -1;
            prevStart=start;
            start=prevStart+1;
            i=start-1;
            cout<<"start : "<<start<<endl;
        }
    }
    return -1;
}
int main()
{
    int t,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        petrolPump a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i].petrol;
            cin>>a[i].distance;
        }
        cout<<tour(a,n);
        cout<<endl;
    }
}
/*
2
32
98 18 82 72 10 76 68 28 98 57 87 54 7 66 20 84 29 25 33 72 4 30 71 20 9 69 41 16 97 50 19 24 47 46 22 52 80 56 65 89 42 29 94 51 35 1 25 65 88 15 44 57
28 92 60 66 33 37 38 52 76 29 75 8
5
1 2 3 4 5 6 7 8 11 10
1
5
1 2 3 4 6 6 8 8 11 10
*/
