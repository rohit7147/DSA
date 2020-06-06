#include<iostream>
using namespace std;

void printBinary(int n) {

    while(n) {
        if(n&1) {
            cout<<"1 ";
        } else {
            cout<<"0 ";
        }
        n = (n>>1);
    }
    cout<<endl;
}
void printArray(int arr[]) {
    for(int i = 0;i<3;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void fun(int arr[]) {
    arr[1] = 5;
}
int main() {
    int n;
    cout<<"OR : "<<(9|10)<<endl;
    int arr[3] = {1,2,3};
    //fun(arr);
    //printArr(arr);
    /*while(1) {
        cin>>n;
        cout<<"Right Shift : "<<(n>>1)<<endl;
        cout<<"Left Shift : "<<(1<<n)<<endl;
        printBinary(n);
    }*/
}
