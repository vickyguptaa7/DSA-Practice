#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Profit_With_CoolDown_Recur(int arr[], int s, bool isBuy, int n)
{
    if (s >= n)
        return 0;
    int profit = 0;
    if (isBuy)
    {
        int dontBuy = Max_Profit_With_CoolDown_Recur(arr, s + 1, isBuy, n);
        int Buy = Max_Profit_With_CoolDown_Recur(arr, s + 1, !isBuy, n) - arr[s];
        profit = max(dontBuy, Buy);
    }
    else
    {
        int dontSell = Max_Profit_With_CoolDown_Recur(arr, s + 1, isBuy, n);
        int Sell = arr[s] + Max_Profit_With_CoolDown_Recur(arr, s + 2, !isBuy, n);
        profit = max(dontSell, Sell);
    }
    return profit;
}

int Max_Profit_With_CoolDown_Memo(int arr[], int s, bool isBuy, int n, vector<vector<int>> &dp)
{
    if (s >= n)
        return 0;
    if (dp[s][isBuy] != -1)
        return dp[s][isBuy];
    int profit = 0;
    if (isBuy)
    {
        int dontBuy = Max_Profit_With_CoolDown_Memo(arr, s + 1, isBuy, n, dp);
        int Buy = Max_Profit_With_CoolDown_Memo(arr, s + 1, !isBuy, n, dp) - arr[s];
        profit = max(dontBuy, Buy);
    }
    else
    {
        int dontSell = Max_Profit_With_CoolDown_Memo(arr, s + 1, isBuy, n, dp);
        int Sell = arr[s] + Max_Profit_With_CoolDown_Memo(arr, s + 2, !isBuy, n, dp);
        profit = max(dontSell, Sell);
    }
    dp[s][isBuy] = profit;
    return profit;
}

int Max_Profit_With_CoolDown_Tabulation(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -arr[0];
    dp[1][1] = max(dp[0][1], dp[0][0] - arr[1]);
    dp[1][0] = max(dp[0][0], dp[0][1] + arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - arr[i]);
    }
    return dp[n - 1][0];
}

int main()
{
    int n, fee;
    cin >> n >> fee;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << Max_Profit_With_CoolDown_Recur(arr, 0, 1, n) << "\n";
    cout << Max_Profit_With_CoolDown_Memo(arr, 0, 1, n, dp) << "\n";
    cout << Max_Profit_With_CoolDown_Tabulation(arr, n) << "\n";

    return 0;
}
/*
12 3
10
15
17
20
16
18
22
20
22
20
23
25
*/