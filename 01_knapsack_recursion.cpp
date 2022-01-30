#include <iostream>
using namespace std;

// each item can be put once only

int knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    
    if (wt[n - 1] <= w)
        return max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
    
    else if(wt[n-1]>w)
        return knapsack(wt, val, w, n-1);

    return 0;
}
int main()
{
    int weight[]={1,3,4,5};
    int value[]={1,4,5,7};
    int W = 7;
    cout<<knapsack(weight, value, W, 4);
    return 0;
}
