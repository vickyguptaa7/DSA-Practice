#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Unique_Path_Recur(int n, int m)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;
    return Unique_Path_Recur(n - 1, m) + Unique_Path_Recur(n, m - 1);
}

int Unique_Path_Memo(int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    dp[n][m] = Unique_Path_Memo(n - 1, m, dp) + Unique_Path_Memo(n, m - 1, dp);
    return dp[n][m];
}

int Unique_Path_Tabu(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = 0;
    for (int i = 1; i < n; i++)
        dp[i][0] = 1;
    for (int i = 1; i < m; i++)
        dp[0][i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << Unique_Path_Recur(n - 1, m - 1) << "\n";
    cout << Unique_Path_Memo(n - 1, m - 1, dp) << "\n";
    cout << Unique_Path_Tabu(n, m) << "\n";

    return 0;
}