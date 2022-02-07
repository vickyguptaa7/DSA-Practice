#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Count_Ways_Recur(int n, int m)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    int No_Of_Ways = 0;
    for (int i = 1; i <= m; i++)
    {
        No_Of_Ways += Count_Ways_Recur(n - i, m);
    }
    return No_Of_Ways;
}

int Count_Ways_Memo(int n, int m, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int No_Of_Ways = 0;
    for (int i = 1; i <= m; i++)
    {
        No_Of_Ways += Count_Ways_Memo(n - i, m, dp);
    }
    dp[n] = No_Of_Ways;

    return dp[n];
}

int Count_Ways_Tabu(int n, int m)
{
    // Initializations
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m && j <= i; j++)
        {
            dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, -1);
    // cout << Count_Ways_Recur(n, m) << "\n";
    // cout << Count_Ways_Memo(n, m, dp) << "\n";
    cout << Count_Ways_Tabu(n, m) << "\n";
    return 0;
}