#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Sum_No_3_Consec_Recur(int arr[], int n, int k, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
        return -1e9;
    if (dp[n][k] != -1)
        return dp[n][k];
    int max_profit = 0;
    if (k == 2)
    {
        max_profit += Max_Sum_No_3_Consec_Recur(arr, n - 1, 0, dp);
        return dp[n][k] = max_profit;
    }
    else
    {
        max_profit += max(arr[n - 1] + Max_Sum_No_3_Consec_Recur(arr, n - 1, k + 1, dp), Max_Sum_No_3_Consec_Recur(arr, n - 1, 0, dp));
        return dp[n][k] = max_profit;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    cout << Max_Sum_No_3_Consec_Recur(arr, n, 0, dp) << "\n";
    return 0;
}