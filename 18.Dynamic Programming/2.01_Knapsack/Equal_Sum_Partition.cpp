#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool Equal_Sum_Partition_Recur(int arr[], int n, int sum)
{
    if (n == 0 || sum == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    if (sum >= arr[n - 1])
        return Equal_Sum_Partition_Recur(arr, n - 1, sum - arr[n - 1]) || Equal_Sum_Partition_Recur(arr, n - 1, sum);

    else
        return Equal_Sum_Partition_Recur(arr, n - 1, sum - arr[n - 1]);
}

bool Equal_Sum_Partition_Memo(int arr[], int n, int sum, vector<vector<int>> &dp)
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
        dp[n][sum] = Equal_Sum_Partition_Memo(arr, n - 1, sum - arr[n - 1], dp) || Equal_Sum_Partition_Memo(arr, n - 1, sum, dp);
    else
        dp[n][sum] = Equal_Sum_Partition_Memo(arr, n - 1, sum, dp);
    return dp[n][sum];
}

bool Equal_Sum_Partition_Tabulation(int arr[], int n, int sum, vector<vector<int>> &dp)
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
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum & 1)
    {
        cout << "Not Possible" << endl;
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
    cout << Equal_Sum_Partition_Recur(arr, n, sum / 2) << "\n";
    cout << Equal_Sum_Partition_Memo(arr, n, sum / 2, dp) << "\n";
    cout << Equal_Sum_Partition_Tabulation(arr, n, sum / 2, dp) << "\n";
    return 0;
}