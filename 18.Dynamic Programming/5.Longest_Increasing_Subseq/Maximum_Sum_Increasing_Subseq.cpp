#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Maximum_Sum_Increasing_Subseq_Recur(int arr[], int prev, int n)
{
    if (n == 0)
        return 0;
    int include = 0, not_include = 0;
    if (prev == -1 || arr[prev] > arr[n - 1])
    {
        include = arr[n - 1] + Maximum_Sum_Increasing_Subseq_Recur(arr, n - 1, n - 1);
    }
    not_include = Maximum_Sum_Increasing_Subseq_Recur(arr, prev, n - 1);
    return max(include, not_include);
}

int Maximum_Sum_Increasing_Subseq_Memo(int arr[], int prev, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[prev + 1] != -1)
        return dp[prev + 1];
    int include = 0, not_include = 0;
    if (prev == -1 || arr[prev] > arr[n - 1])
    {
        include = arr[n - 1] + Maximum_Sum_Increasing_Subseq_Memo(arr, n - 1, n - 1, dp);
    }
    not_include = Maximum_Sum_Increasing_Subseq_Memo(arr, prev, n - 1, dp);
    dp[prev + 1] = max(include, not_include);
    return dp[prev + 1];
}

int Maximum_Sum_Increasing_Subseq_Tabulation(int arr[], int n)
{
    vector<int> dp(n, 0); // initialized
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    int max = 0;
    for (auto x : dp)
        if (max < x)
            max = x;
    return max;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n + 1, -1);
    // cout << Maximum_Sum_Increasing_Subseq_Recur(arr, -1, n) << "\n";
    cout << Maximum_Sum_Increasing_Subseq_Memo(arr, -1, n, dp) << "\n";
    // cout << Maximum_Sum_Increasing_Subseq_Tabulation(arr, n) << "\n";
    return 0;
}