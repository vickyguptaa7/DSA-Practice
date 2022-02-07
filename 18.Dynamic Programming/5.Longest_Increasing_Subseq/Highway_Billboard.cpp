#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int Max_Profit_Highway(int dist[], int revn[], int n, int m, int t) // T.C O(n^2)
{
    vector<int> dp(revn, revn + n);
    int max_profit = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dist[i] - dist[j] > t)
            {
                dp[i] = max(dp[i], dp[j] + revn[i]);
            }
        }
        max_profit = max(max_profit, dp[i]);
    }
    return max_profit;
}

int Max_Profit_Highway_M(int dist[], int revn[], int n, int m, int t) // T.C O(m)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
        umap[dist[i]] = revn[i];
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        if (umap.find(i) == umap.end())
        {
            dp[i] = dp[i - 1];
            continue;
        }
        int not_install = dp[i - 1];
        int install = umap[i];
        if (i - t - 1 >= 0)
            install += dp[i - t - 1];
        dp[i] = max(install, not_install);
    }
    return dp[m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int dist[n], revn[n];
    for (int i = 0; i, i < n; i++)
        cin >> dist[i];
    for (int i = 0; i, i < n; i++)
        cin >> revn[i];
    int t = 0;
    cin >> t;
    cout << Max_Profit_Highway(dist, revn, n, m, t) << "\n";
    cout << Max_Profit_Highway_M(dist, revn, n, m, t) << "\n";
    return 0;
}
/*
5
20
6 7 12 13 14
5 6 5 3 1
5

4
15
6 9 12 14
5 6 3 7
2
*/