#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Balloon_Burst_Recur(vector<int> &arr, int s, int n)
{
    if (s > n)
        return 0;
    if (s == n)
    {
        int temp_answer = arr[s];
        if (s - 1 >= 0)
            temp_answer *= arr[s - 1];
        if (s + 1 < arr.size())
            temp_answer *= arr[s + 1];
        return temp_answer;
    }
    int Max = 0;
    for (int k = s; k <= n; k++)
    {
        int temp_answer = arr[k];
        if (s - 1 >= 0)
            temp_answer *= arr[s - 1];
        if (n + 1 < arr.size())
            temp_answer *= arr[n + 1];
        temp_answer += Balloon_Burst_Recur(arr, s, k - 1) + Balloon_Burst_Recur(arr, k + 1, n);
        if (Max < temp_answer)
            Max = temp_answer;
    }
    return Max;
}

int Balloon_Burst_Memo(vector<int> &arr, int s, int n, vector<vector<int>> &dp)
{
    if (s > n)
        return 0;
    if (s == n)
    {
        int temp_answer = arr[s];
        if (s - 1 >= 0)
            temp_answer *= arr[s - 1];
        if (s + 1 < arr.size())
            temp_answer *= arr[s + 1];
        return temp_answer;
    }
    if (dp[s][n] != -1)
        return dp[s][n];
    int Max = 0;
    for (int k = s; k <= n; k++)
    {
        int temp_answer = arr[k];
        if (s - 1 >= 0)
            temp_answer *= arr[s - 1];
        if (n + 1 < arr.size())
            temp_answer *= arr[n + 1];
        temp_answer += Balloon_Burst_Memo(arr, s, k - 1, dp) + Balloon_Burst_Memo(arr, k + 1, n, dp);
        if (Max < temp_answer)
            Max = temp_answer;
    }
    dp[s][n] = Max;
    return Max;
}

int Balloon_Burst_Tabu(vector<int> arr, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    // Initialization
    for (int i = 1; i <= n; i++)
        dp[i][i] = arr[i - 1] * arr[i] * arr[i + 1];

    for (int size = 2; size <= n; size++)
    {
        for (int left = 1; left <= n - size + 1; left++)
        {
            int right = size + left - 1;
            int Max = 0;
            for (int k = left; k <= right; k++)
            {
                int cost = arr[left - 1] * arr[k] * arr[right + 1];
                cost += dp[left][k - 1];
                cost += dp[k + 1][right];
                if (Max < cost)
                    Max = cost;
            }
            dp[left][right] = Max;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return dp[1][n];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> newarr = {1};
    for (auto x : arr)
        newarr.push_back(x);
    newarr.push_back(1);
    n += 2;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << Balloon_Burst_Recur(newarr, 1, n - 2) << "\n";
    // cout << Balloon_Burst_Memo(newarr, 1, n - 2, dp) << "\n";
    cout << Balloon_Burst_Tabu(newarr, n - 2) << "\n";

    return 0;
}