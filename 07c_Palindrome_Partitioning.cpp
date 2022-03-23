#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    string p = s.substr(i, j - i + 1);
    string q = s.substr(i, j - i + 1);
    reverse(p.begin(), p.end()); 

    if (p == q)
        return true;
    return false;
}

int solve(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (isPalindrome(s, i, j))
    {
        return 0;
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(s, i, k) + solve(s, k+1, j) + 1;
        if (temp < mn)
        {
            mn = temp;
        }
    }
    return mn;
}

int main()
{
    cout<<solve("Hello", 0, 4);
    return 0;
}