#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Profit_With_Transac_Fee_Recur(int arr[], int s, bool isBuy, int n, int fee)
{
    if (s >= n)
        return 0;
    int profit = 0;
    if (isBuy)
    {
        int dontBuy = Max_Profit_With_Transac_Fee_Recur(arr, s + 1, isBuy, n, fee);
        int Buy = Max_Profit_With_Transac_Fee_Recur(arr, s + 1, !isBuy, n, fee) - arr[s];
        profit = max(dontBuy, Buy);
    }
    else
    {
        int dontSell = Max_Profit_With_Transac_Fee_Recur(arr, s + 1, isBuy, n, fee);
        int Sell = arr[s] - fee + Max_Profit_With_Transac_Fee_Recur(arr, s + 1, !isBuy, n, fee);
        profit = max(dontSell, Sell);
    }
    return profit;
}

int Max_Profit_With_Transac_Fee_Memo(int arr[], int s, bool isBuy, int n, vector<vector<int>> &dp, int fee)
{
    if (s >= n)
        return 0;
    if (dp[s][isBuy] != -1)
        return dp[s][isBuy];
    int profit = 0;
    if (isBuy)
    {
        int dontBuy = Max_Profit_With_Transac_Fee_Memo(arr, s + 1, isBuy, n, dp, fee);
        int Buy = Max_Profit_With_Transac_Fee_Memo(arr, s + 1, !isBuy, n, dp, fee) - arr[s];
        profit = max(dontBuy, Buy);
    }
    else
    {
        int dontSell = Max_Profit_With_Transac_Fee_Memo(arr, s + 1, isBuy, n, dp, fee);
        int Sell = arr[s] - fee + Max_Profit_With_Transac_Fee_Memo(arr, s + 1, !isBuy, n, dp, fee);
        profit = max(dontSell, Sell);
    }
    dp[s][isBuy] = profit;
    return profit;
}

int Max_Profit_With_Transac_Fee_Tabulation(int arr[], int n, int fee)
{
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -arr[0];
    for (int i = 1; i < n; i++)
    {
        int buy_profit = dp[i - 1][1];
        int sell_profit = dp[i - 1][0];

        if (buy_profit < sell_profit - arr[i])
        {
            buy_profit = sell_profit - arr[i];
        }
        if (sell_profit < buy_profit + arr[i] - fee)
        {
            sell_profit = buy_profit + arr[i] - fee;
        }
        dp[i][0] = sell_profit;
        dp[i][1] = buy_profit;
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
    cout << Max_Profit_With_Transac_Fee_Recur(arr, 0, 1, n, fee) << "\n";
    cout << Max_Profit_With_Transac_Fee_Memo(arr, 0, 1, n, dp, fee) << "\n";
    cout << Max_Profit_With_Transac_Fee_Tabulation(arr, n, fee) << "\n";

    return 0;
}