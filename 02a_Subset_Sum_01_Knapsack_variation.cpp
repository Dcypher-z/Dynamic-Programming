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
        cin >> n;
        int sum;
        cin >> sum;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (t[n][sum] != -1)
        {
            cout << (bool) t[n][sum] << endl;
        }
        else
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
                        t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];

                    else if (arr[i - 1] > j)
                        t[i][j] = t[i - 1][j];
                }
            }
            cout << (bool)t[n][sum] << endl;
        }
    }
    return 0;
}