#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Helper(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (x == n || y == m || x < 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    int profit = 0;
    profit = max(profit, Helper(x - 1, y + 1, n, m, grid, dp));
    profit = max(profit, Helper(x, y + 1, n, m, grid, dp));
    profit = max(profit, Helper(x + 1, y + 1, n, m, grid, dp));
    profit += grid[x][y];
    dp[x][y] = profit;
    return profit;
}

int Gold_Mine(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int Max_Profit = 0;
    for (int i = 0; i < n; i++)
    {
        Max_Profit = max(Max_Profit, Helper(i, 0, n, m, grid, dp));
    }
    return Max_Profit;
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
    cout << Gold_Mine(n, m, grid) << "\n";
    return 0;
}