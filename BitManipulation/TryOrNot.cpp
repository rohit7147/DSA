#include<iostream>
using namespace std;
bool subsetMatrix[1048577][151]={false};
bool arr[20][150];
void populateSubSetMatrix() {
    for(int i = 0;i < (1 << 20); ++i)
    {
        for(int j = 0;j < 20;++j) {
            if(i & (1 << j))
                subsetMatrix[i][j] = true;
            else
                subsetMatrix[i][j] = false;
        }
    }
}
void doOR(bool res[], int index, int m) {
    for(int i=0;i<m;i++) {
        res[i] = (res[i] | arr[index][i]);
    }
}
bool isAllSetBit(bool res[], int m) {
    int i = 0;
    while(i<m){
        if(!res[i])
            return false;
        i++;
    }
    return true;
}

int main() {
    int t, n, m, i, j;
    cin>>t;
    populateSubSetMatrix();
    while(t--) {
        cin>>n>>m;
        int index, count = 0;
        for(i = 0;i < n; i++) {
            for(j = 0;j < m; j++) {
                cin>>arr[i][j];
            }
        }
        for(i = 0;i<(1<<n); i++) {
            bool res[m];
            for(j = 0;j < m; j++) {
                res[j] = false;
            }
            for(j = 0;j < m; j++) {
                if(subsetMatrix[i][j] != false) {
                    index = j;
                    for(int k = 0;k<m;k++) {
                        res[k] = (res[k] | subsetMatrix[index][k]);
                    }
                }
            }
            if(isAllSetBit(res, m)) {
                count++;
            }
        }
        cout<<"i : "<<i<<endl;
        cout<<count<<endl;
    }
}

/*
1
3 3
1 0 0
0 1 0
0 0 1
*/
/*
1
15 10
1 0 0 1 0 0 0 0 1 1
1 1 1 0 1 1 0 0 0 1
0 1 0 1 1 0 0 1 1 1
1 0 1 1 1 0 1 1 0 1
0 1 0 1 1 0 0 0 0 0
1 0 1 1 1 1 1 0 1 0
1 0 0 0 0 1 0 0 1 0
1 1 0 1 1 1 1 1 1 1
0 1 1 1 0 1 0 0 1 0
0 0 0 1 0 0 0 1 0 1
1 1 1 1 1 0 1 0 1 0
0 1 1 1 1 0 0 1 0 1
1 0 1 0 1 0 0 0 1 1
1 0 0 0 0 1 0 1 0 0
1 0 1 1 1 0 1 0 0 1
*/
