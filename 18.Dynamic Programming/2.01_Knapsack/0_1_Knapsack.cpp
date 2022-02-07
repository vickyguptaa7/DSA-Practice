#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Knapsack_Recursive_helper(vector<int> wt, vector<int> val, int itr, int cap, int profit, int &max_profit)
{
    if (cap < 0)
        return;
    if (itr == wt.size())
    {
        max_profit = max(max_profit, profit);
        return;
    }
    Knapsack_Recursive_helper(wt, val, itr + 1, cap, profit, max_profit);
    Knapsack_Recursive_helper(wt, val, itr + 1, cap - wt[itr], profit + val[itr], max_profit);
}

int Knapsacnk_1(vector<int> wt, vector<int> val, int cap)
{
    int max_profit = 0;
    Knapsack_Recursive_helper(wt, val, 0, cap, 0, max_profit);
    return max_profit;
}

int Knapsack_Recursive_2(vector<int> wt, vector<int> val, int cap, int size)
{
    if (size == 0 || cap == 0)
        return 0;
    if (wt[size - 1] <= cap)
    {
        return max(Knapsack_Recursive_2(wt, val, cap, size - 1),
                   Knapsack_Recursive_2(wt, val, cap - wt[size - 1], size - 1) + val[size - 1]);
    }
    else
    {
        return Knapsack_Recursive_2(wt, val, cap, size - 1);
    }
}

int Knapsack_Memo(vector<int> wt, vector<int> val, int cap, int n, vector<vector<int>> &dp)
{
    if (n == 0 || cap == 0)
        return 0;
    if (dp[n][cap] != -1)
        return dp[n][cap];
    if (wt[n - 1] <= cap)
    {
        dp[n][cap] = max(Knapsack_Memo(wt, val, cap - wt[n - 1], n - 1, dp) + val[n - 1], Knapsack_Memo(wt, val, cap, n - 1, dp));
        return dp[n][cap];
    }
    else
    {
        dp[n][cap] = Knapsack_Memo(wt, val, cap, n - 1, dp);
        return dp[n][cap];
    }
}

int Knapsack_Tabulation(vector<int> wt, vector<int> val, int cap, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1));
    for (int i = 0; i <= cap; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (j >= wt[i - 1])
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
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
    vector<int> wt(n), val(n);
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << Knapsacnk_1(wt, val, cap) << "\n";
    cout << Knapsack_Recursive_2(wt, val, cap, n) << "\n";
    cout << Knapsack_Memo(wt, val, cap, n, dp) << "\n";
    cout << Knapsack_Tabulation(wt, val, cap, n) << "\n";
    return 0;
}