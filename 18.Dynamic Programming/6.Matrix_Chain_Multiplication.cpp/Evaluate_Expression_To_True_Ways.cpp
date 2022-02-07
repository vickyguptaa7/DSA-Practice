#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Ways_Expression_To_True_Recur(string str, int s, int n, bool isTrue)
{
    if (s > n)
        return 0;
    if (s == n)
    {
        if (isTrue == true)
        {
            return str[s] == 'T';
        }
        else
        {
            return str[s] == 'F';
        }
    }
    int ways = 0;
    for (int k = s + 1; k < n; k += 2)
    {
        int lt = Ways_Expression_To_True_Recur(str, s, k - 1, true);
        int lf = Ways_Expression_To_True_Recur(str, s, k - 1, false);
        int rt = Ways_Expression_To_True_Recur(str, k + 1, n, true);
        int rf = Ways_Expression_To_True_Recur(str, k + 1, n, false);
        if (str[k] == '|')
        {
            if (isTrue == true)
                ways += lt * rt + lt * rf + lf * rt;
            else
                ways += rf * lf;
        }
        else if (str[k] == '^')
        {
            if (isTrue == true)
                ways += lt * rf + lf * rt;
            else
                ways += lt * rt + rf * lf;
        }
        else
        {
            if (isTrue == true)
                ways += lt * rt;
            else
                ways += lt * rf + lf * rt + lf * rf;
        }
    }
    return ways;
}

int Ways_Expression_To_True_Memo(string str, int s, int n, bool isTrue, vector<vector<vector<int>>> &dp)
{
    if (s > n)
        return 0;
    if (s == n)
    {
        if (isTrue == true)
        {
            return str[s] == 'T';
        }
        else
        {
            return str[s] == 'F';
        }
    }
    if (dp[s][n][isTrue] != -1)
        return dp[s][n][isTrue];
    int ways = 0;
    for (int k = s + 1; k < n; k += 2)
    {
        int lt = Ways_Expression_To_True_Memo(str, s, k - 1, true, dp);
        int lf = Ways_Expression_To_True_Memo(str, s, k - 1, false, dp);
        int rt = Ways_Expression_To_True_Memo(str, k + 1, n, true, dp);
        int rf = Ways_Expression_To_True_Memo(str, k + 1, n, false, dp);
        if (str[k] == '|')
        {
            if (isTrue == true)
                ways += lt * rt + lt * rf + lf * rt;
            else
                ways += rf * lf;
        }
        else if (str[k] == '^')
        {
            if (isTrue == true)
                ways += lt * rf + lf * rt;
            else
                ways += lt * rt + rf * lf;
        }
        else
        {
            if (isTrue == true)
                ways += lt * rt;
            else
                ways += lt * rf + lf * rt + lf * rf;
        }
    }
    dp[s][n][isTrue] = ways;
    return ways;
}

// int Ways_Expression_To_True_Tabu(string str, int n)
// {
//     string symb, oper;
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         if (i % 2 == 0)
//             symb += str[i];
//         else
//             oper += str[i];
//     }
//     int p = symb.length(), q = oper.length();
//     vector<vector<vector<int>>> dp(p, vector<vector<int>>(p, (vector<int>(2, 0))));
//     for (int i = 0; i < p; i++)
//     {
//         if (symb[i] == 'T')
//             dp[i][i][1] = 1;
//         else
//             dp[i][i][0] = 1;
//     }

//     for (int size = 2; size <= p; size++)
//     {
//         for (int left = 0; left < p; left++)
//         {
//             int right = left + size - 1;
//             for (int k = left + 1; k < right; k += 2)
//             {
//                 if()
//             }
//         }
//     }
// }

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, (vector<int>(2, -1))));
    // cout << Ways_Expression_To_True_Recur(str, 0, n - 1, true) << "\n";
    cout << Ways_Expression_To_True_Memo(str, 0, n - 1, true, dp) << "\n";
    cout << countWays(n, str) << "\n";
    return 0;
}