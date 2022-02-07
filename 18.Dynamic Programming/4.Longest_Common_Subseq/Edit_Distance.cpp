#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Minimum_Edit_Distance_Recur(string x, string y, int n, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (x[n - 1] == y[m - 1])
    {
        return Minimum_Edit_Distance_Recur(x, y, n - 1, m - 1);
    }
    else
    {
        int Insert = 1 + Minimum_Edit_Distance_Recur(x, y, n, m - 1);
        int Delete = 1 + Minimum_Edit_Distance_Recur(x, y, n - 1, m);
        int Replace = 1 + Minimum_Edit_Distance_Recur(x, y, n - 1, m - 1);
        return min(Insert, min(Delete, Replace));
    }
}

int Minimum_Edit_Distance_Memo(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (x[n - 1] == y[m - 1])
    {
        dp[n][m] = Minimum_Edit_Distance_Memo(x, y, n - 1, m - 1, dp);
    }
    else
    {
        int Insert = 1 + Minimum_Edit_Distance_Memo(x, y, n, m - 1, dp);
        int Delete = 1 + Minimum_Edit_Distance_Memo(x, y, n - 1, m, dp);
        int Replace = 1 + Minimum_Edit_Distance_Memo(x, y, n - 1, m - 1, dp);
        dp[n][m] = min(Insert, min(Delete, Replace));
    }
    return dp[n][m];
}

int Minimum_Edit_Distance_Tabu(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int Insert = 1 + dp[i][j - 1];
                int Delete = 1 + dp[i - 1][j];
                int Replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(Insert, min(Replace, Delete));
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    // Edit Distance -> Insert Delete Replace
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // cout << Minimum_Edit_Distance_Recur(x, y, n, m) << "\n";
    cout << Minimum_Edit_Distance_Memo(x, y, n, m, dp) << "\n";
    cout << Minimum_Edit_Distance_Tabu(x, y, n, m) << "\n";
    return 0;
}