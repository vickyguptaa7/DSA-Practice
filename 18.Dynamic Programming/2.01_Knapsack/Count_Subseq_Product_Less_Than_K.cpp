#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Ways_Recur(int arr[], int n, int k, vector<vector<int>> &dp)
{
    if (k == 0 || n == 0)
        return 0;

    if (dp[n][k] != -1)
        return dp[n][k];

    if (k >= arr[n - 1])
    {
        dp[n][k] = 1 + Ways_Recur(arr, n - 1, k, dp) + Ways_Recur(arr, n - 1, k / arr[n - 1], dp);
    }
    else
        dp[n][k] = Ways_Recur(arr, n - 1, k, dp);
    return dp[n][k];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout << Ways_Recur(arr, n, k, dp) << "\n";
    return 0;
}