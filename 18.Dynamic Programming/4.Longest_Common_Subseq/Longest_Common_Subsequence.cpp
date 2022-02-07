#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Longest_Common_Substring_Recur(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (x[n - 1] == y[m - 1])
    {
        return 1 + Longest_Common_Substring_Recur(x, y, n - 1, m - 1);
    }
    else
    {
        return max(Longest_Common_Substring_Recur(x, y, n - 1, m), Longest_Common_Substring_Recur(x, y, n, m - 1));
    }
}

int Longest_Common_Substring_Memo(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
        return dp[n][m];
    if (x[n - 1] == y[m - 1])
    {
        dp[n][m] = 1 + Longest_Common_Substring_Memo(x, y, n - 1, m - 1, dp);
    }
    else
    {
        dp[n][m] = max(Longest_Common_Substring_Memo(x, y, n - 1, m, dp), Longest_Common_Substring_Memo(x, y, n, m - 1, dp));
    }
    return dp[n][m];
}

int Longest_Common_Substring_Tabu(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string x, y;
    cin >> x >> y;
    vector<vector<int>> dp(x.length() + 1, vector<int>(y.length() + 1, -1));
    cout << Longest_Common_Substring_Recur(x, y, x.length(), y.length()) << "\n";
    cout << Longest_Common_Substring_Memo(x, y, x.length(), y.length(), dp) << "\n";
    cout << Longest_Common_Substring_Tabu(x, y, x.length(), y.length(), dp) << "\n";
    return 0;
}