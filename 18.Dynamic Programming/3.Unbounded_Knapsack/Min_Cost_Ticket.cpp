#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int helper(int index, int Cday, vector<int> &days, vector<int> &costs, vector<vector<int>> &dp)
{
    if (index == days.size())
        return 0;

    if (Cday <= days[index])
    {
        int profit = 1e9;
        profit = min(profit, costs[0] + helper(index + 1, Cday + 1, days, costs, dp));
        profit = min(profit, costs[1] + helper(index + 1, Cday + 7, days, costs, dp));
        profit = min(profit, costs[2] + helper(index + 1, Cday + 30, days, costs, dp));
        return profit;
    }
    else
        return helper(index + 1, Cday, days, costs, dp);
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    return helper(0, days[0], days, costs, dp);
}

int main()
{
    vector<int> arr = {1, 4, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 27, 28};
    vector<int> cost = {3, 13, 45};
    cout << mincostTickets(arr, cost) << "\n";
    return 0;
}