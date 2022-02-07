#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Count_Dearrangement_Recur(int n, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (n - 1) * (Count_Dearrangement_Recur(n - 1, dp) + Count_Dearrangement_Recur(n - 2, dp));
    return dp[n];
}

int Count_Dearrangement_Tabu(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

int Count_Dearrangement_Tabu_Opti(int n)
{
    int a1 = 0, a2 = 1;
    for (int i = 3; i <= n; i++)
    {
        int a3 = (i - 1) * (a1 + a2);
        a1 = a2;
        a2 = a3;
    }
    return a2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << Count_Dearrangement_Recur(n, dp) << "\n";
    cout << Count_Dearrangement_Tabu(n) << "\n";
    cout << Count_Dearrangement_Tabu_Opti(n) << "\n";

    return 0;
}