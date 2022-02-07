#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Profit_Recur(int house[], int n)
{
    if (n <= 0)
        return 0;
    return max(Max_Profit_Recur(house, n - 1), house[n - 1] + Max_Profit_Recur(house, n - 2));
}

int Max_Profit_Memo(int house[], int n, vector<int> &dp)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = max(Max_Profit_Memo(house, n - 1, dp), house[n - 1] + Max_Profit_Memo(house, n - 2, dp));
    return dp[n];
}

int Max_Profit_Tabulation(int house[], int n)
{
    vector<int> dp(n, 0);
    dp[0] = house[0];
    dp[1] = max(house[0], house[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(house[i] + dp[i - 2], dp[i - 1]);
    }
    for (auto x : dp)
        cout << x << " ";
    cout << endl;
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    int house[n];
    for (int i = 0; i < n; i++)
        cin >> house[i];
    vector<int> dp(n + 1, -1);
    cout << Max_Profit_Recur(house, n) << "\n";
    cout << Max_Profit_Memo(house, n, dp) << "\n";
    cout << Max_Profit_Tabulation(house, n) << "\n";
    return 0;
}