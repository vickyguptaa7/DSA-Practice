#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(vector<int> b1, vector<int> b2)
{
    if (b1[0] != b2[0])
        return b1[0] < b2[0];
    else
        return b1[1] > b2[1];
}

int Max_Hight_Box_Stacking(int len[], int bred[], int hght[], int n)
{
    vector<vector<int>> Box; // length,breadth,hight
    for (int i = 0; i < n; i++)
    {

        Box.push_back({max(len[i], bred[i]), min(len[i], bred[i]), hght[i]});
        Box.push_back({max(len[i], hght[i]), min(len[i], hght[i]), bred[i]});
        Box.push_back({max(hght[i], bred[i]), min(hght[i], bred[i]), len[i]});
    }
    sort(Box.begin(), Box.end(), mycomp);
    vector<int> dp(3 * n, 0);
    for (int i = 0; i < 3 * n; i++) // Initialization
    {
        dp[i] = Box[i][2];
    }
    int max_profit = 0;
    for (int i = 1; i < 3 * n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Box[i][1] > Box[j][1])
            {
                dp[i] = max(dp[i], dp[j] + Box[i][2]);
            }
        }
        max_profit = max(max_profit, dp[i]);
    }
    return max_profit;
}

int main()
{
    int n;
    cin >> n;
    int len[n], bred[n], hght[n];
    for (int i = 0; i < n; i++)
        cin >> len[i];
    for (int i = 0; i < n; i++)
        cin >> bred[i];
    for (int i = 0; i < n; i++)
        cin >> hght[i];
    cout << Max_Hight_Box_Stacking(len, bred, hght, n) << "\n";

    return 0;
}
/*
4
4 1 4 10
6 2 5 12
7 3 6 32

3
10 4 4
32 7 6
12 6 5
*/