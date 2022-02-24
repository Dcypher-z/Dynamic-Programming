#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

int CountSubsetSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 1;

            else if (i == 0)
                t[i][j] = 0;

            else if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];

            else if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return t[n][sum];
}
int main()
{
    memset(t, -1, sizeof(t));
    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;

        int sum;
        cin >> sum;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << CountSubsetSum(arr, n, sum) << endl;
    }
    return 0;
}