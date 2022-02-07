#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Profit_K_Transac_Recur(int arr[], int s, bool isBuy, int k, int n)
{
    if (s >= n || k < 0)
        return 0;
    int profit = 0;
    if (isBuy)
    {
        int p1 = Max_Profit_K_Transac_Recur(arr, s + 1, isBuy, k, n);
        int p2 = Max_Profit_K_Transac_Recur(arr, s + 1, !isBuy, k - 1, n) - arr[s];
        profit = max(p1, p2);
    }
    else
    {
        int p1 = Max_Profit_K_Transac_Recur(arr, s + 1, isBuy, k, n);
        int p2 = arr[s] + Max_Profit_K_Transac_Recur(arr, s + 1, !isBuy, k, n);
        profit = max(p1, p2);
    }
    return profit;
}

int Max_Profit_K_Transac_Memo(int arr[], int s, bool isBuy, int k, int n, vector<vector<vector<int>>> &dp)
{
    if (s >= n || k < 0)
        return 0;
    if (dp[s][k][isBuy] != -1)
        return dp[s][k][isBuy];
    int profit = 0;
    if (isBuy)
    {
        int p1 = Max_Profit_K_Transac_Memo(arr, s + 1, isBuy, k, n, dp);
        int p2 = Max_Profit_K_Transac_Memo(arr, s + 1, !isBuy, k - 1, n, dp) - arr[s];
        profit = max(p1, p2);
    }
    else
    {
        int p1 = Max_Profit_K_Transac_Memo(arr, s + 1, isBuy, k, n, dp);
        int p2 = arr[s] + Max_Profit_K_Transac_Memo(arr, s + 1, !isBuy, k, n, dp);
        profit = max(p1, p2);
    }
    dp[s][k][isBuy] = profit;
    return profit;
}

int Max_Profit_K_Transac_Tabu(int arr[], int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int profit = 0;
            for (int k = 0; k < j; k++)
            {
                profit = max(profit, arr[j] - arr[k] + dp[i - 1][k]);
            }
            dp[i][j] = max(dp[i][j - 1], profit);
        }
    }
    for (int i = 0; i <= k; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return dp[k][n - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    // cout << Max_Profit_K_Transac_Recur(arr, 0, 1, k, n) << "\n";
    // cout << Max_Profit_K_Transac_Memo(arr, 0, 1, k, n, dp) << "\n";
    cout << Max_Profit_K_Transac_Tabu(arr, k, n) << "\n";
    return 0;
}
/*
6 2
10 22 5 75 65 80
*/