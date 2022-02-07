#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> dp(100000000, -1);
long long Fibo_Recur(long long n)
{
    if (n == 0 || n == 1)
        return n;
    return Fibo_Recur(n - 1) + Fibo_Recur(n - 2);
}

long long Fibo_Memo(long long n)
{
    if (dp[n] == -1)
    {
        int res;
        if (n == 0 || n == 1)
            res = n;
        else
            res = Fibo_Memo(n - 1) + Fibo_Memo(n - 2);
        dp[n] = res;
    }
    return dp[n];
}

long long Fibo_Tabu(long long n)
{
    if (n == 0 || n == 1)
        return n;
    int fibo, a = 1, b = 1;
    for (long long i = 2; i <= n; i++)
    {
        fibo = a + b;
        a = b;
        b = fibo;
    }
    return a;
}

int main()
{
    long long n;
    cin >> n;
    // cout << Fibo_Recur(n);
    // cout << "\n";
    cout << Fibo_Memo(n);
    cout << "\n";
    // cout << Fibo_Tabu(n);
    // cout << "\n";
    return 0;
}