#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t[102][1002];
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
            cout << "Enter weight and value of Item" << (i + 1)<<" :";
            cin >> wt[i] >> val[i];
        }
        cout << "Enter capacity of knapsack: ";
        cin >> W;
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;

                if (wt[i - 1] <= j)
                    t[i][j] = max(val[i - 1] + t[i - 1][j - wt[j - 1]], t[i - 1][j]);

                else if (wt[i - 1] > j)
                    t[i][j] = t[i - 1][j];
            }
        cout << t[n][W]<<endl;
    }
    return 0;
}