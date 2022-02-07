#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Optimal_Bst_Min_Search_Cost_Recur(int s, int n, int h, vector<int> &arr, vector<int> &freq, vector<vector<vector<int>>> &dp) // T.C->O(n^2) S.C O(n^3)
{
    if (s > n)
        return 0;
    if (s == n)
    {
        return h * freq[s];
    }
    if (dp[s][n][h] != -1)
        return dp[s][n][h];
    int min_cost = 1e9;
    for (int k = s; k <= n; k++)
    {
        int temp = h * freq[k];
        temp += Optimal_Bst_Min_Search_Cost_Recur(s, k - 1, h + 1, arr, freq, dp) + Optimal_Bst_Min_Search_Cost_Recur(k + 1, n, h + 1, arr, freq, dp);
        if (temp < min_cost)
            min_cost = temp;
    }
    return dp[s][n][h] = min_cost;
}

int Optimal_Bst_Min_Search_Cost_Recur_Space_Opti(int s, int n, vector<int> &arr, vector<int> &freq, vector<vector<int>> &dp) // T.C->O(n^2) S.C O(n^2)
{
    if (s > n)
        return 0;
    if (s == n)
    {
        return freq[s];
    }
    if (dp[s][n] != -1)
        return dp[s][n];
    int min_cost = 1e9;
    for (int k = s; k <= n; k++)
    {
        int temp = 0;
        for (int i = s; i <= n; i++)
            temp += freq[i];
        temp += Optimal_Bst_Min_Search_Cost_Recur_Space_Opti(s, k - 1, arr, freq, dp) + Optimal_Bst_Min_Search_Cost_Recur_Space_Opti(k + 1, n, arr, freq, dp);

        if (temp < min_cost)
            min_cost = temp;
    }
    return dp[s][n] = min_cost;
}

int Optimal_Bst_Min_Search_Cost_Tabu(vector<int> &arr, vector<int> &freq)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = freq[i];
    }
    for (int size = 2; size <= n; size++)
    {
        for (int left = 0; left < n - size + 1; left++)
        {
            int right = left + size - 1, min_cost = 1e9;
            for (int k = left; k <= right; k++)
            {
                int temp = 0;
                for (int i = left; i <= right; i++)
                {
                    temp += freq[i];
                }
                if (k > left)
                    temp += dp[left][k - 1];
                if (k < right)
                    temp += dp[k + 1][right];
                if (temp < min_cost)
                    min_cost = temp;
            }
            dp[left][right] = min_cost;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), freq(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] >> freq[i];
    }
    vector<vector<vector<int>>> dp(n + 1, (vector<vector<int>>(n + 1, vector<int>(n + 1, -1))));
    vector<vector<int>> table(n, vector<int>(n, -1));
    cout << Optimal_Bst_Min_Search_Cost_Recur(0, n - 1, 1, arr, freq, dp) << "\n";
    cout << Optimal_Bst_Min_Search_Cost_Recur_Space_Opti(0, n - 1, arr, freq, table) << "\n";
    cout << Optimal_Bst_Min_Search_Cost_Tabu(arr, freq) << "\n";
    return 0;
}
/*
3
10 34 12 8 20 50
*/