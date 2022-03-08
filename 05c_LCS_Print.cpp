#include <bits/stdc++.h>
using namespace std;

int t[1002][1002];

int LCS(string x, string y, int n, int m)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else
            {
                if (x[i-1] == y[j-1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
    }
    return t[n][m];
}

void Print_LCS(string x, string y, int n, int m)
{
    int i = n;
    int j = m;
    string s="";
    while (i > 0 && j > 0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(s.begin(), s.end());
    cout<<s;
}

int main()
{
    memset(t, -1, sizeof(t));
    string a = "acbcf";
    string b = "abcdaf";
    cout<<LCS(a, b, 5, 6)<<endl;
    Print_LCS(a, b, 5, 6);
    return 0;
}