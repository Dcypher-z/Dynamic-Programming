#include <bits/stdc++.h>
using namespace std;

int t[1002][1002];

int solve(int e, int f)
{
    if (t[e][f] != -1)
        return t[e][f];

    else if (f == 0 || f == 1)
        return f;

    else if (e == 1)
        return f;

    int mn = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int low, high;
        if (t[e - 1][k - 1] != -1)
            low = t[e - 1][k - 1];
        else
            low = solve(e - 1, k - 1);
        if (t[e][f - k] != -1)
            low = t[e][f - k];
        else
            low = solve(e, f - k);

        int temp = 1 + max(low, high);

        mn = min(mn, temp);
    }
    t[e][f] = mn;
    return mn;
}

int main()
{
    int e, f;
    memset(t, -1, sizeof(t));
    cout << solve(3, 5);
    return 0;
}