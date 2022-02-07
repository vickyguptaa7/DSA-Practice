#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Coin_Change_Min_Recur(int n, int arr[], int sum)
{
    if (n == 0 || sum == 0)
    {
        if (sum == 0)
            return 0;
        else
            return 1e9;
    }
    if (sum >= arr[n - 1])
    {
        return min(1 + Coin_Change_Min_Recur(n, arr, sum - arr[n - 1]), Coin_Change_Min_Recur(n - 1, arr, sum));
    }
    else
    {
        return Coin_Change_Min_Recur(n - 1, arr, sum);
    }
}

int Coin_Change_Min_Memo(int n, int arr[], int sum, vector<vector<int>> &dp)
{
    if (n == 0 || sum == 0)
    {
        if (sum == 0)
            return 0;
        else
            return 1e9;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (sum >= arr[n - 1])
    {
        dp[n][sum] = min(1 + Coin_Change_Min_Memo(n, arr, sum - arr[n - 1], dp), Coin_Change_Min_Memo(n - 1, arr, sum, dp));
    }
    else
    {
        dp[n][sum] = Coin_Change_Min_Memo(n - 1, arr, sum, dp);
    }
    return dp[n][sum];
}

int Coin_Change_Min_Tabu(int n, int arr[], int sum, vector<vector<int>> dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 1e9;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - arr[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    cout << Coin_Change_Min_Recur(n, arr, sum) << "\n";
    cout << Coin_Change_Min_Memo(n, arr, sum, dp) << "\n";
    cout << Coin_Change_Min_Tabu(n, arr, sum, dp) << "\n";
    return 0;
}