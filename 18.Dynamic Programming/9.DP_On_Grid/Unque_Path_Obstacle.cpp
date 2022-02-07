#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Unique_Path_Recur(int n, int m, vector<vector<int>> &matrix)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0 || matrix[n][m] == 1)
        return 0;
    return Unique_Path_Recur(n - 1, m, matrix) + Unique_Path_Recur(n, m - 1, matrix);
}

int Unique_Path_Memo(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0 || matrix[n][m] == 1)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    dp[n][m] = Unique_Path_Memo(n - 1, m, matrix, dp) + Unique_Path_Memo(n, m - 1, matrix, dp);
    return dp[n][m];
}

int Unique_Path_Tabu(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (matrix[i][0] == 1)
        {
            dp[i][0] = 0;
            continue;
        }
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        if (matrix[0][i] == 1)
        {
            dp[0][i] = 0;
            continue;
        }
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : dp[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return dp[n - 1][m - 1];
}

int main()
{
    // 1 for obstacle in matrix
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << Unique_Path_Recur(n - 1, m - 1, matrix) << "\n";
    // cout << Unique_Path_Memo(n - 1, m - 1, matrix, dp) << "\n";
    cout << Unique_Path_Tabu(n, m, matrix) << "\n";

    return 0;
}