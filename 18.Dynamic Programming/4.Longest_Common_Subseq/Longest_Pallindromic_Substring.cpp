#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isPallindrome_Brute(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - 1 - i])
            return false;
    }
    return true;
}

string Longest_Pallindromic_Substring_Brute(string str, int n)
{
    string ans;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        string temp;
        for (int j = i; j < n; j++)
        {
            temp += str[j];
            if (isPallindrome_Brute(temp) && len < temp.length())
            {
                len = temp.length();
                ans = temp;
            }
        }
    }
    return ans;
}

string Pallindrome_Optmal(string str, int left, int right, int n, string &ans)
{
    while (left >= 0 && right < n)
    {
        if (str[left] != str[right])
            return ans;
        ans = str[left] + ans + str[right];
        left--;
        right++;
    }
    return ans;
}

string Longest_Pallindromic_Substring_Optemize(string str, int n)
{
    string ans;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && str[i] == str[i - 1]) // Check For Even Length Pallindrome
        {
            string temp;
            temp = str.substr(i - 1, 2);
            Pallindrome_Optmal(str, i - 2, i + 1, n, temp);
            if (temp.length() > ans.length())
                ans = temp;
        }
        string temp;
        temp += str[i];
        Pallindrome_Optmal(str, i - 1, i + 1, n, temp);
        if (temp.length() > ans.length())
            ans = temp;
    }
    return ans;
}

int Longest_Pallindromic_Substring_Recur(string str, int strt, int end)
{
    if (strt > end)
        return 0;
    if (strt == end)
        return 1;
    if (str[strt] == str[end])
    {
        int left_string = end - strt - 1;
        if (left_string == Longest_Pallindromic_Substring_Recur(str, strt + 1, end - 1))
            return 2 + left_string;
    }
    return max(Longest_Pallindromic_Substring_Recur(str, strt, end - 1),
               Longest_Pallindromic_Substring_Recur(str, strt + 1, end));
}

int Longest_Pallindromic_Substring_Memo(string str, int strt, int end, vector<vector<int>> &dp)
{
    if (strt > end)
        return 0;
    if (strt == end)
        return 1;
    if (dp[strt][end] != -1)
        return dp[strt][end];
    if (str[strt] == str[end])
    {
        int left_String = end - strt - 1;
        if (left_String == Longest_Pallindromic_Substring_Memo(str, strt + 1, end - 1, dp))
        {
            dp[strt][end] = 2 + left_String;
            return dp[strt][end];
        }
    }
    dp[strt][end] = max(Longest_Pallindromic_Substring_Memo(str, strt + 1, end, dp), Longest_Pallindromic_Substring_Memo(str, strt, end - 1, dp));
    return dp[strt][end];
}

int Longest_Pallindromic_Substring_Tabu(string str, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    int result = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] == str[j])
            {
                if (j - i == 1)
                    dp[i][j] = 2;
                else
                {
                    dp[i][j] = (dp[i + 1][j - 1] > 0) ? dp[i + 1][j - 1] + 2 : 0;
                    result = max(result, dp[i][j]);
                }
            }
        }
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << Longest_Pallindromic_Substring_Brute(str, n) << "\n";
    cout << Longest_Pallindromic_Substring_Optemize(str, n) << "\n";
    cout << Longest_Pallindromic_Substring_Recur(str, 0, n - 1) << "\n";
    cout << Longest_Pallindromic_Substring_Memo(str, 0, n - 1, dp) << "\n";
    cout << Longest_Pallindromic_Substring_Tabu(str, n) << "\n";
    return 0;
}