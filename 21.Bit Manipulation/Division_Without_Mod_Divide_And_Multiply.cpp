#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Division_Without_Multi_Mod_Divide_Brute(int p, int q)
{
    int sign = 1;
    if (p < 0)
    {
        sign *= -1;
        p = -p;
    }
    if (q < 0)
    {
        sign *= -1;
        q = -q;
    }
    int quot = 0;
    while (p >= q)
    {
        p -= q;
        quot++;
    }

    if (sign > 0)
        return quot;
    else
        return -quot;
}

int Division_Without_Multi_Mod_Divide_Optimal(long long p, long long q)
{
    int sign = 1;
    if (p < 0)
    {
        sign *= -1;
        p = -p;
    }
    if (q < 0)
    {
        sign *= -1;
        q = -q;
    }
    long long temp = 0, quotient = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (temp + (q << i) <= p)
        {
            temp += (q << i);
            quotient = (quotient | (1ll << i));
        }
    }
    if (sign > 0)
        return quotient;
    else
        return -quotient;
}

int main()
{
    int p, q;
    cin >> p >> q;
    cout << Division_Without_Multi_Mod_Divide_Brute(p, q) << "\n";
    cout << Division_Without_Multi_Mod_Divide_Optimal(p, q) << "\n";
    return 0;
}