#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Subset_Sum_Recur(int arr[], int n, int sum)
{
    if (n == 0 || sum == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    if (arr[n - 1] <= sum)
    {
        return Subset_Sum_Recur(arr, n - 1, sum - arr[n - 1]) + Subset_Sum_Recur(arr, n - 1, sum);
    }
    else
    {
        return Subset_Sum_Recur(arr, n - 1, sum);
    }
}

int Subset_Sum_Memo(int arr[], int n, int sum, vector<vector<int>> &dp)
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

    if (arr[n - 1] <= sum)
    {
        dp[n][sum] = Subset_Sum_Memo(arr, n - 1, sum - arr[n - 1], dp) + Subset_Sum_Memo(arr, n - 1, sum, dp);
    }
    else
    {
        dp[n][sum] = Subset_Sum_Memo(arr, n - 1, sum, dp);
    }
    return dp[n][sum];
}

int Subset_Sum_Tabulation(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
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

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    cout << Subset_Sum_Recur(arr, n, sum) << "\n";
    cout << Subset_Sum_Memo(arr, n, sum, dp) << "\n\n";
    for (int i = 0; i <= n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    cout << Subset_Sum_Tabulation(arr, n, sum, dp) << "\n\n";
    for (int i = 0; i <= n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}