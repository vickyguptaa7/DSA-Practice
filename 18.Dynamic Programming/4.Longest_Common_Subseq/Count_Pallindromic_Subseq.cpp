#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Pallindromic_Subseq_Memo(int s, int e, string str, vector<vector<int>> &dp)
{
    if (s > e)
        return 0;
    if (s == e)
        return 1;
    if (dp[s][e] != -1)
        return dp[s][e];
    if (str[s] == str[e])
    {
        dp[s][e] = 1 + Pallindromic_Subseq_Memo(s + 1, e, str, dp) + Pallindromic_Subseq_Memo(s, e - 1, str, dp);
    }
    else
    {
        dp[s][e] = Pallindromic_Subseq_Memo(s + 1, e, str, dp) + Pallindromic_Subseq_Memo(s, e - 1, str, dp) - Pallindromic_Subseq_Memo(s + 1, e - 1, str, dp);
    }
    return dp[s][e];
}

int Pallindromic_Subseq_Tabu(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int size = 2; size <= n; size++)
    {
        for (int left = 0; left < n - size + 1; left++)
        {
            int right = left + size - 1;
            if (str[left] == str[right])
            {
                dp[left][right] = 1 + dp[left + 1][right] + dp[left][right - 1];
            }
            else
            {
                dp[left][right] = dp[left + 1][right] + dp[left][right - 1] - dp[left + 1][right - 1];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return dp[0][n - 1];
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << Pallindromic_Subseq_Memo(0, n - 1, str, dp) << "\n";
    cout << Pallindromic_Subseq_Tabu(str) << "\n";

    return 0;
}