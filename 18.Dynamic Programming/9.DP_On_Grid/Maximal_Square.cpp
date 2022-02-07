#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Maximal_Square_Brute(int n, int m, vector<vector<int>> &grid)
{
    for (int size = min(n, m); size >= 1; size--)
    {
        for (int i = 0; i < n - size + 1; i++)
        {
            for (int j = 0; j < m - size + 1; j++)
            {
                bool isSquare = true;
                for (int x = i; x < i + size; x++)
                {
                    for (int y = j; y < j + size; y++)
                    {
                        if (grid[x][y] == 0)
                        {
                            isSquare = false;
                            break;
                        }
                    }
                    if (!isSquare)
                        break;
                }
                if (isSquare)
                    return size * size;
            }
        }
    }
    return 0;
}

int Recur_Helper(int x, int y, vector<vector<int>> &grid)
{
    if (x >= grid.size() || y >= grid[0].size())
        return 0;
    if (grid[x][y] == 0)
        return 0;
    return 1 + min(Recur_Helper(x + 1, y + 1, grid), min(Recur_Helper(x + 1, y, grid), Recur_Helper(x, y + 1, grid)));
}

int Maximal_Square_Recur(int n, int m, vector<vector<int>> &grid)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            answer = max(answer, Recur_Helper(i, j, grid));
        }
    }
    return answer * answer;
}

int Memoize_Helper(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (x >= grid.size() || y >= grid[0].size())
        return 0;
    if (grid[x][y] == 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = 1 + min(Memoize_Helper(x + 1, y + 1, grid, dp), min(Memoize_Helper(x + 1, y, grid, dp), Memoize_Helper(x, y + 1, grid, dp)));
    return dp[x][y];
}

int Maximal_Square_Memoize(int n, int m, vector<vector<int>> &grid)
{
    int answer = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            answer = max(answer, Memoize_Helper(i, j, grid, dp));
        }
    }
    return answer * answer;
}

int Maximal_Square_Tabu(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) // Initialization
        dp[i][0] = grid[i][0];

    for (int i = 0; i < m; i++)
        dp[0][i] = grid[0][i];

    int answer = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            answer = max(answer, dp[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return answer * answer;
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
    // cout << Maximal_Square_Brute(n, m, grid) << "\n";
    // cout << Maximal_Square_Recur(n, m, grid) << "\n";
    // cout << Maximal_Square_Memoize(n, m, grid) << "\n";
    cout << Maximal_Square_Tabu(n, m, grid) << "\n";
    return 0;
}