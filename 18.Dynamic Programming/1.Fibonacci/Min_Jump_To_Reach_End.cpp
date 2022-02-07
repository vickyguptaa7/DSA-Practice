#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Min_Jump_Recur(int arr[], int s, int n)
{
    if (s >= n)
        return 0;
    int Min = INT_MAX - 100;
    for (int i = 1; i <= arr[s]; i++)
    {
        Min = min(Min, 1 + Min_Jump_Recur(arr, i + s, n));
    }
    return Min;
}

int Min_Jump_Memo(int arr[], int s, int n, vector<int> &dp)
{
    if (s >= n)
        return 0;
    if (dp[s] != -1)
        return dp[s];
    int Min = 1e9;
    for (int i = 1; i <= arr[s]; i++)
    {
        Min = min(Min, 1 + Min_Jump_Memo(arr, i + s, n, dp));
    }
    dp[s] = Min;
    return dp[s];
}

int Min_Jump_Tabu(int arr[], int n)
{
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            int reachable = i + j;
            if (reachable > n)
                break;
            dp[reachable] = min(dp[reachable], 1 + dp[i]);
        }
    }
    for (auto x : dp)
        cout << x << " ";
    cout << "\n";
    return dp[n];
}

int Min_Jump_Greedy(int arr[], int n)
{
    int curr_max = arr[0], next_max = 0;
    int min_move = 1;
    for (int i = 1; i < n; i++)
    {
        next_max = max(next_max, arr[i] + i);
        if (i == curr_max)
        {
            curr_max = next_max;
            min_move++;
            next_max = 0;
        }
    }
    return min_move;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n + 1, -1);
    cout << Min_Jump_Recur(arr, 0, n) << "\n";
    cout << Min_Jump_Memo(arr, 0, n, dp) << "\n";
    cout << Min_Jump_Tabu(arr, n) << "\n";
    cout << Min_Jump_Greedy(arr, n) << "\n";
    return 0;
}
/*
11  
1 3 5 8 9 2 6 7 6 8 9

10
1 3 6 3 2 3 6 8 9 5
*/