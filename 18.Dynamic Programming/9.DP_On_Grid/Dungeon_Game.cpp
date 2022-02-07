#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Min_Health_Recur(int x, int y, vector<vector<int>> &grid)
{
    if (x == grid.size() - 1 && y == grid[0].size() - 1)
        return (grid[x][y] <= 0) ? -grid[x][y] + 1 : 1;
    if (x >= grid.size() || y >= grid[0].size())
        return 1e9;
    int Health = min(Min_Health_Recur(x + 1, y, grid), Min_Health_Recur(x, y + 1, grid));
    Health -= grid[x][y];
    if (Health <= 0)
        Health = 1;
    return Health;
}

int Min_Health_Memo(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (x == grid.size() - 1 && y == grid[0].size() - 1)
        return (grid[x][y] <= 0) ? -grid[x][y] + 1 : 1;
    if (x >= grid.size() || y >= grid[0].size())
        return 1e9;
    if (dp[x][y] != -1)
        return dp[x][y];
    int Health = min(Min_Health_Memo(x + 1, y, grid, dp), Min_Health_Memo(x, y + 1, grid, dp));
    Health -= grid[x][y];
    if (Health <= 0)
        Health = 1;
    dp[x][y] = Health;
    return Health;
}

int Min_Health_Tabulation(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; i++)
        dp[n][i] = 1e9;
    for (int i = 0; i <= n; i++)
        dp[i][m] = 1e9;
    dp[n - 1][m] = 1;
    dp[n][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int Health = min(dp[i][j + 1], dp[i + 1][j]);
            Health -= grid[i][j];
            if (Health <= 0)
                Health = 1;
            dp[i][j] = Health;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return dp[0][0];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << Min_Health_Recur(0, 0, grid) << "\n";
    cout << Min_Health_Memo(0, 0, grid, dp) << "\n";
    cout << Min_Health_Tabulation(n, m, grid) << "\n";
    return 0;
}

/*
3 3
-2 -3 3
-5 -10 1
10 30 -5
*/