#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Min_Inst_Del_Recur_helper(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
    {
        return 1 + Min_Inst_Del_Recur_helper(x, y, n - 1, m - 1);
    }
    else
    {
        return max(Min_Inst_Del_Recur_helper(x, y, n - 1, m), Min_Inst_Del_Recur_helper(x, y, n, m - 1));
    }
}

void Min_Inst_Del_Recur(string x, string y, int n, int m)
{
    int lcs_ans = Min_Inst_Del_Recur_helper(x, y, n, m);
    int insrt = m - lcs_ans;
    int del = n - lcs_ans;
    cout << insrt << " " << del << "\n";
}

int Min_Inst_Del_Memo_helper(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (x[n - 1] == y[m - 1])
    {
        dp[n][m] = 1 + Min_Inst_Del_Memo_helper(x, y, n - 1, m - 1, dp);
    }
    else
    {
        dp[n][m] = max(Min_Inst_Del_Memo_helper(x, y, n - 1, m, dp), Min_Inst_Del_Memo_helper(x, y, n, m - 1, dp));
    }
    return dp[n][m];
}

void Min_Inst_Del_Memo(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int lcs_ans = Min_Inst_Del_Memo_helper(x, y, n, m, dp);
    int insrt = m - lcs_ans;
    int del = n - lcs_ans;
    cout << insrt << " " << del << "\n";
}

void Min_Inst_Del_Tabu(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Initialize Also
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
    int insrt = m - dp[n][m];
    int del = n - dp[n][m];
    cout << insrt << " " << del << "\n";
}

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    Min_Inst_Del_Recur(x, y, n, m);
    Min_Inst_Del_Memo(x, y, n, m);
    Min_Inst_Del_Tabu(x, y, n, m);
    return 0;
}