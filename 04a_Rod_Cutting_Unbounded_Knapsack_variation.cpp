#include <bits/stdc++.h>
using namespace std;
int t[102][1002];

int RodCutting(int len[], int val[], int l, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < l + 1; j++)
        {
            if (j == 0 || i == 0)
                t[i][j] = 0;
            else if (len[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
}

int main()
{
    memset(t, -1, sizeof(t));
    int n;
    cin >> n;
    int price[n];
    int length[n];
    int l;
    cin >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
        length[i] = i + 1;
    }
    cout<<RodCutting(length, price, l, n)<<endl;
    return 0;
}