#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Coin_Change_Ways_Recur(int arr[], int n, int sum)
{
    if (n == 0 || sum == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    if (sum >= arr[n - 1])
    {
        return Coin_Change_Ways_Recur(arr, n, sum - arr[n - 1]) + Coin_Change_Ways_Recur(arr, n - 1, sum);
    }
    else
    {
        return Coin_Change_Ways_Recur(arr, n - 1, sum);
    }
}

int Coin_Change_Ways_Memo(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    if (n == 0 || sum == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (sum >= arr[n - 1])
    {
        dp[n][sum] = Coin_Change_Ways_Memo(arr, n, sum - arr[n - 1], dp) + Coin_Change_Ways_Memo(arr, n - 1, sum, dp);
    }
    else
    {
        dp[n][sum] = Coin_Change_Ways_Memo(arr, n - 1, sum, dp);
    }
    return dp[n][sum];
}

int Coin_Change_Ways_Tabu(int arr[], int n, int sum, vector<vector<int>> dp)
{
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
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
    cout << Coin_Change_Ways_Recur(arr, n, sum) << "\n";
    cout << Coin_Change_Ways_Memo(arr, n, sum, dp) << "\n";
    cout << Coin_Change_Ways_Tabu(arr, n, sum, dp) << "\n";
    return 0;
}