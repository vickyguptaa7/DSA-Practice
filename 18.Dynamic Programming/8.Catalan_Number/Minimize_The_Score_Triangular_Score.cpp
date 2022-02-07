#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Min_Score_Triangular_Recur(int price[], int s, int n)
{
    if (s + 1 >= n)
        return 0;
    int result = 1e9;
    for (int k = s + 1; k < n; k++)
    {
        result = min(result, price[s] * price[k] * price[n] +
                                 Min_Score_Triangular_Recur(price, s, k) + Min_Score_Triangular_Recur(price, k, n));
    }
    return result;
}

int Min_Score_Triangular_Memo(int price[], int s, int n, vector<vector<int>> &dp)
{
    if (s + 1 >= n)
        return 0;
    if (dp[s][n] != -1)
        return dp[s][n];
    int result = 1e9;
    for (int k = s + 1; k < n; k++)
    {
        result = min(result, price[s] * price[k] * price[n] +
                                 Min_Score_Triangular_Memo(price, s, k, dp) + Min_Score_Triangular_Memo(price, k, n, dp));
    }
    dp[s][n] = result;
    return result;
}

int Min_Score_Triangular_Tabu(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0)); // initialized
    for (int size = 3; size <= n; size++)
    {
        for (int left = 0; left < n - size + 1; left++)
        {
            int right = left + size - 1;
            int result = 1e9;
            for (int k = left + 1; k < right; k++)
            {
                result = min(result, price[left] * price[k] * price[right] + dp[left][k] + dp[k][right]);
            }
            dp[left][right] = result;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return dp[0][n - 1];
}

int main()
{
    // MCM Problem
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << Min_Score_Triangular_Recur(price, 0, n - 1) << "\n";
    cout << Min_Score_Triangular_Memo(price, 0, n - 1, dp) << "\n";
    cout << Min_Score_Triangular_Tabu(price, n) << "\n";
    return 0;
}