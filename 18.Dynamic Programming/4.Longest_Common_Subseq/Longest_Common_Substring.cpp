#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Longest_Common_Substring_Recur(string x, string y, int n, int m, int count)
{
    if (n == 0 || m == 0)
        return count;
    if (x[n - 1] == y[m - 1])
    {
        count = Longest_Common_Substring_Recur(x, y, n - 1, m - 1, count + 1);
    }
    else
    {
        count = max(count, max(Longest_Common_Substring_Recur(x, y, n - 1, m, 0), Longest_Common_Substring_Recur(x, y, n, m - 1, 0)));
    }
    return count;
}

int Longest_Common_Substring_Memo(string x, string y, int n, int m, int count, int ***dp) // S.C O(n*m*min(m,n))
{
    if (n <= 0 || m <= 0)
        return count;
    if (dp[n][m][count] != -1)
        return dp[n][m][count];

    int lcs_count1 = 0, lcs_count2 = 0;
    lcs_count1 = count;
    if (x[n - 1] == y[m - 1])
    {
        lcs_count1 = Longest_Common_Substring_Memo(x, y, n - 1, m - 1, count + 1, dp);
    }
    lcs_count2 = max(Longest_Common_Substring_Memo(x, y, n - 1, m, 0, dp), Longest_Common_Substring_Memo(x, y, n, m - 1, 0, dp));
    dp[n][m][count] = max(lcs_count1, lcs_count2);
    return dp[n][m][count];
}

int Longest_Common_Substring_Memo_2(string x, string y, int n, int m, int &lcs_ans, vector<vector<int>> &dp) // S.C O(n*m*min(m,n))
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    Longest_Common_Substring_Memo_2(x, y, n - 1, m, lcs_ans, dp);
    Longest_Common_Substring_Memo_2(x, y, n, m - 1, lcs_ans, dp);
    if (x[n - 1] == y[m - 1])
    {
        dp[n][m] = Longest_Common_Substring_Memo_2(x, y, n - 1, m - 1, lcs_ans, dp) + 1;
        lcs_ans = max(lcs_ans, dp[n][m]);
        return dp[n][m];
    }
    dp[n][m] = 0;
    return dp[n][m];
}

int Longest_Common_Substring_Tabu(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(dp[i][j], result);
            }
            else
            {
                dp[i][j] = 0;
            }
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return result;
}

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    vector<vector<int>> table(n + 1, vector<int>(m + 1, -1));
    int ***dp = new int **[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int *[m + 1];
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = new int[min(n, m) + 1];
            for (int k = 0; k <= min(n, m); k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    int lcs_ans = 0;
    // cout << Longest_Common_Substring_Recur(x, y, n, m, 0) << "\n";
    cout << Longest_Common_Substring_Memo(x, y, n, m, 0, dp) << "\n";
    // cout << Longest_Common_Substring_Tabu(x, y, n, m, table) << "\n";
    // Longest_Common_Substring_Memo_2(x, y, n, m, lcs_ans, table);
    // cout << lcs_ans << "\n";

    return 0;
}