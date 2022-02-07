#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Minimum_Path_Sum_Recur(int n, int m, vector<vector<int>> &matrix)
{
    if (n == 0 && m == 0)
        return matrix[n][m];
    if (n < 0 || m < 0)
        return 1e9;
    return matrix[n][m] + min(Minimum_Path_Sum_Recur(n - 1, m, matrix), Minimum_Path_Sum_Recur(n, m - 1, matrix));
}

int Minimum_Path_Sum_Memo(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return matrix[n][m];
    if (n < 0 || m < 0)
        return 1e9;
    if (dp[n][m] != -1)
        return dp[n][m];
    dp[n][m] = matrix[n][m] + min(Minimum_Path_Sum_Memo(n - 1, m, matrix, dp), Minimum_Path_Sum_Memo(n, m - 1, matrix, dp));
    return dp[n][m];
}

int Minimum_Path_Sum_Tabu(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    for (int i = 1; i < m; i++)
    {

        dp[0][i] = dp[0][i - 1] + matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
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
    cout << Minimum_Path_Sum_Recur(n - 1, m - 1, matrix) << "\n";
    cout << Minimum_Path_Sum_Memo(n - 1, m - 1, matrix, dp) << "\n";
    cout << Minimum_Path_Sum_Tabu(n, m, matrix) << "\n";

    return 0;
}