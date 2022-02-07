#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int Word_Break(int s, int n, string str, unordered_set<string> dict)
{
    if (s == n)
        return 1;
    string word;
    for (int i = s; i < n; i++)
    {
        word += str[i];
        if (dict.find(word) != dict.end())
        {
            if (Word_Break(i + 1, n, str, dict))
                return 1;
        }
    }
    return 0;
}

bool Word_Break_Memoize(int s, int n, string &str, unordered_set<string> &dict, vector<int> &dp)
{
    if (s == n)
        return 1;
    if (dp[s] != -1)
        return dp[s];
    string word;
    for (int i = s; i < n; i++)
    {
        word += str[i];
        if (dict.find(word) != dict.end())
        {
            if (Word_Break_Memoize(i + 1, n, str, dict, dp))
            {
                dp[s] = 1;
                return dp[s];
            }
        }
    }
    dp[s] = 0;
    return dp[s];
}

bool Word_Break_Tabu(int s, int n, string &str, unordered_set<string> &dict)
{
    vector<int> dp(n + 1, 0);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        string word;
        for (int j = i - 1; j >= 0; j--)
        {
            word = str[j] + word;
            int prev = i - word.length();
            if (dp[prev] && dict.find(word) != dict.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main()
{
    string str;
    cin >> str;
    unordered_set<string> dict;
    int d;
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        string x;
        cin >> x;
        dict.insert(x);
    }
    vector<int> dp(str.length(), -1);
    // cout << Word_Break(0, str.length(), str, dict) << "\n";
    // cout << Word_Break_Memoize(0, str.length(), str, dict, dp) << "\n\n";
    cout << Word_Break_Tabu(0, str.length(), str, dict) << "\n";
    return 0;
}
/*

ilikesamsung
12
i like  sam  sung samsung mobile ice
cream icecream man go mango
*/