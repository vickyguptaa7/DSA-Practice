#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Unbounded_Knapsack_Recur(int wt[], int val[], int cap, int n)
{
    if (n == 0 || cap == 0)
    {
        return 0;
    }
    if (cap >= wt[n - 1])
    {
        return max(val[n - 1] + Unbounded_Knapsack_Recur(wt, val, cap - wt[n - 1], n), Unbounded_Knapsack_Recur(wt, val, cap, n - 1));
    }
    else
    {
        return Unbounded_Knapsack_Recur(wt, val, cap, n - 1);
    }
}

int Unbounded_Knapsack_Memo(int wt[], int val[], int cap, int n, vector<vector<int>> dp)
{
    if (n == 0 || cap == 0)
    {
        return 0;
    }
    if (dp[n][cap] != -1)
        return dp[n][cap];
    if (cap >= wt[n - 1])
    {
        dp[n][cap] = max(val[n - 1] + Unbounded_Knapsack_Memo(wt, val, cap - wt[n - 1], n, dp), Unbounded_Knapsack_Memo(wt, val, cap, n - 1, dp));
    }
    else
    {
        dp[n][cap] = Unbounded_Knapsack_Memo(wt, val, cap, n - 1, dp);
    }
    return dp[n][cap];
}

int Unbounded_Knapsack_Tabu(int wt[], int val[], int cap, int n, vector<vector<int>> dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= cap; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (j >= wt[i - 1])
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][cap];
}

int main()
{
    int n, cap;
    cin >> n >> cap;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> wt[j];
    }
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
    cout << Unbounded_Knapsack_Recur(wt, val, cap, n) << "\n";
    cout << Unbounded_Knapsack_Memo(wt, val, cap, n, dp) << "\n";
    cout << Unbounded_Knapsack_Tabu(wt, val, cap, n, dp) << "\n";
    return 0;
}