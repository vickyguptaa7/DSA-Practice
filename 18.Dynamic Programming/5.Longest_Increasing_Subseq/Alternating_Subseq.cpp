#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Alternating_Subseq_Recurr(int n, int prev, bool isIncreasing, int arr[], vector<vector<int>> &dp)
{
    if (n <= 0)
        return 0;
    if (dp[n][isIncreasing] != -1)
        return dp[n][isIncreasing];
    int max_len = 0;
    if (isIncreasing)
    {
        if (arr[prev - 1] < arr[n - 1])
        {
            max_len = 1 + Alternating_Subseq_Recurr(n - 1, n, !isIncreasing, arr, dp);
        }
        else
        {
            max_len = Alternating_Subseq_Recurr(n - 1, prev, isIncreasing, arr, dp);
        }
    }
    else
    {
        if (arr[prev - 1] > arr[n - 1])
        {
            max_len = 1 + Alternating_Subseq_Recurr(n - 1, n, !isIncreasing, arr, dp);
        }
        else
        {
            max_len = Alternating_Subseq_Recurr(n - 1, prev, isIncreasing, arr, dp);
        }
    }
    dp[n][isIncreasing] = max_len;
    return max_len;
}

int Alternating_Subseq_Tabu(int n, int arr[])
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][1] = dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
                continue;
            if (arr[i] > arr[j])
            {
                dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
            }
            else
            {
                dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
            }
        }
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int Alternating_Subseq_Opti(int n, int arr[])
{
    int increasing = 1, decreasing = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            increasing = decreasing + 1;
        }
        else if (arr[i] < arr[i - 1])
        {
            decreasing = increasing + 1;
        }
    }
    return max(increasing, decreasing);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    cout << 1 + max(Alternating_Subseq_Recurr(n - 1, n, true, arr, dp), Alternating_Subseq_Recurr(n - 1, n, false, arr, dp)) << "\n";
    cout << Alternating_Subseq_Tabu(n, arr) << "\n";
    cout << Alternating_Subseq_Opti(n, arr) << "\n";
    return 0;
}