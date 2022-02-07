#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> isPal(string s)
{
    int n = s.length();
    vector<vector<int>> isPall(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        isPall[i][i] = 1;
    for (int size = 2; size <= n; size++)
    {
        for (int left = 0; left < n - size + 1; left++)
        {
            int right = left + size - 1;
            if (s[left] == s[right])
            {
                isPall[left][right] = isPall[left + 1][right - 1];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : isPall[i])
            cout << x << " ";
        cout << "\n";
    }
    return isPall;
}
string longestPalindrome(string s)
{
    vector<vector<int>> isPallindrome = isPal(s);
    return s;
}

int main()
{
    longestPalindrome("paba");
    return 0;
}