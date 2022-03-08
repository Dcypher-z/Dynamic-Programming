#include <bits/stdc++.h>
using namespace std;

int t[1002][1002];

int LCS(string x, string y, int n, int m)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
            else
            {
                if(x[i-1]==y[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
    }
    return t[n][m];
}

int main()
{
    memset(t, -1, sizeof(t));
    string a = "AGGTAB";
    string b = "GXTXAYB";
    cout<<(a.length()+b.length()-LCS(a, b, a.length(), b.length()));
    return 0;
}