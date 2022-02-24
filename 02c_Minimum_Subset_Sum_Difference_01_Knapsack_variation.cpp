#include <bits/stdc++.h>
using namespace std;
int t[102][1002];

int SubsetSumDifference(int range, int n);

void SubsetSum(int arr[], int n, int range)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (j == 0)
                t[i][j] = 1;

            else if (i == 0)
                t[i][j] = 0;

            else if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];

            else if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    cout << SubsetSumDifference(range, n) << endl;
}

int SubsetSumDifference(int range, int n)
{
    vector<int> v;
    for (int i = 0; i < range + 1; i++)
    {
        if (t[n][i] == 1)
            v.push_back(i);
    }
    int mn = range - 2 * v[0];
    for (int i = 1; i < v.size(); i++)
    {
        mn = min(mn, abs(range - 2 * (v[i])));
    }
    v.clear();
    return mn;
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
        int arr[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        SubsetSum(arr, n, sum);
    }
    return 0;
}