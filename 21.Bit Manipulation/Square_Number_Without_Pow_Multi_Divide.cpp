#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Square_Number_Brute(int n)
{
    if (n < 0)
        n = -n;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += n;
    return res;
}
int Square_Number_Optimal(int n)
{
    if (n < 0)
        n = -n;
    int res = 0;
    int count = 0;
    int temp = n;
    while (temp > 0)
    {
        if ((temp & 1) == 1)
        {
            res += (n << count);
        }
        count++;
        temp = (temp >> 1);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << Square_Number_Brute(n) << "\n";
    cout << Square_Number_Optimal(n) << "\n";
    return 0;
}