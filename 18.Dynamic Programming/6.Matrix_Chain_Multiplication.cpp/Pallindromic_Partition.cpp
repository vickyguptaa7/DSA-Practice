#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isPallindrome(int s, int n, string str)
{
    while (s <= n)
    {
        if (str[s++] != str[n--])
            return 0;
    }
    return 1;
}

int Minimum_Pallindromic_Partition_Recur(int s, int n, string str)
{
    if (s >= n || isPallindrome(s, n, str))
        return 0;
    int min_answer = 1e9;
    for (int k = s; k < n; k++)
    {
        int temp_answer = 1 + Minimum_Pallindromic_Partition_Recur(s, k, str) + Minimum_Pallindromic_Partition_Recur(k + 1, n, str);
        min_answer = min(min_answer, temp_answer);
    }
    return min_answer;
}

int Minimum_Pallindromic_Partition_Memo(int s, int n, string str, vector<vector<int>> &dp)
{
    if (s >= n || isPallindrome(s, n, str))
        return 0;
    if (dp[s][n] != -1)
        return dp[s][n];
    int min_answer = 1e9;
    for (int k = s; k < n; k++)
    {
        int temp_answer = 1 + Minimum_Pallindromic_Partition_Memo(s, k, str, dp) + Minimum_Pallindromic_Partition_Memo(k + 1, n, str, dp);
        min_answer = min(min_answer, temp_answer);
    }
    dp[s][n] = min_answer;
    return dp[s][n];
}

vector<vector<bool>> isPallindrome_Table(string str, int n)
{
    vector<vector<bool>> isPal(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        isPal[i][i] = 1;

    for (int size = 2; size <= n; size++)
    {
        for (int left = 0; left < n - size + 1; left++)
        {
            int right = left + size - 1;
            if (size == 2)
            {
                isPal[left][right] = str[left] == str[right];
            }
            else
            {
                isPal[left][right] = (isPal[left + 1][right - 1]) && (str[left] == str[right]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : isPal[i])
            cout << x << " ";
        cout << endl;
    }
    return isPal;
}

int Minimum_Pallindromic_Partition_Tabu(string str, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<bool>> isPal = isPallindrome_Table(str, n);
    for (int size = 2; size <= n; size++)
    {
        for (int left = 0; left < n - size + 1; left++)
        {
            int right = size + left - 1;
            dp[left][right] = 1e9;
            for (int k = left; k < right; k++)
            {
                if (isPal[left][right])
                {
                    dp[left][right] = 0;
                }
                else
                {
                    dp[left][right] = min(dp[left][right], 1 + dp[left][k] + dp[k + 1][right]);
                }
            }
        }
    }
    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << endl;
    }
    return dp[0][n - 1];
}

int Minimum_Pallindromic_Partition_Tabu_Opt(string str, int n) // Optemize
{
    vector<int> dp(n, 0); // initialized
    vector<vector<bool>> isPal = isPallindrome_Table(str, n);
    for (int i = 1; i < n; i++)
    {
        if (isPal[0][i])
        {
            dp[i] = 0;
            continue;
        }
        dp[i] = 1e9;
        for (int j = i; j >= 1; j--)
        {
            if (isPal[j][i])
                dp[i] = min(dp[j - 1], dp[i]);
        }
        dp[i]++;
    }
    cout << "\n";
    for (auto x : dp)
    {
        cout << x << " ";
    }
    cout << "\n";
    return dp[n - 1];
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int s = 0;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << Minimum_Pallindromic_Partition_Recur(s, n - 1, str) << "\n";
    // cout << Minimum_Pallindromic_Partition_Memo(s, n - 1, str, dp) << "\n";
    // cout << Minimum_Pallindromic_Partition_Tabu(str, n) << "\n";
    cout << Minimum_Pallindromic_Partition_Tabu_Opt(str, n) << "\n";
    return 0;
}