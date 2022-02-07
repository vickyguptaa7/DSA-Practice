#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Target_Sum_Recur(int arr[], int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    if (sum >= arr[n - 1])
    {
        return Target_Sum_Recur(arr, n - 1, sum - arr[n - 1]) + Target_Sum_Recur(arr, n - 1, sum);
    }
    else
    {
        return Target_Sum_Recur(arr, n - 1, sum);
    }
}

int Target_Sum_Memo(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    if (n == 0)
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
        dp[n][sum] = Target_Sum_Memo(arr, n - 1, sum - arr[n - 1], dp) + Target_Sum_Memo(arr, n - 1, sum, dp);
    }
    else
    {
        dp[n][sum] = Target_Sum_Memo(arr, n - 1, sum, dp);
    }
    return dp[n][sum];
}

int Target_Sum_Tabu(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for (int j = 0; j <= n; j++)
        dp[j][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, total_sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total_sum += arr[i];
    }
    int target;
    cin >> target;
    int new_target = (total_sum + target) / 2;
    if (total_sum < abs(target) || (total_sum + target) % 2 != 0)
    {
        cout << "Not Possible\n";
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(new_target + 1, -1));
    cout << Target_Sum_Recur(arr, n, new_target) << "\n";
    cout << Target_Sum_Memo(arr, n, new_target, dp) << "\n";
    cout << Target_Sum_Tabu(arr, n, new_target, dp) << "\n";
    return 0;
}