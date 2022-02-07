#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long Digits_Sum_With_N_Digits(int digits, long long sum)
{
    if (digits <= 0)
        return sum;
    long long res = 0;
    for (int i = 0; i <= 9; i++)
    {
        res += Digits_Sum_With_N_Digits(digits - 1, sum + i);
    }
    return res;
}

int main()
{
    int digits;
    cin >> digits;
    cout << Digits_Sum_With_N_Digits(digits, 0) << "\n";
    vector<vector<int>> dp(10, vector<int>(1, -1));
    return 0;
}