#include<iostream>
using namespace std;
void convertToRoman(int n)
{
    int q,r,i;
    while(n>0)
    {
        if(n>=1000)
        {
            q=n/1000;
            n=n%1000;
            for(i=0;i<q;i++) cout<<"M";
        }
        else if(n>=500 && n<1000)
        {
            if(n>899)
            {
                cout<<"CM";
                n=n%100;
            }
            else
            {
                cout<<"D";
                n=n%500;
            }
        }
        else if(n>=100 && n<500)
        {
            if(n>399)
                cout<<"CD";
            else
            {
                q=n/100;
                for(i=0;i<q;i++) cout<<"C";
            }
            n=n%100;
        }
        else if(n>=50 && n<100)
        {
            if(n>89)
                cout<<"XC";
            else
            {
                cout<<"L";
                q=(n-50)/10;
                for(i=0;i<q;i++) cout<<"X";
            }
            n=n%10;
        }
        else if(n>=10 && n<50)
        {
            if(n>39)
                cout<<"XL";
            else
            {
                q=n/10;
                for(i=0;i<q;i++) cout<<"X";
            }
            n=n%10;
        }
        else if(n>=5 && n<10)
        {
            if(n==9)
                cout<<"IX";
            else
            {
                cout<<"V";
                for(i=0;i<n-5;i++) cout<<"I";
            }
            n=n/10;
        }
        else
        {
            if(n==4) cout<<"IV";
            else
                for(i=0;i<n;i++) cout<<"I";
            n=n/10;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        convertToRoman(n);
        cout<<endl;
    }
}
