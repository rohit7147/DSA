#include<iostream>
using namespace std;
char subset[16][4];
char alpha[21] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
bool subsetMatrix[1048576][150]={false};
void possibleSubsets(char A[], int N)
{
    int temp=0;
    for(int i = 0;i < (1 << 3); ++i)
    {
        for(int j = 0;j < 3;++j) {
            if(i & (1 << j))
                subsetMatrix[i][j] = true;
            else
               subsetMatrix[i][j] = false;
        }
        temp = i;
    }
    cout<<"temp : "<<temp<<endl;
    for(int i = 0;i < (1 << N); ++i)
    {
        for(int j = 0;j < N;++j) {
            cout<<subsetMatrix[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int j = 0;j < N;++j) {
        cout<<"subsetMatrix["<<1048575<<"]["<<j<<"] : "<<subsetMatrix[1047995][j]<<endl;
    }
    cout<<endl;
}
int main() {
    char arr[] = {'a', 'b', 'c', 'd'};
    possibleSubsets(arr, 4);
    bool t = true, f = false;
    cout<<"res : "<<(t^f)<<endl;

}
