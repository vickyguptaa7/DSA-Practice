#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool Check(int num, int x)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    if (sum == x)
        return true;
    else
        return false;
}

int Digit_Sum_Brute(int l, int r, int sum, int x) // Digit Sum In Range L->R
{
    int res = 0;
    for (int i = l; i <= r; i++)
    {
        if (Check(i, x))
            res++;
    }
    return res;
}

int main()
{
    int l, r, x;
    cin >> l >> r >> x;
    cout << Digit_Sum_Brute(l, r, l, x) << "\n";
    return 0;
}