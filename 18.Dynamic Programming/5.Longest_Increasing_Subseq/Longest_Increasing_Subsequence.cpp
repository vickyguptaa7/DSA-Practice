#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Longest_Increasing_Subseq_Recur(int prev, int arr[], int n)
{
    if (n == 0)
        return 0;
    int l1 = 0, l2 = 0;
    if (prev == -1 || arr[prev] > arr[n - 1])
    {
        l1 = 1 + Longest_Increasing_Subseq_Recur(n - 1, arr, n - 1);
    }
    l2 = Longest_Increasing_Subseq_Recur(prev, arr, n - 1);
    return max(l1, l2);
}

int Longest_Increasing_Subseq_Memo_1(int prev, int arr[], int n, vector<vector<int>> &dp) // S.C -> O(n^2)
{
    if (n == 0)
        return 0;
    int l1 = 0, l2 = 0;
    if (prev != -1 && dp[n][prev + 1] != -1)
        return dp[n][prev + 1];
    if (prev == -1 || arr[prev] > arr[n - 1])
    {
        l1 = 1 + Longest_Increasing_Subseq_Memo_1(n - 1, arr, n - 1, dp);
    }
    l2 = Longest_Increasing_Subseq_Memo_1(prev, arr, n - 1, dp);
    dp[n][prev + 1] = max(l1, l2);

    return dp[n][prev + 1];
}

int Longest_Increasing_Subseq_Memo_2(int prev, int arr[], int n, vector<int> &dp) // S.C -> O(n)
{
    if (n == 0)
        return 0;
    int l1 = 0, l2 = 0;
    if (dp[prev + 1] != -1)
        return dp[prev + 1];
    if (prev == -1 || arr[prev] > arr[n - 1])
    {
        l1 = 1 + Longest_Increasing_Subseq_Memo_2(n - 1, arr, n - 1, dp);
    }
    l2 = Longest_Increasing_Subseq_Memo_2(prev, arr, n - 1, dp);
    dp[prev + 1] = max(l1, l2);
    return dp[prev + 1];
}

int Longest_Increasing_Subseq_Tabu(int arr[], int n)
{
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_lis = 0, curr = 0, ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_lis)
        {
            max_lis = dp[i];
            curr = arr[i];
        }
    }
    ans = max_lis;
    vector<int> lis;
    for (int i = n - 1; i >= 0; i--)
    {
        if (max_lis == dp[i] && curr >= arr[i])
        {
            lis.push_back(arr[i]);
            curr = arr[i];
            max_lis--;
        }
    }
    reverse(lis.begin(), lis.end());
    // for (auto x : lis)
    //     cout << x << " ";
    // cout << "\n";
    return ans;
}

int Longest_Increasing_Subseq_Optemize(int arr[], int n) // T.C->O(nlogn)
{
    vector<int> Tail, Lis_arr;
    Tail.push_back(arr[0]);
    Lis_arr.push_back(1);
    for (int i = 1; i < n; i++)
    {
        if (Tail.back() < arr[i])
        {
            Tail.push_back(arr[i]);
            Lis_arr.push_back(Tail.size());
        }
        else
        {
            int indx = upper_bound(Tail.begin(), Tail.end(), arr[i]) - Tail.begin();
            if (indx > 0 && Tail[indx - 1] == arr[i])
            {
                Lis_arr.push_back(indx);
                continue;
            }
            Tail[indx] = arr[i];
            Lis_arr.push_back(indx + 1);
        }
    }
    // for (auto x : Lis_arr)
    //     cout << x << " ";
    // cout << "\n";
    return Tail.size();
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<int> table(n + 1, -1);
    // cout << Longest_Increasing_Subseq_Recur(-1, arr, n) << "\n";
    // cout << Longest_Increasing_Subseq_Memo_1(-1, arr, n, dp) << "\n";
    // cout << Longest_Increasing_Subseq_Memo_2(-1, arr, n, table) << "\n";
    // cout << Longest_Increasing_Subseq_Tabu(arr, n) << "\n";
    cout << Longest_Increasing_Subseq_Optemize(arr, n) << "\n";
    return 0;
}
// 10 22 9 33 21 50 41 60