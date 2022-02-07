#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long Digit_Sum_One_To_N(string num, int indx, long long sum)
{
    if (indx >= num.length())
        return sum;
    int limit = num[indx] - '0';
    long long res = 0;
    for (int i = 0; i <= limit; i++)
    {
        res += Digit_Sum_One_To_N(num, indx + 1, sum + i);
    }
    return res;
}

int main()
{
    string num;
    cin >> num;
    cout << Digit_Sum_One_To_N(num, 0, 0) << "\n";
    return 0;
}