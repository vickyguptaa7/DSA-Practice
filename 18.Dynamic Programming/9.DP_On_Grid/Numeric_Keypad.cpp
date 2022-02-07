#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long Ways(int x, int y, int n, vector<vector<char>> &keypad, vector<vector<long long>> &dp)
{
    if (x >= keypad.size() || y >= keypad[0].size() || x < 0 || y < 0 || keypad[x][y] == '*' || keypad[x][y] == '#')
        return 0;
    if (n == 1)
        return 1;
    if (dp[keypad[x][y] - '0'][n] != -1)
        return dp[keypad[x][y] - '0'][n];
    long long Count = Ways(x, y, n - 1, keypad, dp) +
                      Ways(x + 1, y, n - 1, keypad, dp) +
                      Ways(x, y + 1, n - 1, keypad, dp) +
                      Ways(x - 1, y, n - 1, keypad, dp) +
                      Ways(x, y - 1, n - 1, keypad, dp);
    return dp[keypad[x][y] - '0'][n] = Count;
}

long long Numeric_Keypad_Ways(int n, vector<vector<char>> &keypad)
{
    long long count = 0;
    vector<vector<long long>> dp(10, vector<long long>(n + 1, -1));
    for (int i = 0; i < keypad.size(); i++)
    {
        for (int j = 0; j < keypad[0].size(); j++)
        {
            if (keypad[i][j] != '*' && keypad[i][j] != '#')
            {
                count += Ways(i, j, n, keypad, dp);
            }
        }
    }
    return count;
}

long long Numeric_Keypad_Ways_Tabu(int n, vector<vector<char>> &keypad)
{
    vector<vector<int>> move = {
        {0, 8},
        {1, 2, 4},
        {2, 1, 3, 5},
        {2, 3, 6},
        {1, 4, 5, 7},
        {2, 4, 5, 6, 8},
        {3, 5, 6, 9},
        {4, 7, 8},
        {0, 5, 7, 8, 9},
        {6, 8, 9}};
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (i == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                for (auto x : move[j])
                {
                    dp[i][j] += dp[i - 1][x];
                }
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < 10; i++)
    {
        res += dp[n][i];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> keypad =
        {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'},
            {'*', '0', '#'}};
    cout << Numeric_Keypad_Ways(n, keypad) << "\n";      // Recursion
    cout << Numeric_Keypad_Ways_Tabu(n, keypad) << "\n"; // Tabulation
    return 0;
}