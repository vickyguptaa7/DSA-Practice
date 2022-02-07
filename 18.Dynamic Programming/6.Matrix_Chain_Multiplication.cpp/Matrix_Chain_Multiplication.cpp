#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int MCM_Recur(int arr[], int left, int right)
{
    if (left >= right)
        return 0;
    int min_answer = 1e9;
    for (int k = left; k < right; k++)
    {
        int temp_ans = MCM_Recur(arr, left, k) + MCM_Recur(arr, k + 1, right) + arr[left - 1] * arr[k] * arr[right];
        if (min_answer > temp_ans)
            min_answer = temp_ans;
    }
    return min_answer;
}

int MCM_Memo(int arr[], int left, int right, vector<vector<int>> &dp)
{
    if (left >= right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];
    int min_answer = 1e9;
    for (int k = left; k < right; k++)
    {
        int temp_ans = MCM_Memo(arr, left, k, dp) + MCM_Memo(arr, k + 1, right, dp) + arr[left - 1] * arr[k] * arr[right];
        if (min_answer > temp_ans)
            min_answer = temp_ans;
    }
    dp[left][right] = min_answer;
    return dp[left][right];
}

int MCM_Tabu(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++)
    {
        for (int left = 1; left < n - len + 1; left++)
        {
            int right = len + left - 1;
            dp[left][right] = 1e9;
            for (int k = left; k < right; k++)
            {
                int left_cost = dp[left][k];
                int right_cost = dp[k + 1][right];
                int current_cost = arr[left - 1] * arr[k] * arr[right];
                int total_cost = left_cost + right_cost + current_cost;
                dp[left][right] = min(dp[left][right], total_cost);
            }
        }
    }
    return dp[1][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << MCM_Recur(arr, 1, n - 1) << "\n";
    cout << MCM_Memo(arr, 1, n - 1, dp) << "\n";
    // cout << MCM_Tabu(arr, n) << "\n";
    return 0;
}