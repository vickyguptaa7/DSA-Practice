#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> LCS(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
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
    return dp;
}

void Print_LCS(vector<vector<int>> dp, string x, string y)
{
    int i = dp.size(), j = dp[0].size();
    string ans;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            i--;
            j--;
            ans += x[i];
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    Print_LCS(LCS(x, y, n, m), x, y);
    return 0;
}