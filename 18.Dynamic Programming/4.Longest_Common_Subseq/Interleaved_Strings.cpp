#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool Recur_Helper(int l1, string a, int l2, string b, int l3, string c, vector<vector<int>> &dp)
{
    if (l1 == a.length())
    {
        return (b.substr(l2, b.length() - l2) == c.substr(l3, c.length() - l3));
    }

    if (l2 == b.length())
    {
        return (a.substr(l1, a.length() - l1) == c.substr(l3, c.length() - l3));
    }

    if (dp[l1][l2] != -1)
        return dp[l1][l2];

    bool first = false, second = false;

    if (a[l1] == c[l3])
    {
        first = Recur_Helper(l1 + 1, a, l2, b, l3 + 1, c, dp);
    }

    if (b[l2] == c[l3])
    {
        second = Recur_Helper(l1, a, l2 + 1, b, l3 + 1, c, dp);
    }

    return dp[l1][l2] = (first | second);
}

bool Interleaved_String_Recur(string a, string b, string c)
{
    int l1 = a.length(), l2 = b.length(), l3 = c.length();
    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    if (l1 + l2 != l3)
        return false;
    else
        return Recur_Helper(0, a, 0, b, 0, c, dp);
}

bool Interleaved_String_Tabulation(string a, string b, string c)
{
    int l1 = a.length(), l2 = b.length(), l3 = c.length();
    if (l1 + l2 != l3)
        return false;
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, 0));
    dp[0][0] = true;
    for (int i = 1; i <= l2; i++)
    {
        if (b[i - 1] == c[i - 1])
            dp[0][i] = dp[0][i - 1];
        else
            dp[0][i] = false;
    }
    for (int i = 1; i <= l1; i++)
    {
        if (a[i - 1] == c[i - 1])
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = false;
    }

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            bool first = false, second = false;
            if (a[i - 1] == c[i + j - 1])
            {
                first = dp[i - 1][j];
            }
            if (b[j - 1] == c[i + j - 1])
            {
                second = dp[i][j - 1];
            }
            dp[i][j] = (first | second);
        }
    }
    for (int i = 0; i <= l1; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    return dp[l1][l2];
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    // cout << Interleaved_String_Recur(a, b, c) << "\n";
    cout << Interleaved_String_Tabulation(a, b, c) << "\n";
    return 0;
}
/*
XXYXX XXX XXXXYXXX
*/