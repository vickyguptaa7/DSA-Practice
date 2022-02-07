#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Minimum_Subset_Diff_Recur(int arr[], int n, int sum, int total_sum)
{
    if (n == 0)
    {
        return abs(total_sum - 2 * sum);
    }
    if (sum + arr[n - 1] <= total_sum / 2)
        return min(Minimum_Subset_Diff_Recur(arr, n - 1, sum + arr[n - 1], total_sum), Minimum_Subset_Diff_Recur(arr, n - 1, sum, total_sum));
    else
        return Minimum_Subset_Diff_Recur(arr, n - 1, sum, total_sum);
}

int Minimum_Subset_Diff_Memo(int arr[], int n, int sum, int total_sum, vector<vector<int>> dp)
{
    if (n == 0)
    {
        return abs(total_sum - 2 * sum);
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n - 1] + sum <= total_sum / 2)
        dp[n][sum] = min(Minimum_Subset_Diff_Memo(arr, n - 1, sum + arr[n - 1], total_sum, dp), Minimum_Subset_Diff_Memo(arr, n - 1, sum, total_sum, dp));
    else
        dp[n][sum] = Minimum_Subset_Diff_Memo(arr, n - 1, sum, total_sum, dp);
    return dp[n][sum];
}

int Minimum_Subset_Diff_Tabulation(int arr[], int n, int sum, vector<vector<int>> dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i] == 1)
        {
            return (sum - 2 * i);
        }
    }
    return sum;
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
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    cout << Minimum_Subset_Diff_Recur(arr, n, 0, sum) << "\n";
    cout << Minimum_Subset_Diff_Memo(arr, n, 0, sum, dp) << "\n";
    cout << Minimum_Subset_Diff_Tabulation(arr, n, sum, dp) << "\n";

    return 0;
}