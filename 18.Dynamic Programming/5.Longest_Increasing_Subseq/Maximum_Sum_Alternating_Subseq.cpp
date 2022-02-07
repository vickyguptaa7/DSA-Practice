#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Maximum_Sum_Alternating_Subseq_Recur(int arr[], int n, bool isneg)
{
    if (n == 0)
        return 0;

    int sum1 = Maximum_Sum_Alternating_Subseq_Recur(arr, n - 1, isneg);
    int sum2 = (isneg) ? arr[n - 1] : -arr[n - 1];
    sum2 += Maximum_Sum_Alternating_Subseq_Recur(arr, n - 1, !isneg);
    return max(sum1, sum2);
}

int Maximum_Sum_Alternating_Subseq_Memo(int arr[], int n, bool isPos, vector<vector<int>> &dp)
{
    if (n == 0)
        return 0;
    if (dp[isPos][n - 1] != -1)
        return dp[isPos][n - 1];

    int not_pick = Maximum_Sum_Alternating_Subseq_Memo(arr, n - 1, isPos, dp);
    int pick = (isPos) ? arr[n - 1] : -arr[n - 1];
    pick += Maximum_Sum_Alternating_Subseq_Memo(arr, n - 1, !isPos, dp);

    dp[isPos][n - 1] = max(not_pick, pick);
    return dp[isPos][n - 1];
}

int Maximum_Sum_Alternating_Subseq_Tabu(int arr[], int n)
{
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[1][0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + arr[i]);
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - arr[i]);
    }
    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0;
    vector<vector<int>> dp(2, vector<int>(n, -1));
    // cout << Maximum_Sum_Alternating_Subseq_Recur(arr, n, true) << "\n";
    // cout << Maximum_Sum_Alternating_Subseq_Memo(arr, n, true, dp) << "\n";
    cout << Maximum_Sum_Alternating_Subseq_Tabu(arr, n) << "\n";

    return 0;
}