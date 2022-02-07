#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Number_Of_Valleys_And_Mountain_Recur(int n, int up, int down)
{
    if (up == n && down == n)
        return 1;
    int cnt = 0;
    if (up < n)
        cnt += Number_Of_Valleys_And_Mountain_Recur(n, up + 1, down);
    if (up > down)
        cnt += Number_Of_Valleys_And_Mountain_Recur(n, up, down + 1);
    return cnt;
}

int Number_Of_Valleys_And_Mountain_Memo(int n, int up, int down, vector<vector<int>> &dp)
{
    if (up == n && down == n)
        return 1;

    if (dp[up][down] != -1)
        return dp[up][down];
    int cnt = 0;
    if (up < n)
        cnt += Number_Of_Valleys_And_Mountain_Memo(n, up + 1, down, dp);
    if (up > down)
        cnt += Number_Of_Valleys_And_Mountain_Memo(n, up, down + 1, dp);
    dp[up][down] = cnt;
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << Number_Of_Valleys_And_Mountain_Recur(n, 0, 0) << "\n";
    cout << Number_Of_Valleys_And_Mountain_Memo(n, 0, 0, dp) << "\n";
    for (int i = 0; i <= n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}