#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        //temp = c1+ c2+ c3
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        if (temp < mn)
            mn = temp;
    }
    t[i][j]=mn;
    return mn;
}

int main()
{
    memset(t, -1, sizeof(t));
    int arr[] = {40, 20, 30, 10, 30};
    cout << solve(arr, 1, 4);
    return 0;
}