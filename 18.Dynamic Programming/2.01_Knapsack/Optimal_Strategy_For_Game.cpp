#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Optimal_Strategy_Recur(int s, int n, int arr[], vector<vector<int>> &dp)
{
    if (s > n)
        return 0;
    if (s == n)
        return arr[s];
    if (dp[s][n] != -1)
        return dp[s][n];
    int left_profit = arr[s];
    int right_profit = arr[n];
    left_profit += min(Optimal_Strategy_Recur(s + 1, n - 1, arr, dp), Optimal_Strategy_Recur(s + 2, n, arr, dp));
    right_profit += min(Optimal_Strategy_Recur(s + 1, n - 1, arr, dp), Optimal_Strategy_Recur(s, n - 2, arr, dp));
    dp[s][n] = max(left_profit, right_profit);
    return dp[s][n];
}

int Optimal_Strategy_Tabu(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = arr[i];
    for (int size = 2; size <= n; size++)
    {
        for (int left = 0; left < n - size + 1; left++)
        {
            int right = size + left - 1;
            int left_profit = arr[left];
            int right_profit = arr[right];
            if (size > 2)
            {
                left_profit += min(dp[left + 1][right - 1], dp[left + 2][right]);
                right_profit += min(dp[left + 1][right - 1], dp[left][right - 2]);
            }

            dp[left][right] = max(left_profit, right_profit);
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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << Optimal_Strategy_Recur(0, n - 1, arr, dp) << "\n";
    cout << Optimal_Strategy_Tabu(arr, n) << "\n";
    return 0;
}