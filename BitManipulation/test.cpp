#include<iostream>
using namespace std;
char arr[20], res[20];
void decToBinary(int n)
{
	for (int i = 19; i >= 0; i--) {
		int k = n >> i;
		if (k & 1)
			arr[i]='1';
		else
			arr[i]='0';
	}
}
int countSetBits(long n)
{
    int count=0;
            while( n )
            {
            n = n&(n-1);
               count++;
            }
            return count;
}
long binaryToDecimal()
{
    long dec_value = 0;
    int base = 1;

    int len = 20;
    for (int i = 0; i < 20; i++) {
        if (res[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
int lastIndexOfOneInArr() {
    for(int i=19;i>=0;i--) {
        if(arr[i] == '1')
            return i;
    }
}
int main() {
    long a, b, t, x;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int setBits = countSetBits(b);
        cout<<"Set Bits : "<<setBits<<endl;
        for(int i=0;i<20;i++) {
            arr[i] = '0';
            res[i] = '0';
        }
        decToBinary(a);
        int index = lastIndexOfOneInArr();
        for(int i=index;i>=0;i--) {
            if(setBits > 0) {
                if(arr[i] == '1') {
                    res[i] = '1';
                    cout<<"res["<<i<<"] : "<<res[i]<<endl;
                    setBits--;
                }
            }
        }
        cout<<"Remaining Set Bits : "<<setBits<<endl;
        for(int i=0;i<20;i++) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        for(int i=index;i>=0;i--) {
            if(setBits > 0) {
                if(arr[i] == '0') {
                    cout<<"res["<<i<<"] : "<<res[i]<<endl;
                    res[i] = '1';
                    setBits--;
                }
            }
        }
        for(int i=0;i<20;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<20;i++) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        cout<<binaryToDecimal()<<endl;
    }
}
/*
5
13846579 3
Set Bits : 2
1 1 0 0 1 1 0 0 0 0 0 1 0 0 1 0 1 1 0 0
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
*/
