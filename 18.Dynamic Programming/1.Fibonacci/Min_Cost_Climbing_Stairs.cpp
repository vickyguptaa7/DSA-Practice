#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Min_Cost_Recur(int cost[], int s, int n, int k)
{
    if (s >= n)
        return 0;
    int Min = 1e9;
    for (int i = 1; i <= k; i++)
    {
        Min = min(Min, cost[s] + Min_Cost_Recur(cost, s + i, n, k));
    }
    return Min;
}

int Min_Cost_Memo(int cost[], int s, int n, int k, vector<int> &dp)
{
    if (s >= n)
        return 0;
    if (dp[s] != -1)
        return dp[s];
    int Min = 1e9;
    for (int i = 1; i <= k; i++)
    {
        Min = min(Min, cost[s] + Min_Cost_Memo(cost, s + i, n, k, dp));
    }
    dp[s] = Min;
    return dp[s];
}

int Min_Cost_Tabu(int arr[], int s, int n, int k)
{
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    if (s == 1)
        dp[s] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int reachable = i + j;
            if (reachable > n)
                break;
            dp[reachable] = min(dp[reachable], arr[i] + dp[i]);
        }
    }
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int cost[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    vector<int> dp(n, -1);
    cout << min(Min_Cost_Recur(cost, 0, n, k), Min_Cost_Recur(cost, 1, n, k)) << "\n";
    cout << min(Min_Cost_Memo(cost, 0, n, k, dp), Min_Cost_Memo(cost, 1, n, k, dp)) << "\n";
    cout << min(Min_Cost_Tabu(cost, 0, n, k), Min_Cost_Tabu(cost, 1, n, k)) << "\n";
    return 0;
}
/*
10 2
1 100 1 1 1 100 1 1 100 1

5 3
10 30 40 50 20
*/