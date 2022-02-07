#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Coin_Game_Winner(int n, int arr[], vector<int> &dp)
{
    if (n == 0)
        return false;
    if (n == 1)
        return true;
    if (dp[n] != -1)
        return dp[n];
    bool who_win = 0;
    for (int k = 0; k < 3; k++)
    {
        if (n < arr[k])
            continue;
        who_win = (who_win | (!Coin_Game_Winner(n - arr[k], arr, dp)));
    }
    return dp[n] = who_win;
}

int Coin_Game_Winner_Tabu(int n, int arr[])
{
    vector<bool> dp(n + 1, 0);
    dp[0] = false;
    dp[1] = true;
    for (int i = 2; i <= n; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (i < arr[k])
                continue;
            dp[i] = (dp[i] | (!dp[i - arr[k]]));
        }
    }
    for (auto x : dp)
        cout << x << " ";
    cout << "\n";
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int arr[3] = {1};
    for (int i = 1; i < 3; i++)
        cin >> arr[i];
    vector<int> dp(n + 1, -1);
    cout << Coin_Game_Winner(n, arr, dp) << "\n";
    cout << Coin_Game_Winner_Tabu(n, arr) << "\n";
    return 0;
}