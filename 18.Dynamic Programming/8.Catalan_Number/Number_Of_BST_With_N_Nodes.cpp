#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Number_Of_BST_With_N_Nodes_Recursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += Number_Of_BST_With_N_Nodes_Recursive(i) * Number_Of_BST_With_N_Nodes_Recursive(n - i - 1);
    }
    return result;
}

int Number_Of_BST_With_N_Nodes_Memo(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += Number_Of_BST_With_N_Nodes_Memo(i, dp) * Number_Of_BST_With_N_Nodes_Memo(n - i - 1, dp);
    }
    dp[n] = result;
    return result;
}

int Number_Of_BST_With_N_Nodes_Tabu(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int result = 0;
        for (int k = 0; k < i; k++)
        {
            result += dp[k] * dp[i - 1 - k];
        }
        dp[i] = result;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << Number_Of_BST_With_N_Nodes_Recursive(n) << "\n";
    cout << Number_Of_BST_With_N_Nodes_Memo(n, dp) << "\n";
    cout << Number_Of_BST_With_N_Nodes_Tabu(n) << "\n";

    return 0;
}