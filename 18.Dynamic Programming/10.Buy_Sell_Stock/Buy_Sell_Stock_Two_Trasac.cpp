#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Profit_Two_Transac_Recur(int arr[], int s, bool isBuy, int k, int n)
{
    if (s >= n || k < 0)
        return 0;
    int profit = 0;
    if (isBuy)
    {
        int p1 = Max_Profit_Two_Transac_Recur(arr, s + 1, isBuy, k, n);
        int p2 = Max_Profit_Two_Transac_Recur(arr, s + 1, !isBuy, k - 1, n) - arr[s];
        profit = max(p1, p2);
    }
    else
    {
        int p1 = Max_Profit_Two_Transac_Recur(arr, s + 1, isBuy, k, n);
        int p2 = arr[s] + Max_Profit_Two_Transac_Recur(arr, s + 1, !isBuy, k, n);
        profit = max(p1, p2);
    }
    return profit;
}

int Max_Profit_Two_Transac_Memo(int arr[], int s, bool isBuy, int k, int n, vector<vector<vector<int>>> &dp)
{
    if (s >= n || k < 0)
        return 0;
    if (dp[s][k][isBuy] != -1)
        return dp[s][k][isBuy];
    int profit = 0;
    if (isBuy)
    {
        int p1 = Max_Profit_Two_Transac_Memo(arr, s + 1, isBuy, k, n, dp);
        int p2 = Max_Profit_Two_Transac_Memo(arr, s + 1, !isBuy, k - 1, n, dp) - arr[s];
        profit = max(p1, p2);
    }
    else
    {
        int p1 = Max_Profit_Two_Transac_Memo(arr, s + 1, isBuy, k, n, dp);
        int p2 = arr[s] + Max_Profit_Two_Transac_Memo(arr, s + 1, !isBuy, k, n, dp);
        profit = max(p1, p2);
    }
    dp[s][k][isBuy] = profit;
    return profit;
}
int Max_Profit_Two_Transac_Tabu(int arr[], int n)
{
    vector<int> dp_left(n, 0);
    dp_left[0] = 0;
    int least_so_far = arr[0];
    int max_profit_sell_today = 0;
    for (int i = 1; i < n; i++)
    {
        if (least_so_far > arr[i])
            least_so_far = arr[i];
        max_profit_sell_today = arr[i] - least_so_far;
        if (max_profit_sell_today > dp_left[i - 1])
            dp_left[i] = max_profit_sell_today;
        else
            dp_left[i] = dp_left[i - 1];
    }
    vector<int> dp_right(n, 0);
    dp_right[n - 1] = 0;
    int max_so_far = arr[n - 1];
    int max_profit_buy_today = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (max_so_far < arr[i])
            max_so_far = arr[i];
        max_profit_buy_today = max_so_far - arr[i];
        if (max_profit_buy_today > dp_right[i + 1])
            dp_right[i] = max_profit_buy_today;
        else
            dp_right[i] = dp_right[i + 1];
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, dp_left[i] + dp_right[i]);
    }
    for (auto x : dp_left)
        cout << x << " ";
    cout << "\n";
    for (auto x : dp_right)
        cout << x << " ";
    cout << "\n";
    return answer;
}

int main()
{
    int n, k = 2;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2 + 1, vector<int>(2, -1)));
    cout << Max_Profit_Two_Transac_Recur(arr, 0, 1, 2, n) << "\n";
    cout << Max_Profit_Two_Transac_Memo(arr, 0, 1, 2, n, dp) << "\n";
    cout << Max_Profit_Two_Transac_Tabu(arr, n) << "\n";

    return 0;
}