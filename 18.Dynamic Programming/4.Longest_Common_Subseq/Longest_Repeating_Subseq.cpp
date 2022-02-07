#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Longest_Repeating_Subseq_Recur(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1] && n != m)
    {
        return 1 + Longest_Repeating_Subseq_Recur(x, y, n - 1, m - 1);
    }
    else
    {
        return max(Longest_Repeating_Subseq_Recur(x, y, n - 1, m), Longest_Repeating_Subseq_Recur(x, y, n, m - 1));
    }
}

int Longest_Repeating_Subseq_Memo(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (x[n - 1] == y[m - 1] && n != m)
    {
        dp[n][m] = 1 + Longest_Repeating_Subseq_Memo(x, y, n - 1, m - 1, dp);
    }
    else
    {
        dp[n][m] = max(Longest_Repeating_Subseq_Memo(x, y, n - 1, m, dp), Longest_Repeating_Subseq_Memo(x, y, n, m - 1, dp));
    }
    return dp[n][m];
}

int Longest_Repeating_Subseq_Tabu(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1] && j != i)
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
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << Longest_Repeating_Subseq_Recur(str, str, n, n) << "\n";
    cout << Longest_Repeating_Subseq_Memo(str, str, n, n, dp) << "\n";
    cout << Longest_Repeating_Subseq_Tabu(str, str, n, n, dp) << "\n";
    return 0;
}