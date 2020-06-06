#include<bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int KMPSearch(string s, string x)
{
    int M = s.length();
    int N = x.length();
    int lps[M];
    computeLPSArray(s, M, lps);

    int i = 0;
    int j  = 0;
    while (i < N)
    {
        if (s[j] == x[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found stern at index %d \n", i-j);
            return i-j;
        }
        else if (i < N && s[j] != x[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return -1;
}
int main()
{
    string pat,txt;
    cin>>txt>>pat;
    cout<<KMPSearch(pat, txt)<<endl;
    return 0;
}
