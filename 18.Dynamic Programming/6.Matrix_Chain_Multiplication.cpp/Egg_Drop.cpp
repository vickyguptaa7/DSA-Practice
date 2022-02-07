#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Egg_Drop_Recur(int egg, int floor)
{
    if (floor == 0 || floor == 1)
        return floor;
    if (egg == 1)
        return floor;
    int Min = 1e9;
    for (int k = 1; k <= floor; k++)
    {
        int temp_answer = 1 + max(Egg_Drop_Recur(egg - 1, k - 1), Egg_Drop_Recur(egg, floor - k));
        if (Min > temp_answer)
            Min = temp_answer;
    }
    return Min;
}

int Egg_Drop_Memo(int egg, int floor, vector<vector<int>> &dp)
{
    if (floor == 0 || floor == 1)
        return floor;
    if (egg == 1)
        return floor;
    if (dp[egg][floor] != -1)
        return dp[egg][floor];
    int Min = 1e9;
    for (int k = 1; k <= floor; k++)
    {
        int temp_answer = 1 + max(Egg_Drop_Memo(egg - 1, k - 1, dp), Egg_Drop_Memo(egg, floor - k, dp));
        if (Min > temp_answer)
            Min = temp_answer;
    }
    dp[egg][floor] = Min;
    return Min;
}

int Egg_Drop_Tabu(int egg, int floor)
{
    vector<vector<int>> dp(egg + 1, vector<int>(floor + 1, 0));
    for (int i = 1; i <= floor; i++)
        dp[1][i] = i;
    for (int i = 2; i <= egg; i++)
    {
        for (int j = 1; j <= floor; j++)
        {
            int Min = 1e9;
            for (int k = 1; k <= j; k++)
            {
                int temp_answer = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
                if (Min > temp_answer)
                    Min = temp_answer;
            }
            dp[i][j] = Min;
        }
    }
    for (int i = 0; i <= egg; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return dp[egg][floor];
}

int main()
{
    int egg, floor;
    cin >> egg >> floor;
    vector<vector<int>> dp(egg + 1, vector<int>(floor + 1, -1));
    // cout << Egg_Drop_Recur(egg, floor) << "\n";
    // cout << Egg_Drop_Memo(egg, floor, dp) << "\n";
    cout << Egg_Drop_Tabu(egg, floor) << "\n";
    return 0;
}