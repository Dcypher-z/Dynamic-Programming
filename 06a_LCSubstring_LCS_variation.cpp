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
                    t[i][j] = 0;
                }
            }
        }
    }
    return t[n][m];
}

int main()
{
    memset(t, -1, sizeof(t));
    string a = "abdcf";
    string b = "abcdcf";
    LCS(a, b, 5, 6);
    int m=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            m = max(t[i][j], m);
        }
    }
    cout<<m<<endl;
    return 0;
}