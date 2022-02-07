#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Maximum_Sum_M_Non_Overalaping_Subarray_Recur(vector<int> &presum, int s, int m, int k)
{
    if (m == 0)
        return 0;
    if (s >= presum.size())
        return 0;
    int include = presum[s] + Maximum_Sum_M_Non_Overalaping_Subarray_Recur(presum, s + k, m - 1, k);
    int exclude = Maximum_Sum_M_Non_Overalaping_Subarray_Recur(presum, s + 1, m, k);
    int Max = max(include, exclude);
    return Max;
}

int Maximum_Sum_M_Non_Overalaping_Subarray_Memo(vector<int> &presum, int s, int m, int k, vector<vector<int>> &dp)
{
    if (m == 0)
        return 0;
    if (s >= presum.size())
        return 0;
    if (dp[s][m] != -1)
        return dp[s][m];
    int include = presum[s] + Maximum_Sum_M_Non_Overalaping_Subarray_Memo(presum, s + k, m - 1, k, dp);
    int exclude = Maximum_Sum_M_Non_Overalaping_Subarray_Memo(presum, s + 1, m, k, dp);
    dp[s][m] = max(include, exclude);
    return dp[s][m];
}

vector<int> K_Presum_Array(int arr[], int n, int k)
{
    vector<int> presum(n - k + 1, 0);
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    presum[0] = sum;
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        presum[i - k + 1] = sum;
    }
    return presum;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> Presum = K_Presum_Array(arr, n, k);
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));

    cout << Maximum_Sum_M_Non_Overalaping_Subarray_Recur(Presum, 0, m, k) << "\n";
    cout << Maximum_Sum_M_Non_Overalaping_Subarray_Memo(Presum, 0, m, k, dp) << "\n";
    return 0;
}
/*
8
3 2
1 2 1 2 6 7 5 1
*/