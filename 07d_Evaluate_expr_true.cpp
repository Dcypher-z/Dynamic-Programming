#include <bits/stdc++.h>
using namespace std;

int solve(string s, int i, int j, int p)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (p == true)
        {
            if (s[i] == 'T')
            {
                return 1; // number of ways we can return reqd p if there is only one char in string
            }
            else
            {
                return 0;
            }
        }
        else //means if p==false is asked
        {
            if (s[i] == 'F')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);

        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&')//AND
        {
            if (p == true)
                ans += lt * rt;
            else
                ans += lf * rf + lt * rf + lf * rt;
        }
        if (s[k] == '|')//OR
        {
            if (p == true)
                ans += lt * rt + lt * rf + lf * rt;
            else
                ans += lf * rf;
        }
        if (s[k] == '^')//XOR
        {
            if (p == true)
                ans += lt * rf + lf * rt;
            else
                ans += lf * rf + lt * rt;
        }
    }
    return ans;
}

int main()
{
    cout<<solve("T|F&T", 0, 4, true);
    return 0;
}