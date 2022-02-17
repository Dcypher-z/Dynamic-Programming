#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

int knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (t[n][w] != -1)
        return t[n][w];

    if (wt[n - 1] <= w)
        return t[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));

    else if (wt[n - 1] > w)
        return t[n][w] = knapsack(wt, val, w, n - 1);

    return 0;
}

int main()
{
    memset(t, -1, sizeof(t));
    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cout << "size of array: ";
        cin >> n;
        int wt[n];
        int val[n];
        int W;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter weight and value of Item" + (i + 1);
            cin >> wt[i] >> val[i];
        }
        cout << "Enter capacity of knapsack: ";
        cin >> W;
        cout<<knapsack(wt, val, W, n);
    }
    return 0;
}