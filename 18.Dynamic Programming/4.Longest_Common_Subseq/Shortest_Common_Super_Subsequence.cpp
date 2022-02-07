#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Shortest_Common_Super_Subseq_Recur_Helper(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
    {
        return 1 + Shortest_Common_Super_Subseq_Recur_Helper(x, y, n - 1, m - 1);
    }
    else
    {
        return max(Shortest_Common_Super_Subseq_Recur_Helper(x, y, n - 1, m), Shortest_Common_Super_Subseq_Recur_Helper(x, y, n, m - 1));
    }
}

int Shortest_Common_Super_Subseq_Recur(string x, string y, int n, int m)
{
    int lcs_ans = Shortest_Common_Super_Subseq_Recur_Helper(x, y, n, m);
    return n + m - lcs_ans;
}

int Shortest_Common_Super_Subseq_Memo_Helper(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (x[n - 1] == y[m - 1])
    {
        dp[n][m] = 1 + Shortest_Common_Super_Subseq_Memo_Helper(x, y, n - 1, m - 1, dp);
    }
    else
    {
        dp[n][m] = max(Shortest_Common_Super_Subseq_Memo_Helper(x, y, n - 1, m, dp), Shortest_Common_Super_Subseq_Memo_Helper(x, y, n, m - 1, dp));
    }
    return dp[n][m];
}

int Shortest_Common_Super_Subseq_Memo(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int lcs_ans = Shortest_Common_Super_Subseq_Memo_Helper(x, y, n, m, dp);
    int i = n, j = m;
    string ans;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans = x[i - 1] + ans;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans = x[i - 1] + ans;
            i--;
        }
        else
        {
            ans = y[j - 1] + ans;
            j--;
        }
    }
    while (i > 0)
    {
        ans = x[i - 1] + ans;
        i--;
    }
    while (j > 0)
    {
        ans = y[j - 1] + ans;
        j--;
    }
    cout << ans << "\n";
    return n + m - lcs_ans;
}

int Shortest_Common_Super_Subseq_Tabu(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Initialized Also

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
    int i = n, j = m;
    string ans;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans = x[i - 1] + ans;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans = x[i - 1] + ans;
            i--;
        }
        else
        {
            ans = y[j - 1] + ans;
            j--;
        }
    }
    while (i > 0)
    {
        ans = x[i - 1] + ans;
        i--;
    }
    while (j > 0)
    {
        ans = y[j - 1] + ans;
        j--;
    }
    cout << ans << "\n";
    return n + m - dp[n][m];
}

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    // cout << Shortest_Common_Super_Subseq_Recur(x, y, n, m) << "\n";
    cout << Shortest_Common_Super_Subseq_Memo(x, y, n, m) << "\n";
    cout << Shortest_Common_Super_Subseq_Tabu(x, y, n, m) << "\n";
    return 0;
}