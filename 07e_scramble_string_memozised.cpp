#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> temp;

bool solve(string a, string b)
{
    string key = a+" "+b;
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    if(temp.find(key)!=temp.end())
    {
        return temp[key];
    }
    int n = a.length();
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        if (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i)) || solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n - i), b.substr(0, n-i)))
        {
            flag = true;
            break;
        }
    }
    temp[key] = flag;
    return flag;
}

int main()
{
    string a = "grate";
    string b = "great";
    if (a.length() != b.length())
    {
        cout << false << endl;
    }
    else if (a.length() == 0)
    {
        cout << true << endl;
    }
    else
    {
        solve(a, b);
        cout<<temp[a+" "+b];
    }
    return 0;
}