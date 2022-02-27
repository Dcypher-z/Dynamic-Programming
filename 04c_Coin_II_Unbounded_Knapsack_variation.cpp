#include <bits/stdc++.h>
using namespace std;
int t[102][1002];

int Coin(int coin[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 0;

            if (i == 0)
                t[i][j] = INT_MAX -1;
            
            if(i==1 && j!=0)
            {
                if(j%coin[0]==0)
                {
                    t[i][j]=j/coin[0];
                }
                else
                {
                    t[i][j] = INT_MAX -1;
                }
            }

            if (coin[i - 1] <= sum && i!=0 || j!=0 || i!=1)
                t[i][j] = max(1 + t[i][j - coin[i - 1]], t[i - 1][j]);

            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    memset(t, -1, sizeof(t));
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    cout << Coin(coin, n, sum) << endl;

    return 0;
}